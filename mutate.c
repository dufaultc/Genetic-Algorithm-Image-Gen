#include "a4.h"
#include <stdlib.h>
#include <stdio.h>

void mutate (Individual *individual , double rate){

	int mutateThis  = (int)(rate/100*(individual->image).width*(individual->image).height);
	int div = RAND_MAX/((individual->image).max_color);
	int div2 = (RAND_MAX/( ((individual->image).width) * ((individual->image).height) - 1 ) );
	PIXEL *temp = (individual->image).data;
	PIXEL *temp2; 
	for (int i = 0; i<mutateThis; i++){
		temp2 = temp + (int)(rand()/div2);
		temp2->r = (int) rand()/(div);
		temp2->g = (int) rand()/(div);
		temp2->b = (int) rand()/(div);
	}
}

void mutate_population (Individual *individual, int population_size , double rate){ 
	for(int i = (int)(population_size/4); i<population_size; i++){
		mutate(individual+i, rate);
	}
}


//M + rand() / (RAND_MAX / (N - M + 1) + 1)
