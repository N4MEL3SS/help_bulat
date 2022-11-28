#ifndef TESTDEQUE_HPP
#define TESTDEQUE_HPP

#include "Deque.hpp"

class TestDeque
{
 public:
	int constructor_test(Deque test_dq, int dq_size);
	int deconstructor_test(Deque test_dq);
	int copy_constructor_test(Deque test_dq);
	int copy_assignment_test(Deque test_dq);
	int pluse_operator_test(Deque test_dq1, Deque test_dq2);
	int push_tail_test(Deque test_dq);
	int pop_tail_test(Deque test_dq);
	int push_head_test(Deque test_dq);
	int pop_head_test(Deque test_dq);

	int print_deque_test(Deque test_dq);
	int full_deque_test(Deque test_dq);
};

#endif //TESTDEQUE_HPP
