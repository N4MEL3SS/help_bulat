#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct Tr {
	int value;
	struct Tr *left, *right;
} TreeNode;

void Up_Down(TreeNode *pos, int *max) {
	if (!pos)
		return ;
	if (*max < pos->value)
		*max = pos->value;
	Up_Down(pos->left, max);
	Up_Down(pos->right, max);
}

void Left_Right(TreeNode *pos, int *max) {
	if (!pos)
		return ;
	Left_Right(pos->left, max);
	if (*max < pos->value) {
		*max = pos->value;
	}
	Left_Right(pos->right, max);
}

void Down_Up(TreeNode *pos, int *max) {
	if (!pos)
		return ;
	Down_Up(pos->left, max);
	Down_Up(pos->right, max);
	if (*max < pos->value)
		*max = pos->value;
}

TreeNode *create_node(int item) {
	TreeNode *tree;

	tree = new TreeNode;
	if (tree) {
		tree->left = nullptr;
		tree->right = nullptr;
		tree->value = item;
	}
	return (tree);
}

TreeNode *init_tree() {
	TreeNode *tree;
	tree = new TreeNode;
	if (tree) {
		tree->left = nullptr;
		tree->right = nullptr;
	}
	return (tree);
}

TreeNode *t_search(TreeNode *start, int x) {
	if (!start)
		return nullptr;
	if (x == start->value)
		return nullptr;
	if (x < start->value)
		return t_search(start->left, x);
	else
		return t_search(start->right, x);
}

TreeNode *t_addelement(TreeNode *root, int x) {
	TreeNode *pos;

	if (!root) {
		root = init_tree();
		if (root) {
			root->value = x;
			root->left = root->right = nullptr;
		}
	}
	else {
		if (x < root->value) {
			pos = t_addelement(root->left, x);
			if (pos)
				root->left = pos;
			else
				return nullptr;
		}
		else {
			pos = t_addelement(root->right, x);
			if (pos)
				root->right = pos;
			else
				return nullptr;
		}
	}
	return root;
}

TreeNode *t_delelement(TreeNode *root, int x) {
	TreeNode *pos;

	if (!root)
		return nullptr;
	else if (x == root->value) {
		if (!root->left)
			return root->right;
		else if (!root->right)
			return root->left;
		for (pos = root->left; pos->right; )
			pos = pos->right;
		root->value = pos->value;
		root->left = t_delelement(root->left, pos->value);
	}
	else {
		if (x < root->value)
			root->left = t_delelement(root->left, x);
		else
			root->right = t_delelement(root->right, x);
	}
	return root;
}

TreeNode *fullD(int nbr) {
	TreeNode *root = nullptr;

	for (int i = 0; i < nbr; i++)
		root = t_addelement(root, rand() % 10);
	return root;
}

void printTree(TreeNode *p, string str, int i) {
	if (p != nullptr) {
		cout << str << endl;
		cout << p->value << endl;
		if (p->left)
		{
			str.append("-left");
			printTree(p->left, str, i);
		}
		if (i == 0)
		{
			str.clear();
			str.append("root");
			i++;
		}
		if (p->right)
		{
			str.append("-right");
			printTree(p->right, str, i);
		}
	}
}

int main() {
	TreeNode *first = nullptr;

	cout << "checking add element and fullD" << endl;
	first = fullD(8);
	printTree(first, "root", 0);
	return 0;
}
