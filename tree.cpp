#include "tree.h"

tree::tree() {
	key = -1;
	left = right = 0;
	balance = 1;
}
	
int tree::Height(tree* root) {
	if (root == NULL) return 0;
	int hLeft = Height(root->left),
		hRight = Height(root->right);
	if (hLeft > hRight) return hLeft + 1;
	else
		return hRight + 1;
}

void tree::SetBalance(tree* (&root)) {
	if (root != NULL)
		root->balance = Height(root->right) - Height(root->left);
}

void tree::TurnLeft(tree* (&root)) {
	tree* rightSubtree, * rightSubtreeLeftSubtree;
	rightSubtree = root->right;
	rightSubtreeLeftSubtree = rightSubtree->left;

	rightSubtree->left = root;
	root->right = rightSubtreeLeftSubtree;
	root = rightSubtree;
	SetBalance(root->left);
	SetBalance(root);
}

void tree::TurnRight(tree* (&root)) {
	tree* leftSubtree, * leftSubtreeRightSubtree;
	leftSubtree = root->left;
	leftSubtreeRightSubtree = leftSubtree->right;

	leftSubtree->right = root;
	root->left = leftSubtreeRightSubtree;
	root = leftSubtree;
	SetBalance(root->right);
	SetBalance(root);

}

void tree::Insert(tree* (&root), int d) {
	if (root == NULL) {
		root = new tree;
		root->key = d;
		root->balance = 0;
		root->left = NULL;
		root->right = NULL;
	}
	else {
		if (d > root->key) {
			Insert(root->right, d);
			if (Height(root->right) - Height(root->left) > 1) {
				if (Height(root->right->right) < Height(root->right->left))
					TurnRight(root->right);
				TurnLeft(root);
			}
		}
		else
			if (d < root->key) {
				Insert(root->left, d);
				if(Height(root->left) - Height(root->right) > 1) {
					if (Height(root->left->left) < Height(root->left->right))
						TurnLeft(root->left);
					TurnRight(root);
				}
			}
		SetBalance(root);
	}
}

void tree::Output(tree* p) {
	if (p != NULL) {
		Output(p->left);
		cout << p->key << " ";
		Output(p->right);
	}
}


void tree::Print(tree* p) {
	cout << endl;
	cout << "Распечатка дерева в симметрическом порядке: " << endl;
	for (int k = 1; k <= 95; k++) {
		cout << "-";
	}
	cout << endl;
	p->Output(p);
	cout << endl;
	for (int k = 1; k <= 95; k++) {
		cout << "-";
	}
	cout << endl;
}


void tree::Clear(tree** p) {
	if ((*p) != NULL) {
		Clear(&(*p)->left);
		Clear(&(*p)->right);

		delete* p;
		*p = NULL;

	}
}