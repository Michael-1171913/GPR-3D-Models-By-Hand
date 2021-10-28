#version 330

uniform mat4 matVP;
uniform mat4 matGeo;

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 col;

out vec4 color;

void main() {
   color = vec4(1.0);
   gl_Position = matVP * matGeo * vec4(pos, 1);
}