#include <iostream>
#include "Virus.h"
#include "FluVirus.h"
#include "Patient.h"
#include "Dengue.h"
#include <stdio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

int main() {

	Patient *p = new Patient();
	char t = 0;

	srand(time(0));

	cout << "Patient resistance: " << p->InitResistance() << endl;

	while (p->GetState() == 1)
	{
		cout << "Take Medicine (0 = NO, 1 = YES) "; cin >> t;
		
		if (t == '1')
		{
			int min = 1;
			int max = 10;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
			cout << "medicine_resistance= " << medicine_resistance<<endl;

			if (medicine_resistance >= 30) {
				cout << "Virus all died : ((\n";
				p->DeleteListVirus();
				delete p;
				break;
			}
			else
			{
				p->TakeMedicine(medicine_resistance);
			}

		}
		else
		{
			delete p;
			//exit(0);
		}
	}
	system("pause");
	return 0;
}