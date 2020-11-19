#include <iostream>
#include <locale.h>
#include <conio.h>
using namespace std;

class People {
protected:
	string name, surname, Say;
public:
	People() {
		printf("People()\n");
	}
	People(string name, string surname) {
		printf("People(string name, string surname)\n");
		this->name = name;
		this->surname = surname;
	}
	People(const People &n) {
		printf("People(const Point &n)\n");
		name = n.name;
		surname = n.surname;
	}
	virtual ~People() {
		cout << name << " " << surname << endl;
		printf("~People()\n");
	}
	void Change_surname(string surn) {
		surname = surn;
	}
};

class Nationality : public People {
private:
	string nation;
public:
	Nationality(): People() {
		printf("Nationality()\n");
	}
	Nationality(string name, string surname, string nation):People(name,surname) {
		printf("Nationality(string name, string surname, string nation)\n");
		this->nation = nation;
	}
	Nationality(const Nationality& n) {
		printf("People(const Point &n)\n");
		name = n.name;
		surname = n.surname;
		nation = n.nation;
	}
	~Nationality() {
		cout << name << " " << surname << " " << nation << endl;
		printf("~Nationality()\n");
	}
	void sound() {
		if(nation == "Tatar")
			cout << "TATAR say: исэмесес" << endl;
	}
	void eat();
};
void Nationality:: eat(){
	cout << "Съел ущпущмак на завтрак " << endl;
}

class NewPeople {
protected:
	People *p;
public:
	NewPeople() {
		p = new People();
		printf("NewPeople()\n");
	}
	NewPeople(string name, string sername) {
		printf("NewPeople(string name, string surname)\n");
		p = new People(name, sername);
	}
	NewPeople(const NewPeople& N) {
		printf("People(const Point &n)\n");
		p = new People(*(N.p));
	}
	~NewPeople() {
		delete p;
		printf("~NewPeople()\n");
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	{
		People Man1;
		People Man2("Egor", "Vakbilash");
		People Man3(Man2);
	}
	{
		cout << "-------------------" << endl;
		People* p1 = new People;
		People* p2 = new People("Aleksandr", "Pupkin");
		People* p3 = new People(*p2);
		People* chel = new People("Gena", "Zalupkin");
		chel->Change_surname("Chelovecheskay");
		delete p1;
		delete p2;
		delete p3;
		delete chel;
		cout << "-------------------" << endl;
	}
	{
		cout << "-------------------" << endl;
		Nationality *N = new Nationality("Mamduh", "Baizigitov", "Tatar");
		Nationality* Q = new Nationality("Yra", "Ivanov", "Russian");
		Q->sound();
		N->sound();
		N->eat();
		delete N;
		delete Q;
		cout << "-------------------" << endl;
	}
	{
		cout << "-------------------" << endl;
		People* Q = new Nationality("Yra", "Ivanov", "Russian");
		delete Q;
		cout << "-------------------" << endl;
	}
	{
		cout << "-------------------" << endl;
		NewPeople* k = new NewPeople("Valenok", "Poteranyi");
		delete k;
		cout << "-------------------" << endl;
	}

}