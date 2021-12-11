#version 330 core

in vec2 vUv0;
uniform sampler2D textureT; // tipo sampler2D para texturas
uniform sampler2D tex_front; // tipo sampler2D para texturas
uniform sampler2D tex_back; // tipo sampler2D para texturas

uniform float Flipping;

out vec4 fFragColor;        // out del fragment shader

void main() {
	  vec3 color = vec3(texture(textureT, vUv0));

    if(color.x > 0.6) discard;

    if(gl_FrontFacing){
        vec3 colorL = vec3(texture(tex_front, vUv0));
        fFragColor = vec4(colorL, 1.0);
    }
    else {
        vec3 colorL = vec3(texture(tex_back, vUv0));
        fFragColor = vec4(colorL, 1.0);
    }
}
