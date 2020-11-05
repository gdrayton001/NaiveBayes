 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(int argc, char *argv[]) {
	FILE *myFile = fopen("/home/gdrayton001/CS351/CSCI-351-machine-learning/ML-ratings.txt", "r");
	char buffer[80];
	size_t const n;
	size_t const m;

	fscanf(myFile, "%zu %zu", &n, &m);

	double * const movie1 = malloc(n * sizeof(double));
	double * const movie2 = malloc(n * sizeof(double));
	double * const movie3 = malloc(n * sizeof(double));
	double * const movie4 = malloc(n * sizeof(double));
	double * const movie5 = malloc(n * sizeof(double));
	double const urating[10] = {0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0};

	assert(movie1);
	assert(movie2);
	assert(movie3);
	assert(movie4);
	assert(movie5);
	
	size_t i;
	for(i = 0; i < n; i++) {
		fscanf(myFile, "%lf %lf %lf %lf %lf", &movie1[i], &movie2[i], &movie3[i], &movie4[i], &movie5[i]);
		//printf("%lf %lf %lf %lf %lf\n", movie1[i], movie2[i], movie3[i], movie4[i], movie5[i]);
	}

	int sum = 0;
	int div = 0;
	size_t j;

	for(j = 0; j < n; j++) {
		if (movie5[j] == 1.5) {
			div++;
			if (movie1[j] == urating[0]) {
				sum++;
			}
		}
	}

	printf("%i / %i\n", sum, div);
	
	float prob = (float) sum / (float) div;
	printf("%d\n", prob);

	size_t k;
	int suma = 0;
	int sumb = 0;
	int sumc = 0;
	int sumd = 0;
	int diva = 0;
	int divb = 0;
	int divc = 0;
	int divd = 0;

	for(k = 0; k < n; k++) {
		if (movie1[k] == urating[0]) {
			diva++;
			if (movie5[k] == 1.5) {
				suma++;
			}
		}
		if (movie2[k] == urating[1]) {
			divb++;
			if (movie5[k] == 1.5) {
				sumb++;
			}
		}
		if (movie3[k] == urating[2]) {
			divc++;
			if (movie5[k] == 1.5) {
				sumc++;
			}
		}
		if (movie4[k] == urating[3]) {
			divd++;
			if (movie5[k] == 1.5) {
				sumd++;
			}
		}
	}

	printf("%i / %i\n", suma, diva);
	printf("%i / %i\n", sumb, divb);
	printf("%i / %i\n", sumc, divc);
	printf("%i / %i\n", sumd, divd);

	float proba = (float) suma / (float) diva;
	float probb = (float) sumb / (float) divb;
	float probc = (float) sumc / (float) divc;
	float probd = (float) sumd / (float) divd;
	printf("%d\n", proba);
	printf("%d\n", probb);
	printf("%d\n", probc);
	printf("%d\n", probd);

	int const close = fclose(myFile);
	assert(!close);

}
