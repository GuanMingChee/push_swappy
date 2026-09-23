#include "push_swappy.h"

void	bubbly(t_list **a_head, t_list **b_head)
{
	int	list_len;
	int	iter;

	if (!a_head || !*a_head || !(*a_head)->next)
		return ;
	list_len = check_len(*a_head);
	while (!is_sorted(*a_head))
	{
		iter = 1;
		while (iter < list_len && (*a_head)->next)
		{
			if ((*a_head)->val > ((*a_head)->next)->val)
				sa(a_head);
			pb(b_head, a_head);
			iter++;
		}
		while (*b_head)
			pa(a_head, b_head);
	}
}

void	chunky(t_list **a_head, t_list **b_head)
{
	int	list_len;
	int	chunk_size;
	int	mally;
	int	i;

	//check length of list to determine indexing range
	list_len = check_len(*a_head);
	//create malloc to handle sorting index
	mally = malloc(list_len * sizeof(int));
	//may need a return type due to this
	if (!mally)
		return ;
	//determine size of chunk based on total length
	chunk_size = chunky_size(list_len);
	i = 0;
	while (i < list_len)
	{
		mally[i] = (*a_head)->val;
		i++;
		*a_head = (*a_head)->next;
	}

	free(mally);
}
