#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "particle.h"
#include "BoundBox.h"
#include "physics.h"
#include "draw2D.h"
#include "bitmap.h"
#include "timer.h"

int width = 1000;
int height = 1000;
int running = 1;

int main(){
    // init the things that are used forever!
    srand(time(NULL));
    int numParticles = 10;
    // clock_t tick;
    // clock_t tock;
    float timestep = 1.0f;
    
    unsigned int * PixelBuffer = (unsigned int *) malloc(sizeof(unsigned int) * width * height);
    char title[64];
    Particle * particle_list = init_particles(numParticles,(vec_t){0,0},(vec_t){width,height});
    int * sub_particles = (int *) malloc(sizeof(int) * numParticles);
    for(int i = 0; i < numParticles; i++)sub_particles[i] = i;
    
    //just do 60 frames for now
    int numFrame = 0;
    StartTimer();
    // tick = clock();
    while (numFrame < 60) {
        // Builds a Bounding volume hierarchy ish https://en.wikipedia.org/wiki/Bounding_volume_hierarchy
        Box * Boxes = build_boxes(particle_list, numParticles, sub_particles,0,timestep);
        
        //Move particles by 1 frame's worth of time
        physics_step(particle_list, numParticles,Boxes, timestep);
        
        
        //draws the image
        draw_image(PixelBuffer, width, height, particle_list, numParticles, Boxes);
        sprintf(title, "./Output/Frame_%d.bmp", numFrame++);
        save_bmp((unsigned char *)PixelBuffer, width, height, title);
        
        //the particles have moved so the boxes are wrong and useless now
        free(Boxes);
    }
    // tock = clock();
    double runtime = GetTimer();
    printf(" total: %f s\n", runtime / 1000);
    // printf("%g\n", (double)(tock - tick) / CLOCKS_PER_SEC);
    free(sub_particles);
    free(particle_list);
    free(PixelBuffer);
    

}