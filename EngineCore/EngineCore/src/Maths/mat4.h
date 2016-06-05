#pragma once


#include "maths_func.h"
#include "Vec3.h"
namespace engineCore {namespace maths {
	float toRadians(float degrees);
	struct mat4	//bc everything will be public by default
	{
		float elements[4 * 4];	//write it this way to indicate a 4x4 mat. OpenGL only supports col major ordering

		mat4();
		mat4(float diagonal);

		static mat4 identity(); //constructs new identity matrix

		mat4& multiply(const mat4& other);
		friend mat4 operator*(mat4 left, const mat4& right);
		mat4& operator*=(const mat4& other);

		//defines the boundaries of where crap will be rendered
		static mat4 orthographic(float left, float right, float top, float bottom, float near, float far); 
		static mat4 perspective(float fov, float aspectRatio, float near, float far);

		static mat4 translation(const vec3& translation);
		static mat4 rotation(float angle, const vec3& axis);
		static mat4 scale(const vec3& scale);


	};


}}