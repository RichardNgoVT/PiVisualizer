// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <ostream>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <filesystem>
#include <sstream>
using namespace std;

int main()
{
	ifstream in("primenumbers.txt");
	ofstream out("primeratio.txt");
	ofstream out2("primevisual.txt");
	ofstream out3("primeexcel.txt");
	ofstream out4("primepattern.txt");
	int fourmult = 1;
	int fivemult = 1;
	
	int primeread;
	vector<int> prime;
	vector<int> vectorfour;
	vector<int> vectorfive;

	int past = 0;
	int pasti = 0;
	while (!in.fail())
	{
		in >> primeread;
		prime.push_back(primeread);
	}
	for (int i = 0; i < prime.size(); i++)
	{
		fourmult = 1;
		fivemult = 1;
		while (prime[i] > 5 * fivemult)
		{
			fivemult++;
		}
		while (fourmult * 4 + fivemult * 5 != prime[i])
		{
			fivemult--;
			fourmult = 1;
			while (fourmult * 4 + fivemult * 5 < prime[i])
			{
				fourmult++;
			}
		}
		vectorfour.push_back(fourmult);
		vectorfive.push_back(fivemult);
	}
	
	for (int i = 0; i < prime.size(); i++)
	{
		out2 << prime[i] << ": ";
		for (int j = 0; j < vectorfour[i]; j++)
		{
			out2 << 'O';
		}
		out2 << " | ";
		for (int j = 0; j < vectorfive[i]; j++)
		{
			out2 << 'O';
		}
		out2 << endl;

		out << prime[i] << ": " << vectorfour[i] << " | " << vectorfive[i] << endl;
		out3 << vectorfour[i] << endl;
		if (past == vectorfour[i])
		{
			out4 << i-pasti << endl;
			pasti = i;
		}
		past = vectorfour[i];
	}
    return 0;
}

