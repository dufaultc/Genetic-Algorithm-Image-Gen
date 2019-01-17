#include "a4.h"
#include <stdio.h>
#include <stdlib.h>

PPM_IMAGE *read_ppm (const char *file_name){
	int height, width, max_colour;
	int err, err2;
	FILE *fp  = fopen(file_name, "r");

	err = fscanf(fp, "P3\n%d %d\n%d\n", &width, &height, &max_colour);
	if (err < 3){
		printf("Error: Is this possibly not a properly formatte PPM image?");
		exit(1);
	}
	PIXEL *data = malloc(sizeof(PIXEL)*width*height);
	int r, b, g;
	for(int i  = 0; i < width*height; i++){
		err2  = fscanf(fp, "%d %d %d ", &r, &g,  &b); 
		if (err2 < 3){
			printf("Error: The header for this PPM file is formatted correctly, but there is something wrong with the body.");
			exit(1);
		}
		(data+i)->r = r;
		(data+i)->g = g;
		(data+i)->b = b;
	}
	PPM_IMAGE *image = malloc(sizeof(PPM_IMAGE));
	image->data = data;
	image->width = width;
	image->height = height;
	image->max_color = max_colour;
	fclose(fp);
	return image;
}

void write_ppm(const char * file_name , const PPM_IMAGE *image){
	FILE *fp;
	fp = fopen(file_name, "w");
	PIXEL *temp = image->data;
	fprintf(fp, "P3\n%d %d\n%d\n", image->width, image->height, image->max_color);
	for(int i = 0; i<(image->width*image->height); i++){
		fprintf(fp, "%d %d %d ", temp->r, temp->g, temp->b);
		temp++;
	}
	fclose(fp); 
}
