#version 130
in vec4 P;
in vec3 N;

float specularThreshold = 0.5;
float diffuseThreshold = 0.0;

vec4 phongIllumination(vec4 P, vec3 N)
{
	// Ambient calculation
	vec4 ambient = gl_FrontMaterial.ambient * gl_LightModel.ambient;
	
	// Emission calculation
	vec4 emission = gl_FrontMaterial.emission;
	
	vec3 L = normalize(gl_LightSource[0].position.xyz - vec3(P * gl_LightSource[0].position.w));
	float diffuseIntensity = max(dot(N, L),0);
	vec4 diffuse = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse * diffuseIntensity;
	
	// Specular calculation
	vec3 R = normalize(reflect(L,N));
	vec3 V = normalize(P.xyz);
	float specularIntensity = pow(max(dot(R, V),0),0.3*gl_FrontMaterial.shininess);
	vec4 specular = gl_FrontMaterial.specular * gl_LightSource[0].specular * specularIntensity;
	
	return clamp(ambient+emission+diffuse+specular, 0, 1);
}

vec4 toonIllumination(vec4 P, vec3 N)
{
	vec3 V = normalize(P.xyz);

	if(dot(V, N) > 0.001)
	{
		return vec4(1,0,0.8,1);
	}
	
	// Ambient calculation
	vec4 ambient = gl_FrontMaterial.ambient * gl_LightModel.ambient;
	
	// Emission calculation
	vec4 emission = gl_FrontMaterial.emission;
	
	vec3 L = normalize(gl_LightSource[0].position.xyz - vec3(P * gl_LightSource[0].position.w));
	float diffuseIntensity = max(dot(N, L),0);

	if(diffuseIntensity > diffuseThreshold)
	{
		diffuseIntensity = 1;
	}
	else
	{
		diffuseIntensity = 0;
	}

	vec4 diffuse = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse * diffuseIntensity;
	
	// Specular calculation
	vec3 R = normalize(reflect(L,N));
	
	float specularIntensity = pow(max(dot(R, V),0),0.7*gl_FrontMaterial.shininess);

	if(specularIntensity > specularThreshold)
	{
		specularIntensity = 1;
	}
	else
	{
		specularIntensity = 0;
	}

	vec4 specular = gl_FrontMaterial.specular * gl_LightSource[0].specular * specularIntensity;
	
	return clamp(ambient+emission+diffuse+specular, 0, 1);
}

vec4 orenNayarlllum(vec4 P, vec3 N)
{
	vec3 L = normalize(gl_LightSource[0].position.xyz - vec3(P * gl_LightSource[0].position.w));
	vec3 R = normalize(reflect(L,N));
	vec3 V = normalize(P.xyz);
	
	// Ambient calculation
	vec4 ambient = gl_FrontMaterial.ambient * gl_LightModel.ambient;
	
	// Emission calculation
	vec4 emission = gl_FrontMaterial.emission;
	
	// Diffuse calculation    
    float roughness = 5.0/gl_FrontMaterial.shininess;    
    const float PI = 3.14159;
	    
    float NdotL = dot(N, L);
    float NdotV = dot(N, V); 

    float angleVN = acos(NdotV);
    float angleLN = acos(NdotL);
    
    float alpha = max(angleVN, angleLN);
    float beta = min(angleVN, angleLN);
    float gamma = dot(V - N * dot(V, N), L - N * dot(L, N));
    
    float roughnessSquared = roughness * roughness;
    
    float A = 1.0 - 0.5 * (roughnessSquared / (roughnessSquared + 0.57));
    float B = 0.45 * (roughnessSquared / (roughnessSquared + 0.09)); 
    float C = sin(alpha) * tan(beta);

    float diffuseIntensity = max(0.0, NdotL) * (A + B * max(0.0, gamma) * C);
	vec4 diffuse = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse * diffuseIntensity;
	
	// Specular calculation
	
	float specularIntensity = pow(max(dot(R, V),0),0.3*gl_FrontMaterial.shininess);
	vec4 specular = gl_FrontMaterial.specular * gl_LightSource[0].specular * specularIntensity;
	
	return clamp(ambient+emission+diffuse+specular, 0, 1);
	//return clamp(ambient+emission+diffuse, 0, 1);
}

void main()
{
    // Do Nothing
    //gl_FragColor = phongIllumination(P, N);
    //gl_FragColor = orenNayarlllum(P, N);
    gl_FragColor = toonIllumination(P, N);
}