#ifndef __physics_H
#define __physics_H

#include <stdlib.h>

#include "particle.h"
#include "BoundBox.h"

void physics_step(Particle * particle_list, int numParticles, Box * Boxes, float timestep);


#endif