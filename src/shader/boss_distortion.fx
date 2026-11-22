/*{
    "blocks": [
        "FSBlock": {
            "binding": 1,
            "members": [
                {"name": "SCREENSIZE", "type": "vec4"},
                {"name": "centerX", "type": "float"},
                {"name": "centerY", "type": "float"},
                {"name": "size", "type": "float"},
                {"name": "arg", "type": "float"},
                {"name": "color", "type": "vec4"},
                {"name": "colorsize", "type": "float"},
                {"name": "timer", "type": "float"}
            ]
        }
    ],
    "samplers": [
        {"name": "u_texture", "type": "sampler2D", "binding": 2}
    ]
}*/
#if __VERSION__ >= 300

layout(std140, binding=1) uniform FSBlock
{
    vec4 SCREENSIZE;
    float centerX;
    float centerY;
    float size;
    float arg;
    vec4 color;
    float colorsize;
    float timer;
};
layout(binding=2) uniform sampler2D u_texture;

layout(location=0) in vec4 v_fragmentColor;
layout(location=1) in vec2 v_texCoord;
layout(location=0) out vec4 cc_FragColor;

#else

varying vec4 v_fragmentColor;
varying vec2 v_texCoord;
uniform vec4 SCREENSIZE;
uniform float centerX;
uniform float centerY;
uniform float size;
uniform float arg;
uniform vec4 color;
uniform float colorsize;
uniform float timer;
uniform sampler2D u_texture;

#endif


vec2 Distortion(vec2 xy, vec2 delta, float deltaLen)
{
    float k = deltaLen / size;
    float p = (k - 1.0) * (k - 1.0);
    vec2 delta1 = vec2(arg * 0.8 * sin((xy.x * 0.5 + xy.y) / 18.0 + timer / 5.0), 0.0);
    float a = mix(arg * 1.2, arg * 0.8, sin(timer / 10.0) * 0.5 + 1.0);
	float d2 = deltaLen * (1.0 - mix(pow(k, (1.0 + a)), k, k));
    vec2 delta2 = vec2(d2, d2);
    return delta1 * p + delta2 * p * 0.8;
}

void main()
{
    vec2 uv = v_texCoord;
    vec2 screen_size = vec2(SCREENSIZE.z - SCREENSIZE.x, SCREENSIZE.w - SCREENSIZE.y);
    vec2 center = vec2(centerX, screen_size.y - centerY);
    vec2 xy = uv * screen_size;
    vec2 delta = xy - center;
    float deltaLen = length(delta);
    delta = normalize(delta);

    if (deltaLen <= size) {
        vec2 distDelta = Distortion(xy, delta, deltaLen);
        uv += distDelta / screen_size;
    }

#if __VERSION__ >= 300
	vec4 fragColor = v_fragmentColor * texture(u_texture, uv);
#else
	vec4 fragColor = v_fragmentColor * texture2D(u_texture, uv);
#endif
    
    if (deltaLen <= colorsize) {
        float k = deltaLen / colorsize;
        vec4 addColor = mix(color, vec4(0.0), k * k);
        fragColor += addColor * addColor.a;
    }
//    fragColor.a = 1;

#if __VERSION__ >= 300
    cc_FragColor = fragColor;
#else
    gl_FragColor = fragColor;
#endif
}
