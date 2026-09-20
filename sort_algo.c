#include "push_swappy.h"

void	bubbly(t_list **a_head, t_list **b_head)
{
	//t_list	*a;

	if (!a_head || !*a_head || !(*a_head)->next)
		return ;
	//a = *a_head;
	while (!is_sorted(*a_head))
	{
		//check_len(*a_head)-> infinite loop issue
		while ((*a_head)->next)
		{
			if ((*a_head)->val > ((*a_head)->next)->val)
				sa(a_head);
			pb(b_head, a_head);
		}
		while (*b_head)
			pa(a_head, b_head);
	}
}
