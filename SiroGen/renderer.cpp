#include <SiroGen/renderer.h>

const char* vertex_shader = "#version 330 core\n"
"layout(location = 0) in vec3 vertexPosition;\n"
"layout(location = 1) in vec2 vertexUV;\n"
"uniform mat4 MVP;\n"
"out vec2 UV;\n"
"void main()\n"
"{\n"
"	gl_Position = MVP * vec4(vertexPosition, 1.0);\n"
"	UV = vertexUV;\n"
"}\0";
const char* fragment_shader = "#version 330 core\n"
"in vec2 UV;\n"
"out vec4 FragColor;\n"
"uniform sampler2D myTextureSampler;\n"
"void main()\n"
"{\n"
"	FragColor = texture2D(myTextureSampler, UV);\n"
"}\n\0";


extern "C"
{
    __declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
}

std::string get_file_contents(const char* filename)
{
    std::ifstream in(filename, std::ios::binary);
    if (in)
    {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return(contents);
    }
    throw(errno);
}

Renderer::Renderer()
{
    _shader = 0;
    window = nullptr;
    glewExperimental = true;
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return;
    }
    

    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 


    //if (scene->fullscreen)
    //{
    //    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    //    window = glfwCreateWindow(1280, 720, scene->GetSceneName(), monitor, NULL);
    //}
    //else
    //{
        window = glfwCreateWindow(1920, 1080, "SiroGen", NULL, NULL);
 //   }

    if (window == NULL) {
        fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
        glfwTerminate();
        return;
    }
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwMakeContextCurrent(window);

    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return;
    }
    _shader = GetShader(vertex_shader, fragment_shader);
    glUseProgram(_shader);
    GLuint test;
    glGenVertexArrays(1, &test);
    glBindVertexArray(test);
}

void Renderer::RenderScene(Scene* scene)
{
    _camera = scene->GetMainCamera();
    //glClearColor(0.0f, 0.4f, 0.7f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (int i = 0; i < scene->Getchildren().size(); i++)
    {
        RenderEntity(scene->Getchildren()[i]);
    }
    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Renderer::RenderEntity(Entity* entity)
{
    glm::mat4 TranslationMatrix = glm::translate(glm::mat4(1), glm::vec3(entity->transform->position->x, entity->transform->position->y, entity->transform->position->z));
    glm::mat4 MyRotationAxis = glm::eulerAngleXYZ(entity->transform->rotation->x * 0.01745329f, entity->transform->rotation->y * 0.01745329f, entity->transform->rotation->z * 0.01745329f);
    glm::mat4 myScalingMatrix = glm::scale(glm::mat4(1),glm::vec3(entity->transform->scale->x, entity->transform->scale->y, entity->transform->scale->z));
    
    glm::mat4 myModelVector = TranslationMatrix * MyRotationAxis * myScalingMatrix;
    glm::mat4 CameraMatrix = _camera->GetCameraMat();
    glm::mat4 projectionMatrix = _camera->GetProjectionMat();

    glm::mat4 MVP = projectionMatrix * CameraMatrix * myModelVector;
    GLuint MatrixID = glGetUniformLocation(_shader, "MVP");

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // This is done in the main loop since each model will have a different MVP matrix (At least for the M part)
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    if (entity->GetComponent<Sprite>() || entity->GetComponent<PixelSprite>())
    {
        Sprite* tempSprite;
        tempSprite = entity->GetComponent<Sprite>();
        if (tempSprite == nullptr)
        {
            tempSprite = entity->GetComponent<PixelSprite>();
        }
        if (tempSprite == nullptr)
        {
            std::cout << "Warning Component is NULL" << std::endl;
        }
        else
        {
            if (entity->GetComponent<Animation>())
            {
                Animation* tempAnim = entity->GetComponent<Animation>();
                if (tempAnim->isAnimationPlaying())
                {
                    std::cout << glfwGetTime() - tempAnim->starttime << std::endl;
                    tempSprite->frame = tempAnim->SoloAnimation.GetArray().at(tempSprite->pos).spritetexture;
                    if (glfwGetTime() - tempAnim->starttime >= tempAnim->SoloAnimation.GetArray().at(pos).timeonscreen)
                    {
                        tempSprite->pos++;
                        if (tempSprite->pos > tempAnim->SoloAnimation.GetArray().size() - 1)
                        {
                            tempSprite->pos = 0;
                            if (!tempAnim->isLooping)
                            {
                                tempAnim->StopAnimation();
                            }
                        }
                        tempAnim->starttime = glfwGetTime();
                    }
                }
                else
                {
                    tempSprite->frame = tempSprite->spritetexture;
                }
            }
            glBindTexture(GL_TEXTURE_2D, tempSprite->frame);
            //glBindTexture(GL_TEXTURE_2D, tempSprite->Frame);
            // 1st attribute buffer : vertices
            GLuint vertexPositionID = glGetAttribLocation(_shader, "vertexPosition");
            glEnableVertexAttribArray(vertexPositionID);
            glBindBuffer(GL_ARRAY_BUFFER, tempSprite->sprite);
            glVertexAttribPointer(
                vertexPositionID,   // attribute 0. No particular reason for 0, but must match the layout in the shader.
                3,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                0,                  // stride
                (void*)0            // array buffer offset
            );
            // Draw the triangle !
            GLuint vertexUVID = glGetAttribLocation(_shader, "vertexUV");
            glEnableVertexAttribArray(vertexUVID);
            glBindBuffer(GL_ARRAY_BUFFER, tempSprite->uv);
            glVertexAttribPointer(
                vertexUVID,                       // attribute. No particular reason for 1, but must match the layout in the shader.
                2,                                // size
                GL_FLOAT,                         // type
                GL_FALSE,                         // normalized?
                0,                                // stride
                (void*)0                          // array buffer offset
            );

            //glBindVertexArray(entity->GetComponent<Sprite>()->VertexArrayID);
            glDrawArrays(GL_TRIANGLES, 0, 6); // Starting from vertex 0; 3 vertices total -> 1 triangle
            glDisableVertexAttribArray(vertexPositionID);
            glDisableVertexAttribArray(vertexUVID);

        }

    }
}


GLuint Renderer::GetShader(const char* vertex_file_path, const char* fragment_file_path)
{
    //std::string vertexcode = get_file_contents(vertex_file_path);
    //std::string fragmentcode = get_file_contents(fragment_file_path);

    //const char* VertexSource = vertexcode.c_str();
    //const char* FragmentSource = fragmentcode.c_str();


    GLuint VertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(VertexShader, 1, &vertex_file_path, nullptr);
    glCompileShader(VertexShader);

    GLuint FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(FragmentShader, 1, &fragment_file_path, nullptr);
    glCompileShader(FragmentShader);

    GLuint shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, VertexShader);
    glAttachShader(shaderProgram, FragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(VertexShader);
    glDeleteShader(FragmentShader);

    return shaderProgram;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
