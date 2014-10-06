#include "dice.h"

vec2 Dice::omega;

void Dice::generate_seed()
{
	srand(time(NULL));
}

vec2& Dice::Omega(int n, int m)	//n = no throws, m = no sides
{

	cout << "Executing function Omega\n\n";

	vector <int> list;
	//vector < vector <int> > metalist;

	int combinations = pow(m, n);
	cout << "Number of possible combinations = " << combinations << endl << endl;

	// For each loop, create a vector
	for (int i = 0; i < combinations; i++)
	{
		// Clear list
		list.clear();

		// For each loop fill a vector
		for (int j = n - 1; j >= 0; j--)
		{
			int power = pow(m, j);

			// Det nya elementet f�s av en formel beroende p� antalet sidor,
			// dess position i arrayen samt antalet element arrayen h�ller 
			int newElement = ((i / power) % m) + 1;
			list.push_back(newElement);

		}

		// Put the vector in the vector-vector-reference
		omega.push_back(list);
	}
	
	// What's our vector, Victor?
	return omega;
}



vec2 Dice::E(int n, int m)
{
	cout << "Executing function E\n\n";

	/*vector <int> list;
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

			// Det nya elementet f�s av en formel beroende p� antalet sidor,
			// dess position i arrayen samt antalet element arrayen h�ller 
			int newElement = ((i / power) % m) + 1;
			list.push_back(newElement);
		}*/
	vec2 metalist;

	for (int i = 0; i < omega.size(); i++)
	{
		vector< int >& list = omega[i];
		bool allValues = true;
		for (int die = 1; die <= m; die++)
		{
			bool exists = false;
			for (int k = 0; k < list.size(); k++)
			{
				if (list[k] == die)
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

vec2 Dice::F(int n, int m)
{
	cout << "Executing function F\n\n";

	/*vector <int> list;
	vec2 metalist;

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

			// Det nya elementet f�s av en formel beroende p� antalet sidor,
			// dess position i arrayen samt antalet element arrayen h�ller 
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
	}*/

	vec2 metalist;

	for (int i = 0; i < omega.size(); i++)
	{
		vector< int >& list = omega[i];

		for (int j = 1; j < list.size(); j++)
		{
			if (list[j] >= list[j - 1])
			{
				metalist.push_back(list);
			}
			else
			{
				break;
			}
		}
	}
	return metalist;
}



void Dice::printSet(vec2& inputSet)
{

	for (int i = 0; i < inputSet.size(); i++)
	{

		vector <int> list = inputSet[i];

		for (int j = 0; j < list.size(); j++)
		{
			cout << list[j] << ", ";
		}
		cout << endl;
	}
}


vec2 Dice::section(vec2& A, vec2& B)
{

	cout << "Executing function Section\n\n";

	vec2 sect;
	sect.reserve(A.size()*A[0].size());

	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++)
		{
			if (A[i] == B[j])
			{
				sect.push_back(A[i]);
				break;
			}
		}
	}

	return sect;
}

void Dice::probability(int n, int m)
{
	cout << "Executing function Probability\n\n";

	vec2 o = Omega(n, m);
	vec2 e = E(n, m);
	vec2 f = F(n, m);
	vec2 s = section(e, f);

	cout << "P(E):   " << float(e.size()) / float(o.size()) << endl;
	cout << "P(F):   " << float(f.size()) / float(o.size()) << endl;
	cout << "P(E|F): " << float(s.size()) / float(f.size()) << endl;
}

int Dice::kasta_tarning(int m) // m sidor
{
	if (m < 2)
	{
		return NULL;
	}

	int value = rand() % m + 1;

	cout << value << ", ";

	return value;
}

vector<int> Dice::kasta_tarning(int n, int m)
{
	vector<int> values;
	for (int i = 0; i < n; i++)
	{
		values.push_back(kasta_tarning(m));
	}

	cout << endl;

	return values;
}

void Dice::oneBprobability(int n, int m, int x)
{
	vec2 values;
	for (int i = 0; i < x; i++)
	{
		vector<int> tempValues = kasta_tarning(n, m);
		values.push_back(tempValues);
	}

	int b = section(values, F(n, m)).size();
	int a = section(values, section(E(n, m), F(n, m))).size();

	if (b != 0)
	{

		float probability = (float) a / (float) b;

		cout << a << endl;
		cout << b << endl;

		cout << n << " " << m << "-sided dice " << " thrown " << x << " times\n gives P(E|F): " << probability << endl;
	}
	else
	{
		cout << "Don't divide by zero, stupid." << endl;
	}
}