#include <iostream>
#include <locale.h>
#include <conio.h>
using namespace std;

class Nationality {
private:
	int x;
	int y;
public:
	Nationality() {
		printf("Nationality()\n");
		x = 0;
		y = 0;

	}
	Nationality(int x, int y) {
		printf("Nationality(int x, int y)\n");
		this->x = x;
		this->y = y;
	}
	Nationality(const Nationality &n) {
		printf("Nationality(const Point &p)\n");
		x = n.x;
		y = n.y;
	}
	~Nationality() {
		cout << x << ' ' << y << endl;
		printf("~Nationality()\n");
	}
};

int main() {
	

	

}