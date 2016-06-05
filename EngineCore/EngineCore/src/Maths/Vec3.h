#pragma once

#include <iostream>

namespace engineCore {
	namespace maths {
		struct vec3
		{
			float x, y, z;
			vec3();
			vec3(const float& x, const float& y);

			vec3& add(const vec3& other);
			vec3& subtract(const vec3& other);
			vec3& multiply(const vec3& other);
			vec3& divide(const vec3& other);
		
			vec3& operator+=(const vec3& other);
			vec3& operator-=(const vec3& other);
			vec3& operator*=(const vec3& other);
			vec3& operator/=(const vec3& other);
			
			bool operator==(const vec3& other);
//			bool operator==(const vec3& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
			friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
		};
	}
}