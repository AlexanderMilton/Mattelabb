#ifndef _COIN_
#define _COIN_

#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <cassert>

using namespace std;

class Coin
{
public:
	static void generate_seed();
	static int kasta_mynt(float p);
	static bool experiment(int n, int k, float p);
	static void print_experiment(int n, float p);
};


#endif	//_COIN_