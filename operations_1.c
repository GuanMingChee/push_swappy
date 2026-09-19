#include "push_swappy.h"
#include <unistd.h>

void	rb(t_list **b)
{
	if (rotay_back(b))
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	if ((!a || !*a || !(*a)->next || !b || !*b || !(*b)->next))
		return ;
	rotay_back(a);
	rotay_back(b);
	write(1, "rr\n", 3);
}

void	rra(t_list **a)
{
	if (rotay_front(a))
		write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	if (rotay_front(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	if ((!a || !*a || !(*a)->next) || (!b || !*b || !(*b)->next))
		return ;
	rotay_front(a);
	rotay_front(b);
	write(1, "rrr\n", 4);
}
