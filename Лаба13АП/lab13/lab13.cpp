#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Auto {
	char* mark;
	int price;
	int kilometers;
};

const char* marken[3] = { "BMW","Audi","Volkswagen" };

Auto createAuto() {
	Auto vehicle;
	
	int randomMark = rand() % 3;
	int strlenMark = strlen(marken[randomMark]) + 1;
	
	vehicle.mark = (char*)malloc(strlenMark * sizeof(char));
	strcpy(vehicle.mark, marken[randomMark]);

	vehicle.price = rand() % 10000 + 3000;
	vehicle.kilometers = rand() % 40000 + 10000;

	return  vehicle;
}

void addAuto( FILE* f, Auto vehicle ) {
	fprintf(f, "%s %d %d \n", vehicle.mark, vehicle.price, vehicle.kilometers);
}

void readEditedFile(FILE* f, int k) {
	char* fmark = (char*)malloc(11 * sizeof(char));
	float mKilometers;
	int difCars;
	int Price;
	int Kilometers;
	for (int i = 0; i < k; i++) {
		fscanf(f, "%f%s%d%d\n", &mKilometers, fmark, &Price, &Kilometers);
		printf("Mean Kilometers: %f Mark:%s Price:%d Kilometers:%d \n", mKilometers, fmark, Price, Kilometers);
	}
	fscanf(f, "%d", &difCars);
	printf("Differents car marks: %d", difCars);
}

void readInitialFile(FILE* f) {
	while (!feof(f)) {
		char* fmark = (char*)malloc(11 * sizeof(char));
		int Price;
		int Kilometers;
		if (fscanf(f, "%s%d%d\n", fmark, &Price, &Kilometers) != NULL) {
			printf("Mark:%s Price:%d Kilometers:%d \n", fmark, Price, Kilometers);
		}
	}
}

char** sortByAlphabet(FILE* f, int k) {
	char** alphabeticOrder = (char**)malloc(k*sizeof(char*));
	for (int i = 0; i < k; i++) {
		alphabeticOrder[i] = (char*)malloc(40 * sizeof(char));
	}

	for (int i = 0; i < k; i++) {
		fgets(alphabeticOrder[i], 40, f);
	}

	for (int i = 0; i < (k-1); i++) {
		for (int j = 0; j < k-i-1; j++) {
			char* swap = (char*)malloc(40*sizeof(char)); 
			if (strcmp(alphabeticOrder[j], alphabeticOrder[j + 1]) > 0) {
				strcpy(swap, alphabeticOrder[j]);
				strcpy(alphabeticOrder[j], alphabeticOrder[j + 1]);
				strcpy(alphabeticOrder[j + 1], swap);
			}
		}
	}

	return alphabeticOrder;
}

float meanKilometers(FILE* f, int k) {
	int ditances;
	float sum = 0;
	int empty;
	char* fmark = (char*)malloc(11 * sizeof(char));
	for (int i = 0; i < k; i++) {
		fscanf(f, "%s%d%d\n", fmark, &empty ,&ditances);
		sum += ditances;
	}
	free(fmark);
	return sum / k;
}

int differentCars(FILE* f, int k) {
	char** diffMarks = (char**)malloc(3 * sizeof(char*));
	for (int i = 0; i < 3; i++) {
		diffMarks[i] = (char*)malloc(40 * sizeof(char));
	}
	char* compare = (char*)malloc(40 * sizeof(char));
	int counter = 0;
	int empty1;
	for (int i = 0; i < k; i++) {
		fscanf(f, "%s%d%d\n", compare, &empty1, &empty1);
		bool isInDiff = false;
		for (int j = 0; j < counter; j++) {
			if (strcmp(compare, diffMarks[j]) == 0) {
				isInDiff = true;
				break;
			}
		}
		if (isInDiff) {
			continue;
		}
		else {
			strcpy(diffMarks[counter],compare);
			counter++;
		}
	}

	return counter;
}


int main() {
	srand(time(NULL));
	
	int n;
	printf("Enter how many cars you want to add to the file: ");
	scanf("%d", &n);

	FILE* file = fopen("cars1.txt","w");
	for (int i = 0; i < n; i++){
		addAuto(file, createAuto());
	}
	fclose(file);

	file = fopen("cars1.txt", "r");
	readInitialFile(file);
	fclose(file);
	
	file = fopen("cars1.txt", "r");
	char** carSorted;
	carSorted = sortByAlphabet(file, n);
	fclose(file);

	float mean;
	int totalDifferent;

	file = fopen("cars1.txt", "r");
	mean = meanKilometers(file, n);
	fclose(file);

	file = fopen("cars1.txt", "r");
	totalDifferent = differentCars(file, n);
	fclose(file);

	printf("\n\nCars sorted in alphabetical ordered by their marks: \n");

	file = fopen("cars2.txt", "w");
	for (int i = 0; i < n; i++) {
		fprintf(file, "%f %s", mean,carSorted[i]);
	}
	fprintf(file, "%d", totalDifferent);
	fclose(file);

	file = fopen("cars2.txt", "r");
	readEditedFile(file, n);
	fclose(file);

	return 0;
}