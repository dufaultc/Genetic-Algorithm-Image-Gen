#include "a4.h"
#include <math.h>
#include <stdio.h>

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size)
{

	double sum = 0;
	int i;
	int rem = image_size&0x7;

	// Loop unraveling and invariance operations performed in order to optimize program. Calculations performed multiple times
	// are performed one and then their results are stored, whenever possible
	
	PIXEL AE1;

		PIXEL BEE1;
		PIXEL AE2;
		PIXEL BEE2;
		PIXEL AE3;
		PIXEL BEE3;
		PIXEL AE4;
		PIXEL BEE4;
		PIXEL AE5;
		PIXEL BEE5;
		PIXEL AE6;
		PIXEL BEE6;
		PIXEL AE7;
		PIXEL BEE7;
		PIXEL AE8;
		PIXEL BEE8;


	int bleep = image_size - rem;
	for(i = 0; i < (bleep); i+=8)  //Loop unrolling
	{


		AE1 = *(A + i);
		BEE1 = *(B + i);
		AE2 = *(A + (i+1));
		BEE2 = *(B + (i+1));
		AE3 = *(A + i+2);
		BEE3 = *(B + i+2);
		AE4 = *(A + i+3);
		BEE4 = *(B + i+3);
		AE5 = *(A + i+4);
		BEE5 = *(B + i+4);
		AE6 = *(A + i+5);
		BEE6 = *(B + i+5);
		AE7 = *(A + i+6);
		BEE7 = *(B + i+6);
		AE8 = *(A + i+7);
		BEE8 = *(B + i+7);

		sum = sum + (AE1.r - BEE1.r)*(AE1.r - BEE1.r) + (AE1.g - BEE1.g)*(AE1.g - BEE1.g) + (AE1.b - BEE1.b)*(AE1.b - BEE1.b) + (AE2.r - BEE2.r)*(AE2.r - BEE2.r) + (AE2.g - BEE2.g)*(AE2.g - BEE2.g) + (AE2.b - BEE2.b)*(AE2.b - BEE2.b) + (AE3.r - BEE3.r)*(AE3.r - BEE3.r) + (AE3.g - BEE3.g)*(AE3.g - BEE3.g) + (AE3.b - BEE3.b)*(AE3.b - BEE3.b) +  (AE4.r - BEE4.r)*(AE4.r - BEE4.r) + (AE4.g - BEE4.g)*(AE4.g - BEE4.g) + (AE4.b - BEE4.b)*(AE4.b - BEE4.b) + (AE5.r - BEE5.r)*(AE5.r - BEE5.r) + (AE5.g - BEE5.g)*(AE5.g - BEE5.g) + (AE5.b - BEE5.b)*(AE5.b - BEE5.b) + (AE6.r - BEE6.r)*(AE6.r - BEE6.r) + (AE6.g - BEE6.g)*(AE6.g - BEE6.g) + (AE6.b - BEE6.b)*(AE6.b - BEE6.b) + (AE7.r - BEE7.r)*(AE7.r - BEE7.r) + (AE7.g - BEE7.g)*(AE7.g - BEE7.g) + (AE7.b - BEE7.b)*(AE7.b - BEE7.b)+ (AE8.r - BEE8.r)*(AE8.r - BEE8.r) + (AE8.g - BEE8.g)*(AE8.g - BEE8.g) + (AE8.b - BEE8.b)*(AE8.b - BEE8.b);

	}

	for(i = (image_size - rem); i<image_size; i++){
		PIXEL AE1 = *(A + i);
		PIXEL BEE1 = *(B + i);
		sum = sum + ((AE1).r - (BEE1).r)*((AE1).r - (BEE1).r) + ((AE1).g - (BEE1).g)*((AE1).g - (BEE1).g) + ((AE1).b - (BEE1).b)*((AE1).b - (BEE1).b);
	}
	
	
	return sqrt(sum);

}
void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size){
	int image_size = ((individual->image).width)*((individual->image).height);
	for(int i = 0; i<population_size; i++){
		(individual+i)->fitness = comp_distance(image, ((individual+i)->image).data, image_size);
	}
}
