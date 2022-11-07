#ifndef __BITMAP_H
#define __BITMAP_H

#include <stdio.h>
#include <math.h>
typedef struct {
	float a, r, g, b;
} color_t;

unsigned int color_to_int(color_t color);

void save_bmp(unsigned char * data, int width, int height, char * title);

#endif