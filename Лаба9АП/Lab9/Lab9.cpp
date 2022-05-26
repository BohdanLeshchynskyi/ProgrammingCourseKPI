#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <locale.h>

using namespace std;

struct Institution {
	string name;
	string adress;
};

int main() {
	srand(time(NULL));

	setlocale(LC_ALL, "RUS");

	string possibleNames[] = { "��� i�.������ ��������", "���� ��I i�.����� �i���������",
							   "���������", "�������� ��������i�", "���", "���i����� ���i����i��", "���", " " };
	string possibleAdresses[] = { "���.��������� 19", "��.�������� 15", "���.���� �������� 17", "����������� ����� 1",
								  "��.������� ������� 16", "���. ����������� ��i���", "���. ���� 0", " " };
	cout << "--Enter number of educational institutions: \n";
	int number;
	cin >> number;

	Institution *institutions1 = new Institution[number]; // creating a dynamic array of structures 

	cout << "----Initially generated array of educational insitutions: \n";
	for (int i = 0; i < number; i++) {
		institutions1[i] = { possibleNames[rand() % 8],possibleAdresses[rand() % 8] };
		cout << institutions1[i].name << "  " << institutions1[i].adress<<endl;
	}

	cout << endl;
	cout << "----Edited array of educational insitutions: \n";
	int counter = 0;
	for (int i = 0; i < number; i++) {
		if (institutions1[i].name != " " && institutions1[i].adress != " ") {
			counter++;
		}		
	}
	Institution *institutions2 = new Institution[counter];
	int p = 0;
	for (int i = 0; i < number; i++) {
		if(institutions1[i].name != " " && institutions1[i].adress != " "){
			institutions2[p] = institutions1[i];
			cout << institutions2[p].name << " " << institutions2[p].adress << endl;
			p++;
		}
	}
	
	delete[] institutions1;
	delete[] institutions2;

	return 0;
}