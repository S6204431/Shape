#include<iostream>

#include "CShape.h"

using namespace std;

int main() {

	
	Shape sA(0,0,10,5);
	Shape sB(0,16,3,7);
	Shape sC = sA;
	
	sA.SetText("sono shape A");
	
	cout << endl;
	cout << "fase 1" << endl;
	cout << endl;


	sA.Dump();
	sB.Dump();
	sC.Dump();
	
	if (sA == sB)
		cout << "shape A e shape B sono uguali" << endl;
	else 
		cout << "shape A e shape B sono diversi" << endl;
	if (sA == sC)
		cout << "shape A e shape C sono uguali" << endl;
	else 
		cout << "shape A e shape C sono diversi" << endl;
	
	cout << endl;
	cout << "fase 2" << endl;
	cout << endl;
	
	sC = sB; 
	if (sA == sC)
		cout << "shape A e shape C sono uguali" << endl;
	else 
		cout << "shape A e shape C sono diversi" << endl;
	sA.Dump();
	sC.Dump();
	
	return 0;

}