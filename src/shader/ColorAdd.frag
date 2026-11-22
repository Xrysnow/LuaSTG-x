/*{
    "samplers": [
        {"name": "u_texture", "type": "sampler2D", "binding": 2}
    ]
}*/
#ifdef GL_ES
precision lowp float;
#endif

#if __VERSION__ >= 300

layout(binding=2) uniform sampler2D u_texture;
layout(location=0) in vec4 v_fragmentColor;
layout(location=1) in vec2 v_texCoord;
layout(location=0) out vec4 cc_FragColor;

#else

uniform sampler2D u_texture;
varying vec4 v_fragmentColor;
varying vec2 v_texCoord;

#endif

void main()
{
#if __VERSION__ >= 300
    vec4 tex = texture(u_texture, v_texCoord);
    cc_FragColor.rgb = v_fragmentColor.rgb + tex.rgb;
    cc_FragColor.a = tex.a * v_fragmentColor.a;
#else
    vec4 tex = texture2D(u_texture, v_texCoord);
    gl_FragColor.rgb = v_fragmentColor.rgb + tex.rgb;
    gl_FragColor.a = tex.a * v_fragmentColor.a;
#endif
}
