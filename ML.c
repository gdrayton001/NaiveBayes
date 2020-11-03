
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(int argc, char *argv[]) {
	FILE *myFile = fopen("/home/gdrayton001/CS351/CSCI-351-machine-learning/ML-ratings-small.txt", "rw+");
	char buffer[80];
	double n;
	double m;
	double * const movie1 = malloc(n * sizeof(double));
	double * const movie2 = malloc(n * sizeof(double));
	double * const movie3 = malloc(n * sizeof(double));
	double * const movie4 = malloc(n * sizeof(double));
	double * const movie5 = malloc(n * sizeof(double));

	fscanf(myFile, "%zu %zu", &n, &m);

	assert(movie1);
	assert(movie2);
	assert(movie3);
	assert(movie4);
	assert(movie5);
	
	size_t i;
	for(i = 0; i < n; i++) {
		fscanf(myFile, "%lf %lf %lf %lf %lf", &movie1[i], &movie2[i], &movie3[i], &movie4[i], &movie5[i]);
	}

	int const close = fclose(myFile);
	assert(!close);

	printf("%zu %zu\n", n, m);

	for (i = 0; i < n; i++) {
		printf("%.1lf %.1lf %.1lf %.1lf %.1lf\n", movie1[i], movie2[i], movie3[i], movie4[i], movie5[i]);
	}

	

	free(movie1);
	free(movie2);
	free(movie3);
	free(movie4);
	free(movie5);
}
