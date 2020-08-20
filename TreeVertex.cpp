#include "TreeVertex.h"

void TreeVertex::deleteSons()
{
	delete left_son;
	delete right_son;
}

const TreeVertex& TreeVertex::getMostRightChild() const
{
	if (!right_son)
	{
		return *this;
	}
	return right_son->getMostRightChild();
}

const TreeVertex& TreeVertex::getMostLeftChild() const
{
	if (!left_son)
	{
		return *this;
	}
	return left_son->getMostLeftChild();
}

TreeVertex::TreeVertex(int value, int counter)
	:value(value), counter(counter), left_son_counter(0), right_son_counter(0)
{
}

TreeVertex::TreeVertex(const TreeVertex& other)
{
	this->value = other.value;
	this->counter = other.counter;
	this->left_son = new TreeVertex(*other.left_son);
	this->left_son_counter = other.left_son_counter;
	this->right_son = new TreeVertex(*other.right_son);
	this->right_son_counter = other.right_son_counter;
}

TreeVertex& TreeVertex::operator=(const TreeVertex& other)
{
	if (this != &other)
	{
		this->value = other.value;
		this->counter = other.counter;
		deleteSons();
		this->left_son = new TreeVertex(*other.left_son);
		this->left_son_counter = other.left_son_counter;
		this->right_son = new TreeVertex(*other.right_son);
		this->right_son_counter = other.right_son_counter;
	}
	return *this;
}

TreeVertex::~TreeVertex()
{
	deleteSons();
}

void TreeVertex::add(int number)
{
	if (counter == 0)//new leaf
	{
		counter = 1;
		value = number;
		return;
	}
	if (value == number)
	{
		counter++;
		return;
	}
	if (value < number)
	{
		this->right_son_counter++;
		if (right_son == nullptr)
		{
			right_son = new TreeVertex();
		}
		right_son->add(number);
		return;
	}
	
	if (number < value)
	{
		this->left_son_counter++;
		if (left_son == nullptr)
		{
			left_son = new TreeVertex();
		}
		left_son->add(number);
		return;
	}
}

double TreeVertex::returnMedian(int greater_above) const
{
	if (counter == 0)
	{
		return 0;
	}

	if (left_son_counter < counter + right_son_counter + greater_above
		and right_son_counter + greater_above < counter + left_son_counter)
	{
		return value;
	}

	if (left_son_counter > counter + right_son_counter + greater_above)
	{
		return left_son->returnMedian(greater_above + counter + right_son_counter);
	}
	if (right_son_counter + greater_above > counter + left_son_counter)
	{
		return right_son->returnMedian(greater_above - counter - left_son_counter);
	}

	if (left_son_counter == counter + right_son_counter + greater_above)
	{
		return double((double)left_son->getMostRightChild().value+ (double)value) / 2;
	}
	if (right_son_counter + greater_above == counter + left_son_counter)
	{
		return double((double)right_son->getMostLeftChild().value + (double)value) / 2;
	}

}