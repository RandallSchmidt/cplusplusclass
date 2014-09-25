// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <utility>  // make_pair, pair
#include <cmath>

using namespace std;

std::pair<int, int> collatz_read(std::istream& r)
{
	int i;
	r >> i;
	if (!r)
		return std::make_pair(0, 0);
	int j;
	r >> j;
	return std::make_pair(i, j);
}

int cycleLength(int n)
{
	assert(n > 0);
	int c = 1;
	while (n > 1)
	{
		if ((n % 2) == 0)
			n = (n / 2);
		else
			n = (3 * n) + 1;
		++c;
	}
	assert(c > 0);
	return c;
}

int collatz_eval(int i, int j)
{
	int maximum_value = 0;

	for (int number = i; number <= j; number++)
	{
		int cycle_length = cycleLength(number);
		
		if (cycle_length > maximum_value)
		{
			maximum_value = cycle_length;
		}
	}

	return maximum_value;
}


void collatz_print(std::ostream& w, int i, int j, int v)
{
	w << i << " " << j << " " << v << std::endl;
}

void collatz_solve(std::istream& r, std::ostream& w)
{
	while (true) {
		const std::pair<int, int> p = collatz_read(r);
		if (p == std::make_pair(0, 0))
			return;
		const int i = p.first;
		const int j = p.second;
		const int v = collatz_eval(i, j);
		collatz_print(w, i, j, v);
	}
}

int main()
{
	collatz_solve(cin, cout);
	return 0;
}