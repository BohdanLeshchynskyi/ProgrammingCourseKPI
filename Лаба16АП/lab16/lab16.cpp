int alphabetBig = 0;
int alphabetSmall = 0;
int digits = 0;
int controls = 0;
int punctuation = 0;
int spaces = 0;

#define alphabetBig_incr alphabetBig++
#define alphabetSmall_incr alphabetSmall++
#define spaces_incr spaces++
#define punctplus_incr punctuation++
#define control_incr controls++
#define digit_incr digits++


#define orderTo(x) ((x)<32||(x)==127 ? control_incr :\
((x)>32&&(x)<=47)||((x)>=58&&(x)<65)||((x)>=91&&(x)<=96)||((x)>=123&&(x)<=126) ? punctplus_incr :\
(x)>=48&&(x)<58 ? digit_incr :\
(x) >= 65 && (x)<=90 ? alphabetBig_incr :\
(x)>=97&&(x)<=122 ? alphabetSmall_incr :\
(x)==32 ? spaces_incr : 0)


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string fPath = "charFile.txt";

int main()
{
    ofstream file1;
    file1.open(fPath);

    string line;
    cout << "Enter a line that will be later saved to the file for further assessing: \n";
    getline(cin, line);

    file1 << line;
    file1.close();

    ifstream file2;
    file2.open(fPath);

    char ch;
    while (file2.get(ch)) {
        orderTo(ch);
    }
    file2.close();
    cout << endl;
    cout << "Entered line: " << line << endl;
    cout << endl;
    cout << "Control characters : " << controls << endl;
    cout << "Digits : " << digits << endl;
    cout << "Punctuation charackters : " << punctuation << endl;
    cout << "Uppercase letters : " << alphabetBig << endl;
    cout << "Lowcase letters : " << alphabetSmall << endl;
    cout << "Spaces : " << spaces << endl;

    remove("charFile.txt");
    return 0;
}
