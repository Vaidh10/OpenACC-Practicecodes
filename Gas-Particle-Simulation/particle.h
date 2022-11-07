#ifndef __particle_H
#define __particle_H

#include <stdlib.h>

#define dims 2
enum AXIS {X, Y};

typedef struct {
	float v[dims];
} vec_t;


typedef struct{
    vec_t pos;      //pixels
    vec_t vel;      // pixels per frame
	float radius;   // pixels
}Particle;

Particle * init_particles(int numParticles,vec_t min, vec_t max);

#endif