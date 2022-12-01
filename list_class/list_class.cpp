#include "list_class.hpp"

t_list::t_list()
{
	next = nullptr;
	head = this;
}

t_list::t_list(int num)
{
	next = nullptr;
	data = num;
	head = this;
}

t_list &t_list::operator = (const t_list &other)
{
	data = other.data;
	next = other.next;
	head = other.head;
	return *this;
}

t_list::~t_list()
{
	list_clear();
}

int t_list::get_list() { return data; }
void t_list::set_list(int num) { data = num; }

void t_list::list_clear()
{
	t_list	*tmp;
	t_list	*list;

	if (head)
	{
		list = head;
		while (list)
		{
			tmp = list->next;
			delete list;
			list = tmp;
		}
	}
}

t_list *t_list::create_elem(int num)
{
	t_list	*t = new t_list;

	t->data = num;
	t->next = nullptr;
	t->head = nullptr;
	return (t);
}

void	t_list::push_front(int num)
{
	t_list *temp = create_elem(num);

	next = this;
	head = temp;
	temp->head = temp;
}

void	t_list::push_back(int num)
{
	t_list *list = list_last();
	list->next = create_elem(num);
	list->next->head = this;
}

void t_list::list_show()
{
	t_list *list = head;

	while (list)
	{
		cout << list->data << endl;
		list = list->next;
	}
}

int t_list::list_size()
{
	t_list *list = head;
	int i = 0;

	while (list)
	{
		i++;
		list = list->next;
	}
	return i;
}

t_list *t_list::list_last()
{
	t_list *list = head;

	while (list->next)
		list = list->next;

	return list;
}

t_list *t_list::list_at(int index)
{
	t_list *list = head;

	for (int i = 0; i < index; ++i)
	{
		if (list->next)
			list = list->next;
		else
			return nullptr;
	}

	return list;
}



//void *t_list::list_remove(int index)
//{
//	return nullptr;
//}
