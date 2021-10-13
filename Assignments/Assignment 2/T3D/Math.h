// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Robert Ollington
//
// math.h
//
// Currently just a few constants
// Adapted from Ogre3D
#pragma once

#include <cstdlib>
#include <algorithm>

// TODO: Fix windows.h using preprocessor symbol NOMINMAX. IIRC, SDL includes windows.h -- maybe do it before then?
#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

namespace T3D
{
	//! \brief Helpful constants and free functions.
	class Math
	{
	public:
        static const float PI;
        static const float TWO_PI;
        static const float HALF_PI;
		static const float DEG2RAD;
		static const float RAD2DEG;
		static const float LOG2;

		//! \brief Linearly interpolate between two values, based on time t.
		/*
		 * \param first starting value
		 * \param second ending value
		 * \param t time (aka alpha)
		 *
		 */
		static float lerp(float first, float second, float t) { return t*(second-first)+first; }
		static float smoothedLerp(float first, float second, float t, float aT)
		{ 
			float dist = second - first;
			float a = dist / (aT * (1 - aT));
			float v = a * aT;

			if (t < 0) return first;
			else if (t < aT) return first + 0.5 * a * t * t;
			else if (t < 1 - aT) return first + 0.5 * a * aT * aT + v * (t - aT);
			else if (t <= 1) return first + 0.5 * a * aT * aT + v * (1 - 2 * aT) + v * (t - 1 + aT) - 0.5 * a * (t - 1 + aT) * (t - 1 + aT);

			return second;
		}

		static float** generateFractal(int size, float min, float max, float roughness, bool tile = false);

		/*! randRange
		  Generates a random value in a given range
		  \param minimum	range from 
		  \param maximum	range to 
		  */
		static float randRange(float minimum, float maximum) { 
			float r = float(rand())/RAND_MAX;
			return r*(maximum-minimum)+minimum; 
		}

		/*! randRangeND
		  Generates a random value in a given range with an
		  approximation of a normal distribution, uses Central
		  limit theorem.
		  \param minimum	range from 
		  \param maximum	range to 
		  \param iterations	iterations (more for better distribution curve)
		  */
		static float randRangeND(float minimum, float maximum, int iterations=3){ 
			float r = 0;
			for (int i=0; i<iterations; i++)
				r += float(rand())/RAND_MAX;
			return r / (float)iterations * (maximum - minimum) + minimum; 
		}

		//! \brief Ensure value lies between an inclusive min and max
		/*
		 * \param value value to clamp
		 * \param minimum lower bound (inclusive)
		 * \param maximum upper bound (inclusive)
		 *
		 */
		static float clamp(float value, float minimum, float maximum){ 
			return std::max(
				std::min(maximum,value),minimum
				); 
		}
	};
}
