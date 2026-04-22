#include<iostream>

#include "CShape.h"
#include "CRombo.h"
#include "CParal.h"

using namespace std;

int main() {

	Shape sA(0,0,10,5);
	Paral reB(0,16,3,7);
	Rombo roC;

	sA.Dump();
	reB.Dump();
	roC.Dump();

	reB.SetText("Sono un rettangolo");
	reB.Dump();

	Rombo roD(19,27,3,7);
	if(roD.GetBoundingBoxArea() == reB.GetBoundingBoxArea())
	{
		cout << "sono uguali" << endl;
	}

	return 0;

}