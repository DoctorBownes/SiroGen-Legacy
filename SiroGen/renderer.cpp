#include <SiroGen/renderer.h>
#include <glm/gtx/matrix_decompose.hpp>

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
"uniform vec4 blendColor;\n"
"void main()\n"
"{\n"
"	FragColor = texture2D(myTextureSampler, UV) * blendColor;\n"
//"	if (FragColor.a < 0.5)discard;\n"
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
    _camera = nullptr;
    _shader = 0;
    window = nullptr;
    glewExperimental = true;
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return;
    }
    

    //glfwWindowHint(GLFW_SAMPLES, 8); // 4x antialiasing
    glEnable(GL_MULTISAMPLE);
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

Renderer::~Renderer()
{
    delete window;
    delete _camera;
}

void Renderer::RenderScene(Scene* scene)
{
    _camera = scene->GetMainCamera();
    
   // glClearColor(Palette[scene->bkgdcolor].r /255.0f, Palette[scene->bkgdcolor].g / 255.0f, Palette[scene->bkgdcolor].b / 255.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    RenderEntity(glm::mat4(1), scene);

    for (int i = 0; i < scene->GetTexts().size(); i++)
    {
        RenderText(scene->GetTexts()[i]);
    }
    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Renderer::RenderText(Text* text)
{
    glm::mat4 MVP = glm::mat4(1);
    GLuint MatrixID = glGetUniformLocation(_shader, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    text->DoIt(_shader);
}

void Renderer::RenderEntity(glm::mat4 mat, Entity* entity)
{
    glm::mat4 TranslationMatrix = glm::translate(glm::mat4(1), glm::vec3(entity->transform->position->x, entity->transform->position->y, entity->transform->position->z));
    glm::mat4 MyRotationAxis = glm::eulerAngleXYZ(entity->transform->rotation->x * 0.01745329f, entity->transform->rotation->y * 0.01745329f, entity->transform->rotation->z * 0.01745329f);
    glm::mat4 myScalingMatrix = glm::scale(glm::mat4(1),glm::vec3(entity->transform->scale->x, entity->transform->scale->y, entity->transform->scale->z));
    
    glm::mat4 myModelVector = TranslationMatrix * MyRotationAxis * myScalingMatrix;
    mat *= myModelVector;

    glm::vec3 worldpos = glm::vec3();
    glm::quat worldrot = glm::quat();
    glm::vec3 worldscale = glm::vec3();

    glm::decompose(mat, worldscale, worldrot, worldpos, glm::vec3(), glm::vec4());

    *entity->worldtransform->position = Vector3(worldpos.x, worldpos.y, worldpos.z);
    *entity->worldtransform->rotation = Vector3(worldrot.x, worldrot.y, worldrot.z);
    *entity->worldtransform->scale = Vector3(worldscale.x, worldscale.y, worldscale.z);

    glm::mat4 CameraMatrix = _camera->GetCameraMat();
    glm::mat4 projectionMatrix = _camera->GetProjectionMat();

    glm::mat4 MVP = projectionMatrix * CameraMatrix * mat;
    GLuint MatrixID = glGetUniformLocation(_shader, "MVP");

    

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // This is done in the main loop since each model will have a different MVP matrix (At least for the M part)
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    std::map<size_t, Component*> componentlist = entity->GetComponentList();
    std::map<size_t, Component*>::iterator component;
    for (component = componentlist.begin(); component != componentlist.end(); component++)
    {
        component->second->DoIt(_shader);
    }
    std::vector<Entity*> child = entity->Getchildren();
    std::vector<Entity*>::iterator it;
    for (it = child.begin(); it != child.end(); it++)
    {
        RenderEntity(mat,*it);
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
