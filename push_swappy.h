#ifndef PUSH_SWAPPY_H
# define PUSH_SWAPPY_H

typedef struct node
{
	void		*val;
	struct node	*next;
}	t_list;

double	compute_disorder(t_list *a);
int		swappy(t_list **head);
int		pushy(t_list **dest, t_list **src);
int		rotay_back(t_list **head);
int		rotay_front(t_list **head);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif
