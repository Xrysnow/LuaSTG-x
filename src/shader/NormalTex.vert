#define MAX_DIRECTIONAL_LIGHT_NUM 2
#define MAX_POINT_LIGHT_NUM 2
#define MAX_SPOT_LIGHT_NUM 2

#if (MAX_DIRECTIONAL_LIGHT_NUM > 0)
    uniform vec3 u_DirLightSourceDirection[MAX_DIRECTIONAL_LIGHT_NUM];
#endif
#if (MAX_POINT_LIGHT_NUM > 0)
    uniform vec3 u_PointLightSourcePosition[MAX_POINT_LIGHT_NUM];
#endif
#if (MAX_SPOT_LIGHT_NUM > 0)
    uniform vec3 u_SpotLightSourcePosition[MAX_SPOT_LIGHT_NUM];
    uniform vec3 u_SpotLightSourceDirection[MAX_SPOT_LIGHT_NUM];
#endif

attribute vec4 a_position;
attribute vec2 a_texCoord;
//attribute vec3 a_normal;
//attribute vec3 a_tangent;
//attribute vec3 a_binormal;
varying vec2 TextureCoordOut;

uniform mat4 u_MVPMatrix;

attribute vec4 a_color;
#ifdef GL_ES
varying lowp vec4 v_fragmentColor;
#else
varying vec4 v_fragmentColor;
#endif

#if MAX_DIRECTIONAL_LIGHT_NUM
varying vec3 v_dirLightDirection[MAX_DIRECTIONAL_LIGHT_NUM];
#endif

#if MAX_POINT_LIGHT_NUM
varying vec3 v_vertexToPointLightDirection[MAX_POINT_LIGHT_NUM];
#endif

#if MAX_SPOT_LIGHT_NUM
varying vec3 v_vertexToSpotLightDirection[MAX_SPOT_LIGHT_NUM];
varying vec3 v_spotLightDirection[MAX_SPOT_LIGHT_NUM];
#endif

void main(void)
{
    v_fragmentColor = a_color;
    vec4 ePosition = a_position;
    #if ((MAX_DIRECTIONAL_LIGHT_NUM > 0) || (MAX_POINT_LIGHT_NUM > 0) || (MAX_SPOT_LIGHT_NUM > 0))
//        vec3 eTangent = normalize(CC_NormalMatrix * a_tangent);
//        vec3 eBinormal = normalize(CC_NormalMatrix * a_binormal);
//        vec3 eNormal = normalize(CC_NormalMatrix * a_normal);
    #endif
    #if (MAX_DIRECTIONAL_LIGHT_NUM > 0)
        for (int i = 0; i < MAX_DIRECTIONAL_LIGHT_NUM; ++i)
        {
//            v_dirLightDirection[i].x = dot(eTangent, u_DirLightSourceDirection[i]);
//            v_dirLightDirection[i].y = dot(eBinormal, u_DirLightSourceDirection[i]);
//            v_dirLightDirection[i].z = dot(eNormal, u_DirLightSourceDirection[i]);
            v_dirLightDirection[i] = u_DirLightSourceDirection[i];
        }
    #endif

    #if (MAX_POINT_LIGHT_NUM > 0)
        for (int i = 0; i < MAX_POINT_LIGHT_NUM; ++i)
        {
            vec3 pointLightDir = u_PointLightSourcePosition[i].xyz - ePosition.xyz;
            v_vertexToPointLightDirection[i] = pointLightDir;
        }
    #endif

    #if (MAX_SPOT_LIGHT_NUM > 0)
        for (int i = 0; i < MAX_SPOT_LIGHT_NUM; ++i)
        {
            vec3 spotLightDir = u_SpotLightSourcePosition[i] - ePosition.xyz;
//            v_vertexToSpotLightDirection[i].x = dot(eTangent, spotLightDir);
//            v_vertexToSpotLightDirection[i].y = dot(eBinormal, spotLightDir);
//            v_vertexToSpotLightDirection[i].z = dot(eNormal, spotLightDir);
            v_vertexToSpotLightDirection[i] = spotLightDir;

//            v_spotLightDirection[i].x = dot(eTangent, u_SpotLightSourceDirection[i]);
//            v_spotLightDirection[i].y = dot(eBinormal, u_SpotLightSourceDirection[i]);
//            v_spotLightDirection[i].z = dot(eNormal, u_SpotLightSourceDirection[i]);
            v_spotLightDirection[i] = u_SpotLightSourceDirection[i];
        }
    #endif

    TextureCoordOut = a_texCoord;
//    TextureCoordOut.y = 1.0 - TextureCoordOut.y;
    gl_Position = u_MVPMatrix * a_position;
}
