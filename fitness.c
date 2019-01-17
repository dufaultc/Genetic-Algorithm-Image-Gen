#include "a4.h"
#include <math.h>
#include <stdio.h>

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size)
{

	double sum = 0;
	int i;
	int rem = image_size&0x7;

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



/*
		sum = sum + ((*(A + i)).r - (*(B + i)).r)*((*(A + i)).r - (*(B + i)).r) + ((*(A + i)).g - (*(B + i)).g)*((*(A + i)).g - (*(B + i)).g) + ((*(A + i)).b - (*(B + i)).b)*((*(A + i)).b - (*(B + i)).b);
		sum = sum + ((*(A + i + 1)).r - (*(B + i + 1)).r)*((*(A + i + 1)).r - (*(B + i + 1)).r) + ((*(A + i + 1)).g - (*(B + i + 1)).g)*((*(A + i + 1)).g - (*(B + i+1)).g) + ((*(A + i+1)).b - (*(B + i+1)).b)*((*(A + i+1)).b - (*(B + i +1)).b);
		sum = sum + ((*(A + i + 2)).r - (*(B + i + 2)).r)*((*(A + i + 2)).r - (*(B + i + 2)).r) + ((*(A + i + 2)).g - (*(B + i + 2)).g)*((*(A + i + 2)).g - (*(B + i+2)).g) + ((*(A + i+2)).b - (*(B + i+2)).b)*((*(A + i+2)).b - (*(B + i +2)).b);
		sum = sum + ((*(A + i + 3)).r - (*(B + i + 3)).r)*((*(A + i + 3)).r - (*(B + i + 3)).r) + ((*(A + i + 3)).g - (*(B + i + 3)).g)*((*(A + i + 3)).g - (*(B + i+3)).g) + ((*(A + i+3)).b - (*(B + i+3)).b)*((*(A + i+3)).b - (*(B + i +3)).b);
		sum = sum + ((*(A + i + 4)).r - (*(B + i + 4)).r)*((*(A + i + 4)).r - (*(B + i + 4)).r) + ((*(A + i + 4)).g - (*(B + i + 4)).g)*((*(A + i + 4)).g - (*(B + i+4)).g) + ((*(A + i+4)).b - (*(B + i+4)).b)*((*(A + i+4)).b - (*(B + i +4)).b);
		sum = sum + ((*(A + i + 5)).r - (*(B + i + 5)).r)*((*(A + i + 5)).r - (*(B + i + 5)).r) + ((*(A + i + 5)).g - (*(B + i + 5)).g)*((*(A + i + 5)).g - (*(B + i+5)).g) + ((*(A + i+5)).b - (*(B + i+5)).b)*((*(A + i+5)).b - (*(B + i +5)).b);
		sum = sum + ((*(A + i + 6)).r - (*(B + i + 6)).r)*((*(A + i + 6)).r - (*(B + i + 6)).r) + ((*(A + i + 6)).g - (*(B + i + 6)).g)*((*(A + i + 6)).g - (*(B + i+6)).g) + ((*(A + i+6)).b - (*(B + i+6)).b)*((*(A + i+6)).b - (*(B + i +6)).b);
		sum = sum + ((*(A + i + 7)).r - (*(B + i + 7)).r)*((*(A + i + 7)).r - (*(B + i + 7)).r) + ((*(A + i + 7)).g - (*(B + i + 7)).g)*((*(A + i + 7)).g - (*(B + i+7)).g) + ((*(A + i+7)).b - (*(B + i+7)).b)*((*(A + i+7)).b - (*(B + i +7)).b);
*/

/*
		sum = sum + ((A[i]).r - (B[i]).r)*((A[i]).r - (B[i]).r) + ((A[i]).g - (B[i]).g)*((A[i]).g - (B[i]).g) + ((A[i]).b - (B[i]).b)*((A[i]).b - (B[i]).b) + ((A[i+1]).r - (B[i+1]).r)*((A[i+1]).r - (B[i+1]).r) + ((A[i+1]).g - (B[i+1]).g)*((A[i+1]).g - (B[i+1]).g) + ((A[i+1]).b - (B[i+1]).b)*((A[i+1]).b - (B[i+1]).b) +  ((A[i+2]).r - (B[i+2]).r)*((A[i+2]).r - (B[i+2]).r) +  ((A[i+2]).g - (B[i+2]).g)*((A[i+2]).g - (B[i+2]).g) +  ((A[i+2]).b - (B[i+2]).b)*((A[i+2]).b - (B[i+2]).b) +  ((A[i+3]).r - (B[i+3]).r)*((A[i+3]).r - (B[i+3]).r) + ((A[i+3]).g - (B[i+3]).g)*((A[i+3]).g - (B[i+3]).g) + ((A[i+3]).b - (B[i+3]).b)*((A[i+3]).b - (B[i+3]).b) + ((A[i+4]).r - (B[i+4]).r)*((A[i+4]).r - (B[i+4]).r) + ((A[i+4]).g - (B[i+4]).g)*((A[i+4]).g - (B[i+4]).g) + ((A[i+4]).b - (B[i+4]).b)*((A[i+4]).b - (B[i+4]).b) + ((A[i+5]).r - (B[i+5]).r)*((A[i+5]).r - (B[i+5]).r)+ ((A[i+5]).g - (B[i+5]).g)*((A[i+5]).g - (B[i+5]).g) + ((A[i+5]).b - (B[i+5]).b)*((A[i+5]).b - (B[i+5]).b) + ((A[i+6]).r - (B[i+6]).r)*((A[i+6]).r - (B[i+6]).r) + ((A[i+6]).g - (B[i+6]).g)*((A[i+6]).g - (B[i+6]).g) + ((A[i+6]).b - (B[i+6]).b)*((A[i+6]).b - (B[i+6]).b)+ ((A[i+7]).r - (B[i+7]).r)*((A[i+7]).r - (B[i+7]).r) + ((A[i+7]).g - (B[i+7]).g)*((A[i+7]).g - (B[i+7]).g)+ ((A[i+7]).b - (B[i+7]).b)*((A[i+7]).b - (B[i+7]).b);
*/
/*
		sum = sum + (AE1.r - BEE1.r)*(AE1.r - BEE1.r) + (AE1.g - BEE1.g)*(AE1.g - BEE1.g) + (AE1.b - BEE1.b)*(AE1.b - BEE1.b);
		sum = sum + (AE2.r - BEE2.r)*(AE2.r - BEE2.r) + (AE2.g - BEE2.g)*(AE2.g - BEE2.g) + (AE2.b - BEE2.b)*(AE2.b - BEE2.b); 
		sum = sum + (AE3.r - BEE3.r)*(AE3.r - BEE3.r) + (AE3.g - BEE3.g)*(AE3.g - BEE3.g) + (AE3.b - BEE3.b)*(AE3.b - BEE3.b);
		sum = sum + (AE4.r - BEE4.r)*(AE4.r - BEE4.r) + (AE4.g - BEE4.g)*(AE4.g - BEE4.g) + (AE4.b - BEE4.b)*(AE4.b - BEE4.b);
		sum = sum + (AE5.r - BEE5.r)*(AE5.r - BEE5.r) + (AE5.g - BEE5.g)*(AE5.g - BEE5.g) + (AE5.b - BEE5.b)*(AE5.b - BEE5.b);
		sum = sum + (AE6.r - BEE6.r)*(AE6.r - BEE6.r) + (AE6.g - BEE6.g)*(AE6.g - BEE6.g) + (AE6.b - BEE6.b)*(AE6.b - BEE6.b);
		sum = sum + (AE7.r - BEE7.r)*(AE7.r - BEE7.r) + (AE7.g - BEE7.g)*(AE7.g - BEE7.g) + (AE7.b - BEE7.b)*(AE7.b - BEE7.b);
		sum = sum + (AE8.r - BEE8.r)*(AE8.r - BEE8.r) + (AE8.g - BEE8.g)*(AE8.g - BEE8.g) + (AE8.b - BEE8.b)*(AE8.b - BEE8.b);
*/

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
