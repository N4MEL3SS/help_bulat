#include <iostream>

using namespace std;

typedef struct Tr {
	int value;
	struct Tr *left, *right;
} TreeNode;

void printTree(TreeNode *p, string str, const string& temp) {
	if (p != nullptr) {
		str.append(temp);
		cout << str << endl;
		cout << p->value << endl;
		printTree(p->left, str, "-left");
		printTree(p->right, str, "-right");
	}
}

void t_clear(TreeNode *root)
{
	if (root != nullptr) {
		if (root->left)
			t_clear(root->left);
		if (root->right)
			t_clear(root->right);
		delete root;
	}
}

TreeNode *create_elem(int x) {
	TreeNode *tree = new TreeNode;
	tree->value = x;
	tree->left = nullptr;
	tree->right = nullptr;
	return (tree);
}

int main() {
	int count, number, height = 0, kol;
	TreeNode *root = nullptr, *current = nullptr;
	cout << "please enter number of elements" << endl;
	cin >> count;
	if (count < 1) {
		cout << "the number is 0 or negative" << endl;
		return 1;
	}
	cout << "please enter element" << endl;
	cin >> number;
	root = create_elem(number);
	++height;
	for (int i = 1; i < count; i++) {
		cout << "please enter next element" << endl;
		cin >> number;
		number = rand() % 100;
		kol = 1;
		current = root;
		while(true) {
			if (number < current->value) {
				if (current->left == nullptr) {
					current->left = create_elem(number);
					kol++;
					break;
				} else {
					current = current->left;
					kol++;
				}
			}
			else {
				if (current->right == nullptr) {
					current->right = create_elem(number);
					kol++;
					break;
				}
				else {
					current = current->right;
					kol++;
				}
			}
		}
		if (kol > height)
			height = kol;
	}
	cout << endl;
	printTree(root, "root", "");
	cout << endl;
	cout << "height of wood is " << height << endl;
	t_clear(root);
	return 0;
}