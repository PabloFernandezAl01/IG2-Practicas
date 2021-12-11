#version 330 core

in vec2 vUv0;
in vec3 Normal;

uniform sampler2D textureT;
uniform sampler2D textureL;
uniform sampler2D textureM;
uniform vec4 lightPos;      // direccion de la luz
uniform vec4 intLuz;        // intensidad de luz

uniform vec3 color_front;
uniform vec3 color_back;

out vec4 fFragColor;        // out del fragment shader

void main() {
	  vec3 color = vec3(texture(textureT, vUv0));

    if(color.x > 0.6) discard;

    if(gl_FrontFacing) {
        vec3 colorL = texture(textureL, vUv0).rgb;
        colorL = colorL * color_front;

        vec3 norm = normalize(Normal);
        vec3 lightDir = normalize(vec3(lightPos));
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = vec3(intLuz) * diff;
        fFragColor = vec4(colorL * diffuse, 1.0);
    }
    else {
        vec3 colorM = texture(textureM, vUv0).rgb;
        colorM = colorM * color_back;

        vec3 norm = -normalize(Normal);
        vec3 lightDir = normalize(vec3(lightPos));
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = vec3(intLuz) * diff;
        fFragColor = vec4(colorM * diffuse, 1.0);
    }
}
