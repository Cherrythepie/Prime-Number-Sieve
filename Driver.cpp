#include <iostream>
#include <fstream>
#include <cctype>

#define datatype int

using namespace std;

struct PrimeNodeType
{
	datatype primeNum;

	datatype primeNumCounter;

	PrimeNodeType *next, *previous;

	PrimeNodeType()
	{
		primeNum = 0;
		primeNumCounter = 0;
		next = previous = false;
	}
};


void incrementAllPrimeCounters(datatype incrementAmount, PrimeNodeType &primeLL);
bool checkForPrime(PrimeNodeType &primeLL, datatype &primeNum);

int main()
{
	datatype num = 3;

	PrimeNodeType primeLL, *current = &primeLL;
	
	primeLL.primeNum = 3;

	while (num < 100000)
	{
		num += 2;

		incrementAllPrimeCounters(2, primeLL);
		if (checkForPrime(primeLL, num) == true)
		{
			PrimeNodeType *newPrime = new(PrimeNodeType);
			current->next = newPrime;
			newPrime->previous = current;

			newPrime->primeNum = num;

			current = current->next;
		}

	}

	current = &primeLL;

	ofstream outputFile;
	outputFile.open("foundPrimes.txt");

	int count = 1;
	outputFile << 2 << " ";

	while (current != NULL)
	{
		outputFile << current->primeNum << " ";
		current = current->next;

		count++;
		if (count == 10)
		{
			count = 0;
			outputFile << endl;
		}
	}

	outputFile.close();
	return 0;
}

void incrementAllPrimeCounters(datatype incrementAmount, PrimeNodeType &primeLL)
{
	PrimeNodeType *current = &primeLL;

	while (current != NULL)
	{
		current->primeNumCounter += incrementAmount;

		if (current->primeNumCounter == current->primeNum * 2)
			current->primeNumCounter = 0;

		current = current->next;
	}
}

bool checkForPrime(PrimeNodeType &primeLL, datatype &primeNum)
{
	PrimeNodeType *current = &primeLL;

//	if (primeNum % 5 == 0)
//		return false;

	while (current != NULL)
	{
		if (current->primeNumCounter == 0)
			return false;

		current = current->next;
	}

	return true;
}