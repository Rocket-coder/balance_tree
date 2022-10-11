#pragma once
#include <string>
#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

class tree
{

private:

	int key; 
	tree* left;
	tree* right;
	int balance;

	int Height(tree* root);

	void SetBalance(tree* (&root));

	void TurnLeft(tree* (&root));

	void TurnRight(tree* (&root));

public:

	tree();

	void Insert(tree* (&root), int d);

	void Output(tree* p);

	void Print(tree* p);

	void Clear(tree** p);
};

