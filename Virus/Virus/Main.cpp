#include <iostream>
#include "Virus.h"
#include "FluVirus.h"

using namespace std;

int main() {

	FluVirus *flu = new FluVirus();
	flu->DoBorn();
	system("pause");
	return 0;
}