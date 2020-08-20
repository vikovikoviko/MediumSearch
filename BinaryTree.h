#pragma once
#include <vector>
#include "TreeVertex.h"
using namespace std;
class BinaryTree
{
private:
	TreeVertex root = TreeVertex();
public:
	void add(int number);
	double returnMedian()const;
};