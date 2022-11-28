#include <iostream>

#define DEF 20

using namespace std;

class Deque
{
private:
	int	*val, head, tail, size, occ;
public:
	Deque() {
		val = new int[DEF];
		head = occ = 0;
		size = DEF;
		tail = head + 1;
		if (size == 1)
			tail = head;
	}

	Deque(int x) {
		if (x >= 0)
		{
			val = new int[x];
			size = x;
			head = occ = 0;
			tail = head + 1;
			if (x < 2)
				tail = head;
		}
		else
		{
			cout << "Error" << endl;
		}
	}

	~Deque() {
		if (val)
			delete[] val;
	}

	Deque(const Deque &other)
	{
		head = other.head;
		tail = other.tail;
		size = other.size;
		occ = other.occ;
		if (other.val) {
			val = new int[size];
			for (int i = head + 1; i < head + 1 + occ; i++)
				val[i % size] = other.val[i % size];
		}
	}

	Deque& operator=(const Deque& other)
	{
		int* temp;

		size = other.size;
		head = other.head;
		tail = other.tail;
		occ = other.occ;
		if (other.val) {
			temp = new int[size];
			for (int i = head + 1; i < head + 1 + occ; i++)
				temp[i % size] = other.val[i % size];
			}
		delete []val;
		val = temp;
		return *this;
	}

	Deque operator+(const Deque& Y)
	{
		Deque Z(size + Y.size);

		for (int i = 0; i < occ; i++)
			Z.val[i] = val[(head + 1 + i) % size];
		for (int i = occ; i < Y.occ + occ; i++)
			Z.val[i] = Y.val[(Y.head + 1 + i - occ) % Y.size];
		Z.occ = occ + Y.occ;
		Z.head = Z.size - 1;
		Z.tail = Z.occ % size;
		return Z;
	}

	int *GetVal() { return val; }
	int GetVal_i(int i) { return val[i]; }
	int GetSize() const { return size; }
	int GetHead() const { return head; }
	int GetOcc() const { return occ; }
	int GetTail() const { return tail; }

	int PushTail(int var) {
		if (occ < size) {
			val[tail++] = var;
			if (tail == size)
				tail = 0;
			++occ;
			return 0;
		}
		cout << "haven't free places" << endl;
		return -1;
	}

	int PopHead(int* var) {
		if (occ > 0) {
			if (head == size - 1)
				head = 0;
			else
				++head;
			*var = val[head];
			occ--;
			return 0;
		}
		cout << "the elements are gone, there is nothing" << endl;
		return -1;
	}

	int PopTail(int* var)
	{
		if (occ > 0) {
			if (tail == 0)
				tail = size - 1;
			else
				--tail;
			*var = val[tail];
			occ--;
			return 0;
		}
		cout << "the elements are gone, there is nothing" << endl;
		return -1;
	}

	int PushHead(int var)
	{
		if (occ < size) {
			if (head == 0) {
				val[head] = var;
				head = size - 1;
			}
			else
				val[head--] = var;
			occ++;
			return 0;
		}
		cout << "haven't free places" << endl;
		return -1;
	}

	int fullD()
	{
		if (occ == 0) {
			for (int i = 0; i < size; i++)
				val[i] = rand() % 100;
			occ = size;
			cout << "deck is full" << endl;
			return 0;
		}
		cout << "can't fill anymore" << endl;
		return -1;
	}

	void printD()
	{
		if (occ > 0) {
			for (int i = head + 1; i < head + occ + 1; i++)
				cout << val[i % occ] << endl;
			cout << endl;
			return ;
		}
		cout << "deck is empty" << endl;
	}
};

/*
int main()
{
	int choice = 8;
	int val, control;
	Deque A, S1(5), S2(10);

	cout << "choose an action" << endl;
	cout << "11 - use push_head" << endl;
	cout << "12 - use pop_head" << endl;
	cout << "21 - use push_tail" << endl;
	cout << "22 - use pop_tail" << endl;
	cout << "1 - use assignment operator" << endl;
	cout << "2 - deck + deck" << endl;
	cout << "3 - print deck" << endl;
	cout << "4 - fill deck with random numbers" << endl;
	cout << "0 - finish work" << endl;

	while (choice) {
		switch (choice)
		{
		case 11: cout << "enter the number you want to put at the beginning of the deck" << endl;
			cin >> val;
			control = A.PushHead(val);
			if (!control)
				cout << "complete!" << endl;
			break;
		case 12: control = A.PopHead(&val);
			if (!control)
				cout << "you have extracted the number " << val << " from the beginning of the deque" << endl;
			else
				cout << endl;
			break;
		case 21: cout << "enter the number you want to put at the end of the deck";
			cin >> val;
			control = A.PushTail(val);
			if (!control)
				cout << "complete!" << endl;
			break;
		case 22: control = A.PopTail(&val);
			if (!control)
				cout << "you have extracted the number " << val << " from the end of the deque" << endl;
			else
				cout << endl;
			break;
		case 1:	S1.fullD();
			cout << "before" << endl;
			cout << "1-st deck" << endl;
			A.printD();
			cout << "2-nd deck" << endl;
			S1.printD();
			cout << "after" << endl;
			A = S1;
			cout << "1-st deck" << endl;
			A.printD();
			cout << "2-nd deck" << endl;
			S1.printD();
			break;
		case 2: S1.fullD();
			S2.fullD();
			cout << "1-st deck" << endl;
			S1.printD();
			cout << "2-nd deck" << endl;
			S2.printD();
			A = S1 + S2;
			cout << "result sum is" << endl;
			A.printD();
			break;
		case 3:
			A.printD();
			break;
		case 4: control = A.fullD();
				if (!control)
					cout << "successfully!" << endl;
				else
					cout << "error..." << endl;
				break;
		default:break;
		}
		cout << "Your choise ";
		cin >> choice;
		cout << endl;
	}
	return 0;
}
*/
