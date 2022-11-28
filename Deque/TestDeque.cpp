#include "TestDeque.hpp"

int TestDeque::constructor_test(Deque test_dq, int dq_size)
{
	if (test_dq.GetSize() == dq_size && test_dq.GetVal())
	{
		if (test_dq.GetHead() != test_dq.GetOcc() && test_dq.GetTail() != (test_dq.GetHead() + 1))
			return 1;
	}
	return 0;
}

int TestDeque::copy_constructor_test(Deque test_dq)
{
	Deque copy_deque(test_dq);

	if (copy_deque.GetHead() != test_dq.GetHead())
	{
		cout << "Head Error!" << endl;
		return 1;
	}
	if (copy_deque.GetTail() != test_dq.GetTail())
	{
		cout << "Tail Error!" << endl;
		return 1;
	}
	if (copy_deque.GetOcc() != test_dq.GetOcc())
	{
		cout << "Occ Error!" << endl;
		return 1;
	}
	if (copy_deque.GetSize() != test_dq.GetSize())
	{
		cout << "Size Error!" << endl;
		return 1;
	}

	for (int i = 0; i < test_dq.GetSize(); ++i)
	{
		if (test_dq.GetVal_i(i) != copy_deque.GetVal_i(i))
			return 1;
	}

	return 0;
}

int TestDeque::copy_assignment_test(Deque test_dq)
{
	Deque copy_deque;
	copy_deque = test_dq;

	if (copy_deque.GetHead() != test_dq.GetHead())
	{
		cout << "Head Error!" << endl;
		return 1;
	}
	if (copy_deque.GetTail() != test_dq.GetTail())
	{
		cout << "Tail Error!" << endl;
		return 1;
	}
	if (copy_deque.GetTail() != test_dq.GetOcc())
	{
		cout << "Occ Error!" << endl;
		return 1;
	}
	if (copy_deque.GetSize() != test_dq.GetSize())
	{
		cout << "Size Error!" << endl;
		return 1;
	}

	for (int i = 0; i < test_dq.GetSize(); ++i)
	{
		if (test_dq.GetVal_i(i) != copy_deque.GetVal_i(i))
			return 1;
	}

	return 0;
}

// TODO: Чекнуть подробнее
int TestDeque::pluse_operator_test(Deque test_dq1, Deque test_dq2)
{
	int i = 0;
	Deque sum_deque;
	sum_deque = test_dq1 + test_dq2;
	sum_deque.printD();
	test_dq1.printD();

	if (sum_deque.GetSize() == test_dq1.GetSize() + test_dq2.GetSize())
	{
		for (; i < test_dq1.GetSize(); ++i)
		{
			if (sum_deque.GetVal_i(i) != test_dq1.GetVal_i(i))
				return 1;
		}
		for (; i < sum_deque.GetSize(); ++i)
		{
			if (sum_deque.GetVal_i(i) != test_dq2.GetVal_i(i))
				return 1;
		}
	}
	return 0;
}

int TestDeque::push_tail_test(Deque test_dq)
{
	for (int i = 0; i < test_dq.GetSize(); ++i)
	{
		if (test_dq.PushTail(i))
			return 1;
	}
	if (!test_dq.PushTail(42))
		return 1;
	return 0;
}
