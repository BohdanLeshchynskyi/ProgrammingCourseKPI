#include <iostream>
#include <string>
using namespace std;

void reverseIter(string str)
{
    for (int i = str.length() - 1; i >= 0; i--) //ітеративно
        cout << str[i];
    cout << endl;
}

void reverseRec(string str, int pos)
{
    if (pos < str.length() - 1)
        reverseRec(str, pos + 1);        // рекурсивно
    std::cout << str[pos];
}

int main()
{
    string str;
    cout << "Enter a line: ";
    getline(cin, str);
    cout << "Reverse:\n";
    reverseIter(str);
    reverseRec(str, 0);
}

// Лещинський Богдан КА-07 Microsoft Visual Studio
