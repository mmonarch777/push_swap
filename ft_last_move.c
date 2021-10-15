#include "push_swap.h"

void ft_last_move(t_stack **a)
{
	t_stack *head;
	int 	size;

	size = ft_size(a);
	head = *a;
	ft_position(a);
	while (head)
	{
		if (head->index == 1)
			break ;
		head = head->next;
	}
	if (head->index <= size / 2 + 1)
		while (head->position != 1)
			ft_rotate("ra", a);
	else
		while (head->position != 1)
			ft_revers_rotate("rra", a);
}