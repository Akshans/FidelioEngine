#pragma once

#include <iostream>

namespace sparky {
	namespace maths {
		struct vec4
		{
			float x, y, w, z;
			vec4();
			vec4(const float& x, const float& y, const float& w, const float& z);

			vec4& add(const vec4& other);
			vec4& subtract(const vec4& other);
			vec4& multiply(const vec4& other);
			vec4& divide(const vec4& other);
		
			vec4& operator+=(const vec4& other);
			vec4& operator-=(const vec4& other);
			vec4& operator*=(const vec4& other);
			vec4& operator/=(const vec4& other);
			
			bool operator==(const vec4& other);
			bool operator==(const vec4& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
			friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
		};
	}
}