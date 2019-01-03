#include <iostream>
#include "MyPoint.h"

using namespace std;

int main() {

	int posXp, posYp;

	MyPoint *p = new MyPoint();
	cout << "Input posXp: "; cin >> posXp;
	cout << "Input posYp: "; cin >> posYp;
	(*p).SetX(posXp);
	(*p).SetY(posYp);

	int posX, posY;
	MyPoint *current = new MyPoint();
	
	cout << "Input posX: "; cin >> posX;
	cout << "Input posY: "; cin >> posY;

	(*current).SetX(posX);
	(*current).SetY(posY);

	cout << "Coordinate of current point is: ";
	(*current).Display();
	cout << endl;
	
	cout << "Distance between current pointer and p is: " << (*current).Distance(*p)<<endl;
	system("pause");
	return 0;
}
