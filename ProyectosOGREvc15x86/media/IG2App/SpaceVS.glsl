#version 330 core
in vec4 vertex;
in vec2 uv0;
in vec2 uv1;
uniform mat4 modelViewProjMat;
out vec2 vUv0;
out vec2 vUv1;

void main() {
  vUv0 = uv0;
  vUv1 = uv1;
  gl_Position = modelViewProjMat * vertex;
}
