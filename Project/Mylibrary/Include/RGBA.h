#pragma once
#include "HSV.h"

namespace mylib
{
	class RGBA
	{
		friend class HSV;
		float r = 0;
		float g = 0;
		float b = 0;
		float a = 0;
	public:
		float red() const;

		void set_r(float r);

		float green() const;

		void set_g(float g);

		float blue() const;

		void set_b(float b);

		float alpha() const;

		void set_a(float a);
		void to_convert(const HSV& hsv);

		RGBA(float r_, float g_, float b_, float a_);
		RGBA();
	};
}
