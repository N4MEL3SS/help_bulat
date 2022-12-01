#ifndef LIST_CLASS_HPP
#define LIST_CLASS_HPP

#include <iostream>

using namespace std;

class t_list
{
private:
	int data;
	t_list *next;
	t_list *head;
public:
	t_list();
	t_list(int num);
	t_list& operator=(const t_list& other);
	~t_list();

	int		get_list();
	void	set_list(int num);

	t_list	*create_elem(int num);
	void 	push_front(int num);
	void 	push_back(int num);
	int		list_size();
	t_list	*list_last();
	void	list_clear();
	t_list	*list_at(int index);
//	void	*list_remove(int index);
	void	list_show();
};


#endif //LIST_CLASS_HPP
