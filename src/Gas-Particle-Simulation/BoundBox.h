#ifndef __BoundBox_H
#define __BoundBox_H

#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#include "particle.h"

typedef struct{
    int numBoxes;
    int P_index;
    int num_P;
    int children[(1<<dims)];
    vec_t max_pos;
    vec_t min_pos;
    vec_t mid_pos;
}Box;

Box * build_boxes(Particle * particle_list, int numParticles, int sub_particles[numParticles], int BoxOffset, float timestep);
int * get_within_bounds(Box * Boxes, int box_num, vec_t min, vec_t max, int * P_num);
#pragma acc routine(get_within_bounds) seq
#endif
