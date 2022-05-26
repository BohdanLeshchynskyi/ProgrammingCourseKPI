#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <locale.h>
#include <string>

using namespace std;

int main(){
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string letters;
    string word;
    int n;
    

    cout << "Введіть підряд 10 літер українського алфавіту: \n";
    getline(cin, letters);
    cout << "0123456789 \n";

    cout << "Введіть якесь слово використовуючи введені раніше літери: \n";
    getline(cin, word);

    int* wordNumbers = new int[word.size()]; // creating an array for storing correspondig number for letters of the entered word

    //enumerating letters of the entered word
    for (int i = 0; i < word.size(); i++) {
        for (int j = 0; j < letters.size(); j++) {
            if (word[i] == letters[j]) {
                wordNumbers[i] = j;
                break;
            }
        }
    }
    for (int i = 0; i < word.size(); i++) {
        cout << wordNumbers[i];
    }
    cout << "\n";

    cout << "Введіть довжину кода(3-8):\n";
    cin >> n;
    int* code = new int[n];

    cout << "Введіть код для шифровки слова: \n";
    for (int i = 0; i < n; i++) {
        cin >> code[i];
    }
    cout << "\n";

    //encoding the word
    cout << "Закодоване слово: \n";
    for (int i = 0; i < word.size(); i++) {
        cout << (wordNumbers[i] + code[i % n]) % 10;
    }

    return 0;
}