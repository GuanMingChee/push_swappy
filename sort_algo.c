#include "push_swappy.h"
#include <limits.h>

int	bubbly(t_list **a_head, t_list **b_head)
{
	int	list_len;
	int	iter;

	if (!a_head || !*a_head || !(*a_head)->next || !b_head)
		return (0);
	list_len = check_len(*a_head);
	while (!is_sorted(*a_head))
	{
		iter = 1;
		while (iter < list_len && (*a_head)->next)
		{
			if ((*a_head)->val > ((*a_head)->next)->val)
				sa(a_head);
			pb(a_head, b_head);
			iter++;
		}
		while (*b_head)
			pa(a_head, b_head);
	}
	return (1);
}

int	indexing(t_list **head, int list_len)
{
	int		i;
	int		*mally;
	t_list	*iter;

	if (!head || !*head)
		return (0);
	if (list_len < 2)
		return (1);
	mally = malloc(list_len * sizeof(int));
	if (!mally)
		return (0);
	i = 0;
	iter = *head;
	while (i < list_len)
	{
		mally[i] = iter->val;
		iter = iter->next;
		i++;
	}
	if (!bubbly_indexing(mally, list_len))
		return (free(mally), 0);
	if (!node_ranking(mally, list_len, *head))
		return (free(mally), 0);
	return (free(mally), 1);
}

int	node_ranking(int *mally, int list_len, t_list *head)
{
	t_list	*iter;
	int		i;

	if (!mally || !head || list_len < 1)
		return (0);
	i = 0;
	while (i < list_len)
	{
		iter = head;
		while (iter)
		{
			if (iter->val == mally[i])
			{
				iter->idx = i;
				break ;
			}
			iter = iter->next;
		}
		i++;
	}
	return (1);
}

int	bubbly_indexing(int *mally, int list_len)
{
	int	inner;
	int	outer;
	int	tmp;

	if (!mally || list_len < 1)
		return (0);
	outer = 1;
	while (outer < list_len)
	{
		inner = 0;
		while (inner < list_len - outer)
		{
			if (mally[inner] > mally[inner + 1])
			{
				tmp = mally[inner];
				mally[inner] = mally[inner + 1];
				mally[inner + 1] = tmp;
			}
			inner++;
		}
		outer++;
	}
	return (1);
}

int	chunky(t_list **a_head, t_list **b_head)
{
	int	list_len;
	int	chunk_size;

	//check length of list to determine indexing range
	list_len = check_len(*a_head);
	//determine size of chunk based on total length
	chunk_size = chunky_size(list_len);
	//phase 1 (indexing of node)
	if (!indexing(a_head, list_len))
		return (0);
	return (1);
}
