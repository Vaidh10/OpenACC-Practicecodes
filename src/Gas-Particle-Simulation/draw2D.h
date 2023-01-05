#ifndef __DRAW2D_H
#define __DRAW2D_H

#include <math.h>
#include <stdlib.h>

#include "particle.h"
#include "BoundBox.h"
#include "bitmap.h"

void draw_image(unsigned int * PixelBuffer, int width, int height, Particle * particle_list, int numParticles,Box * Boxes);

#endif