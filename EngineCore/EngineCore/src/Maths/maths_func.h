#pragma once

#define _USE_MATH_DEFINES	//gets us math defs like M_PI
#include <math.h>
namespace engineCore{namespace maths{
	inline float toRadians(float degrees)
	{
		return degrees*M_PI / 180;
	}
	

}}