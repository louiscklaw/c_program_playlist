

static double Min(double a, double b) { return a <= b ? a : b; }

static double Max(double a, double b) { return a >= b ? a : b; }

#include <stdio.h>

void rgbToHsv(double r, double g, double b, double hsv[]) {
	double delta, min;
	double h = 0, s, v;

	min = (double)Min(Min(r, g), b);
	v = (double)Max(Max(r, g), b);
	delta = v - min;

	if (v == 0.0)
		s = 0;
	else
		s = delta / v;

	if (s == 0)
		h = 0.0;

	else
	{
		if (r == v)
			h = (g - b) / delta;
		else if (g == v)
			h = 2 + (b - r) / delta;
		else if (b == v)
			h = 4 + (r - g) / delta;

		h *= 60;

		if (h < 0.0)
			h = h + 360;
	}

    hsv[0] = h;
    hsv[1] = s;
    hsv[2] = v/255;
}
