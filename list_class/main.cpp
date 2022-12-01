#include "list_class.hpp"

int main()
{
	t_list *begin_list = new t_list(5);

	for (int i = 0; i < 10; ++i)
	{
		begin_list->push_back(rand() % 10);
	}
	cout << "list size: " << begin_list->list_size() << endl;
	begin_list->list_show();
	delete begin_list;

	return 0;
}
