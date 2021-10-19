#pragma once
#include "RGBA.h"
#include "cmath"
#include <algorithm>

namespace mylib
{
	class HSV
	{
		friend class RGBA;
		float h = 0;
		float s = 0;
		float v = 0;
	public:
		float hue() const;

		void set_h(float h);

		float saturation() const;

		void set_s(float s);

		float value() const;

		void set_v(float v);
		HSV(float hue, float saturation, float value);

		void to_convert(const RGBA& rgb);

		HSV& operator=(const HSV&);

		HSV& operator=(HSV&);
	};

}