#include<iostream>
#include<cstdlib>
#include<ctime>


double elementsSum(double **matrix,int size) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			sum += matrix[i][j];
		}
	}
	return sum;
}

void allocation(int n,double*** matrix) {
	*matrix = new double* [n];
	for (int i = 0; i < n; i++) {
		(*matrix)[i] = new double[n];
	}
}

int main() {
	srand(time(NULL));
	const int n4 = 4;
	const int n5 = 5;
	
	std::cout << "---Random generated 4x4 upper triangle matrix with elements in range [-100,100]: \n";

	double** matrix4;
	allocation(n4, &matrix4);
	//initializing and filling up the matrix
	for (int i = 0; i < n4; i++) {
		for (int j = 0; j < n4; j++) {	
			matrix4[i][j] = rand() % 201 - 100;
			std::cout << matrix4[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "\n";

	std::cout << "Elements` sum : " << elementsSum(matrix4,n4) << "\n";

	for (int i = 0; i < n4; i++) {
		delete[] matrix4[i];
	}
	delete[] matrix4;

	std::cout << "---Random generated 5x5 upper triangle matrix with elements in range [-100,100]: \n";

	double** matrix5;
	allocation(n5, &matrix5);
	//initializing and filling up the matrix
	for (int i = 0; i < n5; i++) {
		for (int j = 0; j < n5; j++) {
			matrix5[i][j] = rand() % 201 - 100;
			std::cout << matrix5[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	std::cout << "Elements` sum : " << elementsSum(matrix5,n5) << "\n";

	for (int i = 0; i < n5; i++) {
		delete[] matrix5[i];
	}
	delete[] matrix5;

	return 0;
}