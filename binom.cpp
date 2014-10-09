#include "binom.h"

int Binom::binom_pascal(int n, int k, bool p)
{
	if (k > n)
	{
		return 0;
	}

	vector<vector<int>*> pascalVector;

	
	for (int i = 0; i <= n; i++)	// raden
	{
		vector<int>* v= new vector<int>();
	
		for (int j = 0; j <= i; j++)	// elementet i raden
		{
			if (j == 0 || j == i)
			{
				v->push_back(1);
				
				if(p) cout << "1 ";
				
			}
			else
			{
				int firstValue = pascalVector.at(i - 1)->at(j - 1);
				int secondValue = pascalVector.at(i - 1)->at(j);
				if(p) cout << firstValue + secondValue <<" ";
				v->push_back(firstValue+secondValue);
			}
		}		
		pascalVector.push_back(v);
		if(p) cout << endl;
	}
	

	return pascalVector.at(n)->at(k);
}

void Binom::extension(int kx, string x, int ky, string y, int n)
{
	for (int i = 0; i <= n; i++)
	{
		int k = binom_pascal(n, i, 0);
		if (n - i != 0) k *= pow(kx, n);
		if (i != 0) k *= pow(ky, n - i);

		if (k > 1) cout << k;
		if ((n -i) != 1)
		{
			if ((n - i) != 0) cout << "(" << x << ")^" << n - i;
		}
		else
		{
			cout << x;
		}
		if (i != 1)
		{
			if (i != 0) cout << " (" << y << ")^" << i;
		}
		else
		{
			cout << y;
		}

		if (i != n)
		{
			cout << " + ";
		}
	}
}