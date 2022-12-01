#include <iostream>
#include <cstdlib>

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

	tree = new(TreeNode);
	if (tree) {
		tree->left = nullptr;
		tree->right = nullptr;
		tree->value = item;
	}
	return (tree);
}

TreeNode *init_tree() {
	TreeNode *tree;
	tree = new(TreeNode);
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
		return start;
	if (x < start->value) {
		cout << "left ";
		return t_search(start->left, x);
	}
	else {
		cout << "right ";
		return t_search(start->right, x);
	}
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

void t_clear(TreeNode *root)
{
	if (root != nullptr)
	{
		if (root->left)
			t_clear(root->left);
		if (root->right)
			t_clear(root->right);
		delete root;
	}
}

TreeNode *fullD(int nbr) {
	TreeNode *root = nullptr;
	srand(time(0));

	for (int i = 0; i < nbr; i++)
		root = t_addelement(root, random() % 10);
	return root;
}

void printTree(TreeNode *p, string str, string temp) {
	if (p != nullptr) {
		str.append(temp);
		cout << str << endl;
		cout << p->value << endl;
		printTree(p->left, str, "-left");
		printTree(p->right, str, "-right");
	}
}

int main() {
	int val = 8;
	TreeNode *first;

	cout << "checking add element and fullD" << endl;
	first = fullD(10);
	first = t_addelement(first, val);
	printTree(first, "root", "");
	cout << endl;

	cout << "find max by up_down" << endl;
	int x;
	Up_Down(first, &x);
	cout << "max by up_down is " << x << endl;
	cout << endl;

	cout << "find max by left_right" << endl;
	int y;
	Left_Right(first, &y);
	cout << "max by left_right is " << y << endl;
	cout << endl;

	cout << "find max by down_up" << endl;
	int z;
	Down_Up(first, &z);
	cout << "max by down_up is " << z << endl;
	cout << endl;

	cout << "checking search element: " << val << endl;
	TreeNode *temp = t_search(first, val);
	cout << endl;
	if (temp != nullptr) {
		cout << "we can find this element, he is " << temp->value << endl;
	}
	else
		cout << "there haven't this element" << endl;
	cout << endl;

//	cout << "checking delete element: " << val << endl;
//	temp = t_delelement(first, val);
//	if (temp != nullptr)
//		cout << "we can delete this element" << endl;
//	else
//		cout << "there haven't this element" << endl;
//	printTree(first, "root", "");
//	cout << endl;

	t_clear(first);

	return 0;
}
