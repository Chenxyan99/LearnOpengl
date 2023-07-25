#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec4 ourColor;

uniform vec2 xyoffset;

xoffset = sin(time)
yoffset = cos(time)

void main()
{
    gl_Position = vec4(aPos.x + xoffset, aPos.y + yoffset, aPos.z, 1.0);
    ourColor = gl_Position;
}