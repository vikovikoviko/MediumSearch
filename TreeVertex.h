#pragma once
#include<iostream>
class TreeVertex
{
private:
	int value;
	int counter;//counting the current value frequency
	TreeVertex* left_son = nullptr;
	int left_son_counter;//counting childs to the left
	TreeVertex* right_son = nullptr;
	int right_son_counter;//counting childs to the right
	void deleteSons();//deletes pointers

	const TreeVertex& getMostRightChild()const;
	const TreeVertex& getMostLeftChild()const;

public:
	TreeVertex(int value = 0, int counter = 0);
	TreeVertex(const TreeVertex& other);
	TreeVertex& operator=(const TreeVertex& other);
	~TreeVertex();

	void add(int number);
	double returnMedian(int greater_above)const;//greater_above
	friend class BinaryTree;
};