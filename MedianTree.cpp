#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "BinaryTree.h"

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define PROBABILITY_OF_RETURNING_MEDIAN 5 //1 in X chance of returning the median
int main()
{

	vector<int> data2;

	/* initialize random seed: */
	srand(time(NULL));

	BinaryTree data;

	cout << "Input number N and limit L:\nN - number of operations\nL - range of numbers added\n";
	unsigned int N, L;
	cin >> N >> L;
	for (unsigned int i = 0;i < N;i++)
	{
		bool is_new_number = rand() % PROBABILITY_OF_RETURNING_MEDIAN;//false (0) - return median, true(1,2,3) - add new number
		if (!is_new_number)
		{
			cout << "The median is:";
			cout << data.returnMedian();
			cout << endl;
			sort(data2.begin(), data2.end());
			for (int k = 0;k < data2.size();k++)
			{
				if (k == data2.size() / 2)cout << "|";
				if (k == (data2.size()+1) / 2)cout << "|";
				
				cout << data2[k] << " ";
			}
			cout << endl;
		}
		else
		{
			int number_to_add = rand() % (2 * L + 1) - L;//generats random number between -L and L
			cout << "New number to the data: " << number_to_add << endl;
			data.add(number_to_add);
			data2.push_back(number_to_add);
		}
	}
	return 0;
}