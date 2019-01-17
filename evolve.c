#include "a4.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int comparator(const void *p, const void *q)
{
	double fit1 = ((Individual *)p)->fitness;
	double fit2 = ((Individual *)q)->fitness;
	return ((int)(fit1-fit2));
}

void free_image(PPM_IMAGE *p){
	free(p->data);
	free(p);
}



PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate)
{
	srand((int)time(NULL));

	Individual *individual;

	individual = generate_population(population_size, image->width, image->height, image->max_color);
	
	comp_fitness_population(image->data, individual, population_size);
	printf("The initial fitness is around: %f.\n", individual->fitness);
	qsort(individual, population_size, sizeof(Individual), comparator);
	

	for(int i = 0; i < num_generations; i++)	
	{

		crossover(individual, population_size);
		mutate_population(individual, population_size, rate);
		comp_fitness_population(image->data, individual, population_size);
		qsort(individual, population_size, sizeof(Individual), comparator);

		//printf("%d \n", i);
		//printf("Fitness: %f \n", individual[0].fitness);
		
	}
	printf("The final fitness is: %f.", individual->fitness);
	
	PPM_IMAGE *return_value = malloc(sizeof(PPM_IMAGE));
	return_value->width = individual->image.width;
	return_value->height = individual->image.height;
	return_value->max_color = individual->image.max_color;
	return_value->data = malloc(sizeof(PIXEL)*individual->image.height*individual->image.width);
	for (int i = 0; i < individual->image.height*individual->image.width; i++){
		((return_value->data)+i)->r = ((individual->image.data)+i)->r;
		((return_value->data)+i)->b = ((individual->image.data)+i)->b;
		((return_value->data)+i)->g = ((individual->image.data)+i)->g;
	}
	

	for(int i = 0; i< population_size; i++)
	{
		free(((individual+i)->image).data);
	}
	free(individual);
		

	return return_value;
	
}
