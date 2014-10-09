#ifndef _BINOM_
#define _BINOM_

#include <iostream>
#include <math.h>
#include <vector>
#include <memory>
#include <string>

using namespace std;

typedef vector<int> littlePascalVector;

class Binom
{
public:
	static int binom_pascal(int n, int k, bool p);
	static void extension(int kx, string x, int ky, string y, int n);

};

#endif	// _BINOM_