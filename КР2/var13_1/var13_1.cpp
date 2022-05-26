#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

void matrixRowsShift(int** matrix, int m, int n, int shift) {
    int* temp = new int[n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int shiftedInd = (j - shift);
            if (shiftedInd < 0) {
                temp[n + shiftedInd] = matrix[i][j];
            }
            else {
                temp[shiftedInd] = matrix[i][j];
            }
        }
        //matrix[i] = temp;
        for (int k = 0; k < n; k++) {
            matrix[i][k] = temp[k];
        }
    }
    delete[] temp;
}

int main()
{
    srand(time(NULL));

    int m, n;
    std::cout << "Enter m for number of rows and n for number of coloms on a matrix: \n";
    std::cout << "rows m: ";  // вводиться кількість рядків
    std::cin >> m;
    std::cout<<std::endl;
    std::cout << "coloms n: ";  // вводиться кількість стопців
    std::cin >> n;
    std::cout << std::endl;

    int** randMatrix = new int* [m]; // динамічно виділяємо пам'ять у відповідності з введеною кілкістю рядкв та совпців 
    for (int i = 0; i < m; i++) {
        randMatrix[i] = new int[n];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            randMatrix[i][j] = rand() % 1001;   // заповнюємо матрицю випадковими числами до 1000
        }
    }

    std::cout << std::endl;
    std::cout << "Initial randomly filled matrix: \n";   // виводимо початкову матрицю
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(5) << randMatrix[i][j];  
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    int leftShift;
    std::cout << "Enter the number by which elements of the rows in matrix will be shifted to the left: \n";
    std::cout << "Left shift: ";  // вводиться зсув ліворуч
    std::cin >> leftShift;
    std::cout << std::endl;

    matrixRowsShift(randMatrix, m, n, leftShift);

    std::cout << std::endl;
    std::cout << "Matrix with shifted elements: \n";   // виводимо перетворену матрицю
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(5) << randMatrix[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int i = 0; i < m; i++) {  //звілняємо пам'ять
        delete[] randMatrix[i];
    }
    delete[] randMatrix;

    return 0;
}

// Лещинський Богдан КА-07 Microsoft Visual Studio