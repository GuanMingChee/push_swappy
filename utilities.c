#include "push_swappy.h"

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
