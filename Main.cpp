#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <ctime>

#include "dice.h"
#include "binom.h"

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
	int y = 0;
	int k = 0;
	string p;
	string X;
	string Y;

	cout << "\tAvailable functions:\n\n\n";
	
	cout << " 1) Uppgift 1a: Omega (n, m)\n";
	cout << " 2) E (n, m)\n";
	cout << " 3) F (n, m)\n";
	cout << " 4) Section(E, F)\n";
	cout << " 5) Uppgift 1a: Probability\n";
	cout << " 6) Throw die\n";
	cout << " 7) Throw dice\n";
	cout << " 8) Uppgift 1b: Probability\n";
	cout << " 9) Uppgift 2a: Pascals triangle\n";
	cout << "10) Uppgift 2b: Binomial extension\n";
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
		Dice::Omega(n,m);
		Dice::printSet(Dice::E(n, m));
		break;

	case 3:
		n = inputN();
		m = inputM();
		cout << endl;
		Dice::Omega(n,m);
		Dice::printSet(Dice::F(n, m));
		break;

	case 4:
		n = inputN();
		m = inputM();
		cout << endl;
		Dice::Omega(n,m);
		Dice::printSet(Dice::section(Dice::E(n, m), Dice::F(n, m)));
		break;

	case 5:
		n = inputN();
		m = inputM();
		cout << endl;
		Dice::Omega(n,m);
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

	case 9:

		cout << "n: Ange rad: ";
		cin >> n;
		cout << "k: Ange element i raden: ";
		cin >> k;
		Binom::binom_pascal(n, k, 1);		// 1 = print triangle
		break;

	case 10:

		cout << "x: Koefficientvärde: ";
		cin >> x;
		cout << "Variabelnamn: ";
		cin >> X;
		cout << "y: Koefficientvärde: ";
		cin >> y;
		cout << "Variabelnamn: ";
		cin >> Y;
		cout << "n: Exponent: ";
		cin >> n;
		cout << "Binomialexpansion C(x, y, n): ";
		Binom::extension(x, X, y, Y, n);
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