#include "BinaryTree.h"

void BinaryTree::add(int number)
{
	root.add(number);
}

double BinaryTree::returnMedian() const
{
	return root.returnMedian(0);
}