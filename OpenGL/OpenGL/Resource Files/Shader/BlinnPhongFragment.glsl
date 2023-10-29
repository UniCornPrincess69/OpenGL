#version 330 core

out vec4 fragColor;

in vec3 vertexColor;
in vec3 fragPos;
in vec3 normal;
in vec3 lightOutputPos;

uniform vec3 lightVec;
uniform vec3 objectVec;

void main()
{
	float ambientStrength = 0.1;
	vec3 ambient = ambientStrength * lightVec;

	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(lightOutputPos - fragPos);
	float diffStrength = max(dot(norm, lightDir), 0.0);
	vec3 diffVec = diffStrength * lightVec;

	float specularStrength = 0.5;
	vec3 viewDir = normalize(-fragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float specularInten = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular = specularStrength * specularInten * lightVec;

	vec3 resultVec = (ambient * diffVec * specular) * objectVec;
	fragColor = vec4(resultVec, 1.0);
}