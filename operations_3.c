#include "push_swappy.h"
#include <unistd.h>

void	sa(t_list **a)
{
	if (swappy(a))
		write(1, "sa\n", 3);
}

int	swappy(t_list **head)
{
	t_list	*first;
	t_list	*second;

	if (!head || !*head || !(*head)->next)
		return (0);
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
	return (1);
}

int	pushy(t_list **dest, t_list **src)
{
	t_list	*node_del;

	if (!src || !*src)
		return (0);
	node_del = *src;
	*src = node_del->next;
	node_del->next = *dest;
	*dest = node_del;
	return (1);
}

int	rotay_back(t_list **head)
{
	t_list	*spin;
	t_list	*iter;

	if (!head || !*head || !(*head)->next)
		return (0);
	spin = *head;
	iter = spin;
	*head = (*head)->next;
	while (iter->next)
		iter = iter->next;
	spin->next = NULL;
	iter->next = spin;
	return (1);
}

int	rotay_front(t_list **head)
{
	t_list	*spin;
	t_list	*prev;

	if (!head || !*head || !(*head)->next)
		return (0);
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
	return (1);
}
