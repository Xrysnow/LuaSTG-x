#if __VERSION__ >= 300

layout(location=0) in vec4 a_position;
layout(location=1) in vec4 a_color;
layout(location=2) in vec2 a_texCoord;

layout(std140, binding=0) uniform VSBlock
{
    mat4 u_MVPMatrix;
    float u_fogDensity;
};

#ifdef GL_ES
layout(location=0) out lowp vec4 v_fragmentColor;
layout(location=1) out mediump vec2 v_texCoord;
layout(location=2) out mediump float v_fogFactor;
#else
layout(location=0) out vec4 v_fragmentColor;
layout(location=1) out vec2 v_texCoord;
layout(location=2) out float v_fogFactor;
#endif

#else

attribute vec4 a_position;
attribute vec4 a_color;
attribute vec2 a_texCoord;

uniform mat4 u_MVPMatrix;
uniform float u_fogDensity;

#ifdef GL_ES
varying lowp vec4 v_fragmentColor;
varying mediump vec2 v_texCoord;
varying lowp float v_fogFactor;
#else
varying vec4 v_fragmentColor;
varying vec2 v_texCoord;
varying float v_fogFactor;
#endif

#endif


void main()
{
    gl_Position = u_MVPMatrix * a_position;
    v_fragmentColor = a_color;
    v_texCoord = a_texCoord;
	
    // get fog distance
	float fogFragCoord = abs(gl_Position.z);
    // exp2 fog
	v_fogFactor = exp(-pow(u_fogDensity * fogFragCoord, 2.0));
    // clamp
	v_fogFactor = clamp(v_fogFactor, 0.0, 1.0);
}
