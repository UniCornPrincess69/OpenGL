#version 330 core

out vec4 FragColor;

in vec3 fragPos;
in vec2 texCoord;
in vec3 vertexColor;
in vec3 lightNormal;
in vec3 lightOutputPos;

uniform sampler2D PyramidTexture;
uniform vec3 lightVec;
uniform vec3 objectVec;

void main()
{
	vec4 baseColor = texture(PyramidTexture, texCoord) * vec4(vertexColor, 1.0);

	float randomValue = fract(sin(dot(texCoord.xy, vec2(10, 90))) * 20000);

	float glitterStrength = 1;
	float glitterSize = 0.005;

	vec3 glitter = lightVec * step(randomValue, glitterStrength) * glitterSize;

	vec3 norm = normalize(lightNormal);
	vec3 lightDir = normalize(lightOutputPos - fragPos);
	float diffStrength = max(dot(norm, lightDir), 0.0);
	vec3 diffVec = diffStrength * lightVec;
	vec3 reflectDir = reflect(-lightDir, norm);

	vec3 finalColor = baseColor.rgb + (glitter * reflectDir);

	FragColor = vec4(finalColor, baseColor.a);

}