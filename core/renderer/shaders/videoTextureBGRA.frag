#version 310 es
precision highp float;
precision highp int;

layout(location = 0) in vec4 v_fragmentColor;
layout(location = 1) in vec2 v_texCoord;

layout(binding = 0) uniform sampler2D u_tex0;

layout(location = 0) out vec4 FragColor;

void main()
{
    FragColor = v_fragmentColor * texture(u_tex0, v_texCoord).bgra;
}
