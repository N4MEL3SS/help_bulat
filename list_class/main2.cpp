#include <iostream>

using namespace std;

struct	t_list {
	int data;
	t_list *next;
};

t_list *init() {
	t_list	*t;

	t = new t_list;
	t->next = nullptr;
	return(t);
}

void set_list(t_list *list, int num) {
	list->data = num;
}

int get_list(t_list *list) {
	return (list->data);
}

t_list	*create_elem(int data) {
	t_list	*t;

	t = new t_list;
	t->data = data;
	t->next = nullptr;
	return (t);
}

t_list	*push_front(t_list *begin_list, int data) {
	t_list	*list;

	list = create_elem(data);
	list->next = begin_list;

	return (list);
}

int	list_size(t_list *begin_list) {
	int	number;

	number = 0;
	while (begin_list) {
		number++;
		begin_list = begin_list->next;
	}
	return (number);
}

t_list	*list_last(t_list *begin_list) {
	if (begin_list)
	{
		while (begin_list->next)
			begin_list = begin_list->next;
		return (begin_list);
	}
	return (nullptr);
}

t_list	*push_back(t_list *begin_list, int data) {
	t_list	*list;

	if (begin_list) {
		list = begin_list;
		while (list->next)
			list = list->next;
		list->next = create_elem(data);
	}
	else
		begin_list = create_elem(data);
	return (begin_list);
}

t_list	*list_clear(t_list *begin_list) {
	t_list	*tmp;
	t_list	*list;

	list = begin_list;
	while (list)
	{
		tmp = list->next;
		delete list;
		list = tmp;
	}
	return (nullptr);
}

t_list	*list_at(t_list *begin_list, int nbr) {
	if (begin_list != nullptr)
	{
		for (int i = 0; i < nbr; i++)
		{
			if (begin_list->next)
				begin_list = begin_list->next;
			else
				return nullptr;
		}
	}
	return (begin_list);
}

t_list *remove_list(t_list *begin_list, int d) {
	t_list *temp = list_at(begin_list, d - 1);
	if (d == 0) {
		begin_list = begin_list->next;
		delete temp;
	}
	else if (temp != nullptr) {
		t_list *temp2 = temp->next;
		if (temp2 == nullptr)
			temp->next = temp2;
		else
			temp->next = temp2->next;
		delete temp2;
	}
	return (begin_list);
}

void show_list(t_list *begin_list)
{
	while (begin_list) {
		cout << begin_list->data << endl;
		begin_list = begin_list->next;
	}
}

int main()
{
	t_list *first = nullptr;

	cout << "checking push_front and push_back" << endl;
	first = push_front(first, 5);
	show_list(first);
	cout << endl;
	first = push_back(first, 10);
	show_list(first);
	cout << endl;
	first = push_front(first, 100);
	show_list(first);
	cout << endl;
	cout << "checking remove element with index" << endl;
	first = remove_list(first, 2);
	show_list(first);
	cout << endl;
	cout << "checking list_size" << endl;
	t_list *temp = first;
	cout << "list size is " << list_size(temp) << endl;
	cout << endl;
	cout << "checking list_last" << endl;
	temp = first;
	cout << "data in last list is " << list_last(temp)->data << endl;
	cout << endl;
	cout << "checking list_at" << endl;
	temp = first;
	cout << "data in element with index is " << list_at(temp, 1)->data << endl;
	cout << endl;
	list_clear(first);
	return 0;
}
