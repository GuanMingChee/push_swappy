#include "push_swappy.h"
#include <unistd.h>

void	sa(t_list **a)
{
	swappy(a);
	write(1, "sa\n", 3);
}

void	swappy(t_list **head)
{
	t_list	*first;
	t_list	*second;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	pushy(t_list **head_add, t_list **head_del)
{
	t_list	*node_del;

	if (!head_del || !*head_del)
		return ;
	node_del = *head_del;
	*head_del = node_del->next;
	node_del->next = *head_add;
	*head_add = node_del;
}

void	rotay_back(t_list **head)
{
	t_list	*spin;
	t_list	*iter;

	if (!head || !*head || !(*head)->next)
		return ;
	spin = *head;
	iter = spin;
	*head = (*head)->next;
	while (iter->next)
		iter = iter->next;
	spin->next = NULL;
	iter->next = spin;
}

void	rotay_front(t_list **head)
{
	t_list	*spin;
	t_list	*prev;

	if (!head || !*head || !(*head)->next)
		return ;
	spin = (*head)->next;
	prev = *head;
	while (spin->next)
	{
		prev = spin;
		spin = spin->next;
	}
	prev->next = NULL;
	spin->next = *head;
	*head = spin;
}
