#include "push_swappy.h"
#include <unistd.h>

void	sb(t_list **b)
{
	if (swappy(b))
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	swappy(a);
	swappy(b);
	write(1, "ss\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	if (pushy(a, b))
		write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	if (pushy(b, a))
		write(1, "pb\n", 3);
}

void	ra(t_list **a)
{
	if (rotay_back(a))
		write(1, "ra\n", 3);
}
