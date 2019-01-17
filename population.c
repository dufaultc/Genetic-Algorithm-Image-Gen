#include "a4.h"
#include <stdlib.h>

PIXEL *generate_random_image(int width, int height, int max_color)
{
	PIXEL *pixels;
	pixels = malloc((sizeof(PIXEL))*(width*height));

	
	for(int i = 0; i < (width*height); i++)
	{		
		pixels[i].r = rand() / (RAND_MAX / (max_color + 1));		
		pixels[i].g = rand() / (RAND_MAX / (max_color + 1));
		pixels[i].b = rand() / (RAND_MAX / (max_color + 1));
	}
	
	return pixels;
}

Individual *generate_population(int population_size, int width, int height, int max_color)
{
	Individual *individuals;
	individuals = malloc((sizeof(Individual))*(population_size));
	PPM_IMAGE current;

	for(int i = 0; i < (population_size); i++)
	{

		current.data = generate_random_image(width,height,max_color);
		current.width  = width;
		current.height  = height;
		current.max_color  = max_color;
		individuals[i].image = current;
	
	}
	
	return individuals;
	

}
