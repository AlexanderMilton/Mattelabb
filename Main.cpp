#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector <vector <int>> Omega(int n, int m)	//n = no throws, m = no sides
{

	cout << "Executing function Omega\n\n";

	vector <int> list;
	vector < vector <int> > metalist;

	int combinations = pow(m, n);
	cout << "Number of possible combinations = " << combinations << endl << endl;

	// For each loop, create a vector
	for (int i = 0; i < combinations; i++)
	{
		// Clear list
		list.clear();

		// For each loop fill a vector
		for (int j = n-1; j >= 0; j--)
		{
			int power = pow(m, j);

			// Det nya elementet fås av en formel beroende på antalet sidor,
			// dess position i arrayen samt antalet element arrayen håller 
			int newElement = ((i / power) % m) + 1;
			list.push_back(newElement);
			
		}

		// Put the vector in the vector-vector
		metalist.push_back(list);
	}

	// What's our vector, Victor?
	return metalist;
}



vector <vector <int>> E(int n, int m)
{
	cout << "Executing function E\n\n";

	vector <int> list;
	vector < vector <int> > metalist;

	int combinations = pow(m, n);

	// For each loop, create a vector
	for (int i = 0; i < combinations; i++)
	{
		// Clear list
		list.clear();

		// For each loop fill a vector
		for (int j = n - 1; j >= 0; j--)
		{
			int power = pow(m, j);

			// Det nya elementet fås av en formel beroende på antalet sidor,
			// dess position i arrayen samt antalet element arrayen håller 
			int newElement = ((i / power) % m) + 1;
			list.push_back(newElement);
		}

		bool allValues = true;
		for (int die = 1; die <= m; die++)
		{
			bool exists = false;
			for (int k = 0; k < list.size(); k++)
			{
				if (list.at(k) == die)
				{
					exists = true;
				}				
			}
			if (exists == false)
			{
				allValues = false;
				break;
			}
		}
		if (allValues == true)
		{
			metalist.push_back(list);
		}
	}
	return metalist;
}

vector <vector <int>> F(int n, int m)
{
	cout << "Executing function F\n\n";

	vector <int> list;
	vector < vector <int> > metalist;

	int combinations = pow(m, n);

	// For each loop, create a vector
	for (int i = 0; i < combinations; i++)
	{
		// Clear list
		list.clear();
		int previousElement = 0;
		// For each loop fill a vector
		for (int j = n - 1; j >= 0; j--)
		{
			int power = pow(m, j);

			// Det nya elementet fås av en formel beroende på antalet sidor,
			// dess position i arrayen samt antalet element arrayen håller 
			int newElement = ((i / power) % m) + 1;
			if (newElement >= previousElement)
			{
				list.push_back(newElement);
				previousElement = newElement;
			}
			else
			{
				break;
			}
		}
		if (list.size() == n)
		{
			metalist.push_back(list);
		}
	}
	return metalist;
}



void printSet(vector < vector< int >> inputSet)
{

	for (int i = 0; i < inputSet.size(); i++)
	{

		vector <int> list = inputSet.at(i);

		for (int j = 0; j < list.size(); j++)
		{
			cout << list.at(j) << ", ";
		}
		cout << endl;
	}
}


vector< vector< int >> section(vector< vector< int >> A, vector< vector< int >> B)
{

	cout << "Executing function Section\n\n";

	vector< vector< int >> sect;

	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++)
		{
			if (A.at(i) == B.at(j))
			{
				sect.push_back(A.at(i));
				break;
			}
		}
	}

	return sect;
}

void probability(int n, int m)
{
	cout << "Executing function Probability\n\n";

	vector <vector <int>> o = Omega(n, m);
	vector <vector <int>> e = E(n, m);
	vector <vector <int>> f = F(n, m);
	vector <vector <int>> s = section(e, f);

	cout << "P(E): "	<< float (e.size()) / float (o.size()) << endl;
	cout << "P(F): "	<< float(f.size()) / float (o.size()) << endl;
	cout << "P(E|F): "	<< float(s.size()) / float (f.size()) << endl;
}

int main()
{

Reset:

	cin.get();

	int input = 0;
	int n = 0;
	int m = 0;

	cout << "\tAvailable functions:\n\n\n";

	cout << "n = number of die throws\nm = number of sides\n\n"; 
	cout << "1) Omega (n, m)\n";
	cout << "2) E (n, m)\n";
	cout << "3) F (n, m)\n";
	cout << "4) Section(E, F)\n";
	cout << "5) Probability of EVERYTHING\n";
	cout << endl << endl;

	cin >> input;

	cout << "\nEnter the number of dice: ";
	cin >> n;

	cout << "Enter the number of sides of the dice: ";
	cin >> m;

	cout << endl;

	switch (input)
	{
	case 1:
		printSet(Omega(n, m));
		break;
	
	case 2:
		printSet(E(n, m));
		break;

	case 3:
		printSet(F(n, m));
		break;

	case 4:
		printSet(section(E(n, m), F(n, m)));
		break;

	case 5:
		probability(n, m);
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