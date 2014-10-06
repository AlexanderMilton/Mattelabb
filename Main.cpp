#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <ctime>

#include "dice.h"

using namespace std;

int inputN()	// Number of dice/throws
{
	int n = 0;
	cout << "Number of dice/throws: ";
	cin >> n;
	return n;
}

int inputM()	// Number of sides on the die
{
	int m = 0;
	cout << "Number of die sides: ";
	cin >> m;
	return m;
}

int inputX()	// Number of experimental iterations
{
	int x = 0;
	cout << "Number of experiments: ";
	cin >> x;
	return x;
}

int main()
{

Reset:

	Dice::generate_seed();

	int input = 0;
	int n = 0;
	int m = 0;
	int x = 0;

	cout << "\tAvailable functions:\n\n\n";

	cout << "n = number of dice throws\nm = number of sides\n\n"; 
	cout << "1) Omega (n, m)\n";
	cout << "2) E (n, m)\n";
	cout << "3) F (n, m)\n";
	cout << "4) Section(E, F)\n";
	cout << "5) Uppgift 1a: probability\n";
	cout << "6) Throw die\n";
	cout << "7) Throw dice\n";
	cout << "8) Uppgift 1b: probability\n";
	cout << endl << endl;

	cin >> input;


	cout << endl;

	switch (input)
	{
	case 1:
		n = inputN();
		m = inputM();
		cout << endl;
		Dice::printSet(Dice::Omega(n, m));
		break;
	
	case 2:
		n = inputN();
		m = inputM();
		cout << endl;
		Dice::printSet(Dice::E(n, m));
		break;

	case 3:
		n = inputN();
		m = inputM();
		cout << endl;
		Dice::printSet(Dice::F(n, m));
		break;

	case 4:
		n = inputN();
		m = inputM();
		cout << endl;
		Dice::printSet(Dice::section(Dice::E(n, m), Dice::F(n, m)));
		break;

	case 5:
		n = inputN();
		m = inputM();
		cout << endl;
		Dice::probability(n, m);
		break;

	case 6:
		m = inputM();
		cout << endl;
		Dice::kasta_tarning(m);
		break;

	case 7:
		n = inputN();
		m = inputM();
		cout << endl;
		Dice::kasta_tarning(n, m);
		break;

	case 8:
		n = inputN();
		m = inputM();
		x = inputX();
		cout << endl;
		Dice::oneBprobability(n, m, x);
		break;

	default:
		goto Reset;
		break;
	}

	cout << "\n\n";
	system("PAUSE");

	system("CLS");
	goto Reset;

	system("PAUSE");
	return 0;
}