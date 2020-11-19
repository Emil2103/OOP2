#include <iostream>
#include <locale.h>
#include <conio.h>
using namespace std;

class People {
private:
	string name, surname, Say;
public:
	People() {
		printf("People()\n");
	}
	People(string name, string surname) {
		printf("People(int name)\n");
		this->name = name;
		this->surname = surname;
	}
	People(const People &n) {
		printf("People(const Point &p)\n");
		name = n.name;
		surname = n.surname;
	}
	~People() {
		cout << name << " " << surname << endl;
		printf("~Nationality()\n");
	}
	void Change_surname(string surn) {
		surname = surn;
	}
};

int main() {
	{
		People Man1;
		People Man2("Egor", "Vakbilash");
		People Man3(Man2);
	}
	{
		cout << endl;
		People* p1 = new People;
		People* p2 = new People("Aleksandr", "Pupkin");
		People* p3 = new People(*p2);
		People* chel = new People("Gena", "Zalupkin");
		chel->Change_surname("Chelovecheskay");
		delete p1;
		delete p2;
		delete p3;
		delete chel;
	}
	

}