#include <iostream>

using namespace std;

struct	t_list {
	int data;
	t_list *next;
};

t_list *init()
{
	t_list	*t;

	t = new t_list;
	t->next = nullptr;
	return(t);
}

void set_list(t_list *list, int num)
{
	list->data = num;
}

int get_list(t_list *list)
{
	return (list->data);
}

t_list	*create_elem(int data)
{
	t_list	*t;

	t = new t_list;
	t->data = data;
	t->next = nullptr;
	return (t);
}

t_list	*push_front(t_list *begin_list, int data)
{
	t_list	*list;

	list = create_elem(data);
	list->next = begin_list;

	return (list);
}

int	list_size(t_list *begin_list)
{
	int	number;

	number = 0;
	while (begin_list) {
		number++;
		begin_list = begin_list->next;
	}
	return (number);
}

t_list	*list_last(t_list *begin_list)
{
	if (begin_list)
	{
		while (begin_list->next)
			begin_list = begin_list->next;
		return (begin_list);
	}
	return (nullptr);
}

t_list	*push_back(t_list *begin_list, int data)
{
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

t_list	*list_clear(t_list *begin_list)
{
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

t_list	*list_at(t_list *begin_list, int nbr)
{
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

void show_list(t_list *begin_list)
{
	while (begin_list) {
		cout << begin_list->data << endl;
		begin_list = begin_list->next;
	}
}

/*
int main()
{
	t_list *first, *temp;
	int	choice = 10, val;

	first = init();
	cout << "choose an action" << endl;
	cout << "1 - use set function" << endl;
	cout << "2 - show all lists" << endl;
	cout << "3 - use push_front" << endl;
	cout << "4 - use list_size" << endl;
	cout << "5 - use list_last" << endl;
	cout << "6 - use push_back" << endl;
	cout << "7 - use list_clear" << endl;
	cout << "8 - use list_at" << endl;
	cout << "0 - finish work" << endl;

	while (choice) {
		switch (choice) {
			case 1:
				cout << "enter the sheet number you want to change" << endl;
				cin >> val;
				temp = list_at(first, val);
				if (temp == nullptr) {
					cout << "no such index" << endl;
					break;
				}
				cout << "enter the number you want to put at list" << endl;
				cin >> val;
				set_list(temp, val);
				cout << "number that lies in the given element of the list: ";
				cout << get_list(temp) << endl;
				break;
			case 2:
				temp = first;
				show_list(temp);
				cout << endl;
				break;
			case 3:
				cout << "enter the number you want to put at begin list\n";
				cin >> val;
				first = push_front(first, val);
				cout << "success! let's go next act" << endl;
				break;
			case 4:
				temp = first;
				cout << "list_size is " << list_size(temp) << endl;
				cout << "success! let's go next act\n";
				break;
			case 5:
				temp = first;
				temp = list_last(temp);
				if (temp)
					cout << "data from the last sheet is " << get_list(temp) <<
				endl;
				else
					cout << "list empty" << endl;
				break;
			case 6:
				cout << "enter the number you want to put at end list" << endl;
				cin >> val;
				temp = first;
				first = push_back(temp, val);
				cout << "success! let's go next act" << endl;
				break;
			case 7:
				first = list_clear(first);
				cout << "list is empty" << endl;
				break;
			case 8:
				cout << "enter the sheet number you want to know" << endl;
				cin >> val;
				temp = first;
				temp = list_at(temp, val);
				if (temp == nullptr)
					cout << "no such index" << endl;
				else
					cout << "in this list number is " << get_list(temp) << endl;
				break;
			default:break;
		}
		cout << "Your choise: ";
		cin >> choice;
		cout << endl;
	}
	list_clear(first);
	return 0;
}
*/
