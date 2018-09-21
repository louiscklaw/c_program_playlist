
#include <stdio.h>
#include "math.h"

void HSVToRGB(double hsv_H, double hsv_S, double hsv_V, int rgb[]) {
	double r = 0, g = 0, b = 0;

	if (hsv_S == 0)
	{
		r = hsv_V;
		g = hsv_V;
		b = hsv_V;
	}
	else
	{
		int i;
		double f, p, q, t;

		if (hsv_H == 360)
			hsv_H = 0;
		else
			hsv_H = hsv_H / 60;

		i = (int)trunc(hsv_H);
		f = hsv_H - i;

		p = hsv_V * (1.0 - hsv_S);
		q = hsv_V * (1.0 - (hsv_S * f));
		t = hsv_V * (1.0 - (hsv_S * (1.0 - f)));

		switch (i)
		{
		case 0:
			r = hsv_V;
			g = t;
			b = p;
			break;

		case 1:
			r = q;
			g = hsv_V;
			b = p;
			break;

		case 2:
			r = p;
			g = hsv_V;
			b = t;
			break;

		case 3:
			r = p;
			g = q;
			b = hsv_V;
			break;

		case 4:
			r = t;
			g = p;
			b = hsv_V;
			break;

		default:
			r = hsv_V;
			g = p;
			b = q;
			break;
		}

	}

	rgb[0] = r * 255;
	rgb[1] = g * 255;
	rgb[2] = b * 255;
}

void func_helloworld(){
    printf("\nhelloworld\n");
}
