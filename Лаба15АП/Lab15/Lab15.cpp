#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;

string fPath = "f.txt";
string hPath = "h.txt";
string gPath = "g.txt";

bool is_Empty(string pFile)
{
    ifstream file(pFile);
    bool isEmpty = file.peek() == ifstream::traits_type::eof();
    file.close();
    return isEmpty;
}

void addNumToFile(string filePath, int num) {
    ofstream fout;
    fout.open(filePath, ofstream::app);
    if(is_Empty(filePath)==false) fout << ' ';
    fout << num;
    fout.close();
}

void readFile(string filePath) {
    ifstream fin;
    fin.open(filePath);
    while (!fin.eof()) {
        int num ;
        fin >> num;
        cout << num << "\n";  
    }
    fin.close();

}

int main()
{
    srand(time(NULL));
    int n;
    std::cout << "Enter some even number of numbers you want to add: ";
    std::cin >> n;
    std::cout << "\n";

    int* arrPos = new int[n / 2];
    int* arrNeg = new int[n / 2];
    int* finalArr = new int[n];

    for (int i = 0; i < n / 2; i++) {
        arrPos[i] = rand() % 100 + 1;;
    }

    for (int i = 0; i < n / 2; i++) {
        arrNeg[i] = rand() % 100 - 100;
    }

    for (int i = 0; i < n / 2; i++) {
        int a = arrPos[i];
        int b = arrNeg[i];
        finalArr[2 * i] = a;
        finalArr[2 * i + 1] = b;
    }

    for (int i = 0; i < n; i++) {
        addNumToFile(fPath, finalArr[i]);
    }
    std::cout << "File f :\n";

    readFile(fPath);

    ifstream fFile;
    fFile.open(fPath);

    while (!fFile.eof()) {
        int num;
        fFile >> num;
        if (num < 0) {
            addNumToFile(hPath, num);
        }
        else {
            addNumToFile(gPath, num);
        }
    }

    fFile.close();

    ifstream hFile;
    hFile.open(hPath);

    while (!hFile.eof()) {
        int num;
        hFile >> num;
        addNumToFile(gPath, num);
    }

    hFile.close();

    cout << "File g :\n";

    readFile(gPath);

    remove("f.txt");
    remove("h.txt");
    remove("g.txt");

    return 0;
}

