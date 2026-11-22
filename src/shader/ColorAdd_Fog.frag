/*{
    "blocks": [
        "FSBlock": {
            "binding": 1,
            "members": [
                {"name": "u_fogColor", "type": "vec4"}
            ]
        }
    ],
    "samplers": [
        {"name": "u_texture", "type": "sampler2D", "binding": 2}
    ]
}*/
#ifdef GL_ES
precision lowp float;
#endif

#if __VERSION__ >= 300

layout(std140, binding=1) uniform FSBlock
{
    vec4 u_fogColor;
};
layout(binding=2) uniform sampler2D u_texture;

layout(location=0) in vec4 v_fragmentColor;
layout(location=1) in vec2 v_texCoord;
layout(location=2) in float v_fogFactor;
layout(location=0) out vec4 cc_FragColor;

#else

varying vec4 v_fragmentColor;
varying vec2 v_texCoord;
varying float v_fogFactor;

uniform vec4 u_fogColor;
uniform sampler2D u_texture;

#endif

void main()
{
#if __VERSION__ >= 300
    cc_FragColor = v_fragmentColor + texture(u_texture, v_texCoord);
	cc_FragColor.w = cc_FragColor.w - v_fragmentColor.w;
	cc_FragColor.rgb = mix(u_fogColor.rgb, cc_FragColor.rgb, v_fogFactor);
#else
    gl_FragColor = v_fragmentColor + texture2D(u_texture, v_texCoord);
	gl_FragColor.w = gl_FragColor.w - v_fragmentColor.w;
	gl_FragColor.rgb = mix(u_fogColor.rgb, gl_FragColor.rgb, v_fogFactor);
#endif
}
