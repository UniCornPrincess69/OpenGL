#version 330 core

out vec4 FragColor;

in vec3 fragPos;
in vec2 texCoord;
in vec3 vertexColor;
in vec3 lightNormal;
in vec3 lightBiNormal;
in vec3 lightTangent;
in vec3 lightOutputPos;

uniform sampler2D PyramidTexture;
uniform sampler2D NormalMap;
uniform vec3 lightVec;
uniform vec3 objectVec;
uniform float time;

//Shader inspired by tutorial see: https://www.youtube.com/watch?v=wkWYXjrOVlA&list=PL4neAtv21WOmIrTrkNO3xCyrxg4LKkrF7&index=19
//Usage of Tangent, BiNormal and Normals via different online sources
void main()
{
    vec2 coord = texCoord;
    vec3 color = vec3(0.0);

    float angle = atan(-coord.y + 0.25, coord.x - 0.5) * 0.1;
    float len = length(coord - vec2(0.5, 0.25));

    color.r += sin(len * 40.0 + angle * 40.0 + time);
    color.g += cos(len * 30.0 + angle * 60.0 - time);
    color.b += sin(len * 50.0 + angle * 50.0 + 3.0);

    vec3 normalMapTex = texture(NormalMap, texCoord).rgb * 0.5;
    vec3 normalMapNormal = normalize(normalMapTex * 2.0 - 1.0);

    vec4 textureColor = texture(PyramidTexture, texCoord) * 0.5;

    mat3 TBN = mat3(lightTangent, lightBiNormal, lightNormal);
    vec3 normal = normalize(TBN * normalMapNormal);

    vec3 lightDir = normalize(lightOutputPos - fragPos);
    float diff = max(dot(normal, lightVec), 0.0);
    vec4 diffuse = diff * textureColor * vec4(objectVec, 1.0);

    FragColor = vec4(color, 1.0) * diffuse;
}