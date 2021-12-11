#version 330 core
uniform sampler2D texturaL; // tipo sampler2D para texturas 2D
uniform sampler2D texturaM; // ‐> unidades de textura (int)
uniform float ZF; // blending factor
in vec2 vUv0; // out del vertex shader
in vec2 vUv1;
out vec4 fFragColor; // out del fragment shader

void main() {

  

  fFragColor = vec4(color, 1.0); // out
}
