/*{
    "attributes": [
        {"name": "a_position", "type": "vec4"}
        {"name": "a_color", "type": "vec4"}
        {"name": "a_texCoord", "type": "vec2"}
    ],
    "blocks": [
        "VSBlock": {
            "binding": 0,
            "members": [
                {"name": "u_MVPMatrix", "type": "mat4"}
            ]
        }
    ]
}*/
#if __VERSION__ >= 300

layout(location=0) in vec4 a_position;
layout(location=1) in vec4 a_color;
layout(location=2) in vec2 a_texCoord;

layout(std140, binding=0) uniform VSBlock
{
    mat4 u_MVPMatrix;
};

#ifdef GL_ES
layout(location=0) out lowp vec4 v_fragmentColor;
layout(location=1) out mediump vec2 v_texCoord;
#else
layout(location=0) out vec4 v_fragmentColor;
layout(location=1) out vec2 v_texCoord;
#endif

#else

attribute vec4 a_position;
attribute vec2 a_texCoord;
attribute vec4 a_color;

uniform mat4 u_MVPMatrix;

#ifdef GL_ES
varying lowp vec4 v_fragmentColor;
varying mediump vec2 v_texCoord;
#else
varying vec4 v_fragmentColor;
varying vec2 v_texCoord;
#endif

#endif

void main()
{
    gl_Position = u_MVPMatrix * a_position;
    v_fragmentColor = a_color;
    v_texCoord = a_texCoord;
}
