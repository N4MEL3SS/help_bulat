#include <iostream>
#include "../list_class/list_class.hpp"


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
		val = new int[x];
		size = x;
		head = occ = 0;
		tail = head + 1;
		if (x == 1)
			tail = head;
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

	void printD()
	{
		if (occ > 0) {
			for (int i = head + 1; i < head + occ + 1; i++)
				cout << val[i % size] << endl;
			cout << endl;
			return ;
		}
		cout << "deck is empty" << endl;
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
};

int main(){
	Deque A(4);
	int x;

	cout << "Checking methods associated with the head"<< endl;
	for(int i = 1; i < 6; i++) {
		A.PushHead(i);
		A.printD();
	}
	for(int i = 1; i < 6; i++) {
		A.PopHead(&x);
		A.printD();
	}
	cout << " " << endl;
	cout << "===================================" << endl;
	cout << " " << endl;
	cout << "Checking methods associated with the tail"<< endl;
	for(int i = 1; i < 6; i++) {
		A.PushTail(i);
		A.printD();
	}
	for(int i = 1; i < 6; i++) {
		A.PopTail(&x);
		A.printD();
	}
	cout << " " << endl;
	cout << "===================================" << endl;
	cout << " " << endl;
	cout << "check operator deck + deck" << endl;
	Deque D(6), E(3);
	for(int i = 1; i < 4; i++) {
		D.PushHead(i);
		D.PushTail(i);
		E.PushHead(i);
	}
	D.printD();
	E.printD();
	Deque F = D + E;
	F.printD();
	cout << " " << endl;
	cout << "===================================" << endl;
	cout << " " << endl;
	cout << "check constructor with parametrs"<< endl;
	for(int i = 0; i < 10000; i++) {
		Deque TEST(i);
		for(int j = 0; j < i; j++)
			TEST.PushHead(j);
	}
	cout << "If you see this inscription, the program did not crash, there "
			"was no memory loss error, then the constructor is working correctly" << endl;
	cout << " " << endl;
	cout << "===================================" << endl;
	cout << "Check operator =" << endl;
	Deque Test1(7),Test2;
	for(int i = 0; i < 7; i++)
		Test1.PushHead(i);
	Test2 = Test1;
	cout << "First deck\n";
	Test1.printD();
	cout << " " << endl;
	cout << "Second deck\n";
	Test2.printD();
	cout << " " << endl;
	Test1 = Test1 + Test2;
	cout << "Change first deck" << endl;
	cout << "First deck\n";
	Test1.printD();
	cout << " " << endl;
	cout << "Second deck\n";
	Test2.printD();
	cout << " " << endl;
	cout << "After changing the first, the second did not change, which means "
		   "the operation = works successfully (In arrays of elements in the first and second"
		  " deck uses different areas of memory)" << endl;
	return 0;
}

