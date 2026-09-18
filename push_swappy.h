#ifndef PUSH_SWAPPY_H
# define PUSH_SWAPPY_H

typedef struct node
{
	void		*val;
	struct node	*next;
}	t_list;

void	swappy(t_list **head);
void	pushy(t_list **head_add, t_list **head_del);
void	rotay_back(t_list **head);
void	rotay_front(t_list **head);
void	sa(t_list **a);

#endif
