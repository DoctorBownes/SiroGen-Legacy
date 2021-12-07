#version 330 core
// Interpolated values from the vertex shaders
in vec2 UV;

// Values that stay constant for the whole mesh.
uniform sampler2D myTextureSampler;
out vec4 FragColor;
void main()
{
	
	FragColor = texture(myTextureSampler, UV).rgb;
}