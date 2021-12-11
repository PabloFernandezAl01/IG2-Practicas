#version 330 core
uniform sampler2D texturaT;
uniform sampler2D texturaL;
uniform sampler2D texturaM;
in vec2 vUv0;
out vec4 fFragColor;

void main() {
  vec3 colorT = vec3(texture(texturaT, vUv0));
  vec3 colorL = vec3(texture(texturaL, vUv0));
  vec3 colorM = vec3(texture(texturaM, vUv0));

  if(colorT.x < 1) {
    fFragColor = vec4(colorM, 1.0);
  }
  else {
    fFragColor = vec4(colorL, 1.0);
  }
}
