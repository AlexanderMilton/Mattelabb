#include "dice.h"

vec2 Dice::omega;

void Dice::generate_seed()
{
	srand(time(NULL));
}

vec2& Dice::Omega(int n, int m)	//n = no throws, m = no sides
{
	omega.clear();
	cout << "Executing function Omega\n\n";

	vector <int> list;
	//vector < vector <int> > metalist;

	int permutations = pow(m, n);

	omega.reserve(permutations);

	cout << "Number of possible combinations = " << permutations << endl << endl;

	// For each loop, create a vector
	for (int i = 0; i < permutations; i++)
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

		// Put the vector in the vector-vector-reference
		omega.push_back(list);
	}
	
	// What's our vector, Victor?
	return omega;
}



vec2 Dice::E(int n, int m)
{
	cout << "Executing function E\n\n";
	
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

	vec2 metalist;

	for (int i = 0; i < omega.size(); i++)
	{
		//vector< int >& list = omega[i];
		bool lessThan = false;
		for (int j = 1; j < omega[i].size(); j++)
		{
			if (omega[i][j] < omega[i][j - 1])
			{	
				lessThan = true;
				break;
			}					
		}
		if (!lessThan)
		{
			metalist.push_back(omega[i]);
		}
	}
	return metalist;
}



void Dice::printSet(vec2 inputSet)
{
	cout << "InputSet: "<<inputSet.size() << endl;
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
	//sect.reserve(A.size()*A[0].size());

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
		
	vec2 e = E(n, m);
	vec2 f = F(n, m);
	vec2 s = section(e, f);

	cout << "P(E):   " << float(e.size()) / float(omega.size()) << endl;
	cout << "P(F):   " << float(f.size()) / float(omega.size()) << endl;
	cout << "P(E|F): " << float(s.size()) / float(f.size()) << endl;
}

int Dice::kasta_tarning(int m) // m sidor
{
	if (m < 2)
	{
		return NULL;
	}

	int value = rand() % m + 1;

	return value;
}

vector<int> Dice::kasta_tarningar(int n, int m)
{
	vector<int> values;
	for (int i = 0; i < n; i++)
	{
		values.push_back(kasta_tarning(m));
	}

	return values;
}

void Dice::oneBprobability(int n, int m, int x)
{
	vec2 values;
	for (int i = 0; i < x; i++)
	{
		vector<int> tempValues = kasta_tarningar(n, m);
		values.push_back(tempValues);
	}
	omega = values;
		
	cout << "E: " << E(n, m).size() << endl;
	int b = F(n, m).size();
	cout << "F: " << b << endl;
	int a = section(E(n, m), F(n, m)).size();

	if (b != 0)
	{

		float probability = (float) a / (float) b;

		cout << a << endl;
		cout << b << endl;

		cout << n << " " << m << "-sided dice " << "thrown " << x << " times\n gives P(E|F): " << probability << endl;
	}
	else
	{
		cout << a << endl;
		cout << b << endl;
		cout << "Don't divide by zero, stupid." << endl;
	}
}