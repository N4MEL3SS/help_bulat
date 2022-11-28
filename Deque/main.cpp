#include "TestDeque.hpp"

#define B_SIZE 5

int main()
{
	Deque A, B(B_SIZE);
	TestDeque test_ft;

	test_ft.constructor_test(A, DEF);
	test_ft.constructor_test(B, B_SIZE);
	test_ft.push_tail_test(A);
	test_ft.push_tail_test(B);
//	test_ft.pluse_operator_test(A, B);

	cout << "A:" << endl;
	A.fullD();
	A.printD();
	cout << "B:" << endl;
	B.fullD();
	B.printD();
	test_ft.pluse_operator_test(A, B);
	test_ft.copy_constructor_test(A);
	test_ft.copy_assignment_test(A);
	return 0;
}
