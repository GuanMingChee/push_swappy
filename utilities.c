#include "push_swappy.h"

int	check_len(t_list *head)
{
	int	len;

	len = 0;
	while (head)
	{
		head = head->next;
		len++;
	}
	return (len);
}

int	is_sorted(t_list *head)
{
	if (!head)
		return (1);
	while (head->next)
	{
		if (head->val > (head->next)->val)
			return (0);
		head = head->next;
	}
	return (1);
}

double	compute_disorder(t_list *a)
{
	int		mistakes;
	int		total_pairs;
	t_list	*iter_out;
	t_list	*iter_in;

	if (!a || !a->next)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	iter_out = a;
	while (iter_out)
	{
		iter_in = iter_out->next;
		while (iter_in)
		{
			total_pairs++;
			if (iter_out->val > iter_in->val)
				mistakes++;
			iter_in = iter_in->next;
		}
		iter_out = iter_out->next;
	}
	return ((double)mistakes / (double)total_pairs);
}
