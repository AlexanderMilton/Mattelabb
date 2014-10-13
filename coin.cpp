#include "coin.h"



void Coin::generate_seed()
{
	srand(time(NULL));
}

int Coin::kasta_mynt(float p)
{
	assert(p >= 0 && p <= 1);

	int result = 0;

	int probability = p * 1000;

	result = rand() % 1000;
	
	assert(result >= 0 && result < 1000);

	if (result < probability)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Coin::experiment(int n, int k, float p)
{
	int  count = 0;
	for (int i = 0; i < n; i++)
	{
		count += kasta_mynt(p);
	}
	return (count == k);
}

void Coin::print_experiment( int n, float p)
{
	int x = 100000000;
	
	for (int k = 0; k <= n; k++)
	{
		int h = 0;
		for (int i = 0; i < x; i++)
		{
			if (experiment( n, k, p))
			{
				h++;
			}
		}
		cout << "k: " << k << " h/x: " << (float)h/(float)x  << endl;
	}
}