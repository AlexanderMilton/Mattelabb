#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <ctime>

#include "dice.h"

using namespace std;



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
	cout << "8) Uppgift 1b: probability\n";
	cout << endl << endl;

	cin >> input;

	cout << "\nEnter the number of dice throws: ";
	cin >> n;

	cout << "Enter the number of sides of the dice: ";
	cin >> m;

	cout << endl;

	switch (input)
	{
	case 1:
		Dice::printSet(Dice::Omega(n, m));
		break;
	
	case 2:
		Dice::printSet(Dice::E(n, m));
		break;

	case 3:
		Dice::printSet(Dice::F(n, m));
		break;

	case 4:
		Dice::printSet(Dice::section(Dice::E(n, m), Dice::F(n, m)));
		break;

	case 5:
		Dice::probability(n, m);
		break;

	case 6:
		Dice::kasta_tarning(m);
		break;

	case 7: 
		Dice::kasta_tarning(n, m);
		break;

	case 8:
		cout << "Number of experiments: ";
		cin >> x;
		Dice::oneBprobability(n, m, x);
		break;

	default:
		goto Reset;
		break;
	}

	cout << "\n\n";
	cin.get();
	cin.get();

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
	goto Reset;

	system("PAUSE");
	return 0;
}