#ifndef _DICE_
#define _DICE_

#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <ctime>

using namespace std;

typedef vector<vector<int>> vec2;

class Dice
{
public:
	static void generate_seed();

	static vec2& Omega(int n, int m);
	static vec2 E(int n, int m);
	static vec2 F(int n, int m);
	static void printSet(vec2 a);
	static vec2 section(vec2& a, vec2& b);
	static void probability(int n, int m);
	
	static int kasta_tarning(int m);
	static vector<int> kasta_tarning(int n, int m);
	
	static void oneBprobability(int n, int m, int x);

private:
	 static vec2 omega;

};
	

#endif // _DICE_
