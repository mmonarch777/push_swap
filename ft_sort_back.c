#include "push_swap.h"

static void	ft_find_and_add_position(t_stack **a, t_stack **b)
{
	t_stack *head;

	head = *b;
	while (head)
	{
		ft_find_position(a, &head);
		head = head->next;
	}
}

void	ft_sort_back(t_stack **a, t_stack **b)
{

	ft_step_to_up(a);
	ft_step_to_up(b);
	while ((*b))
	{
		ft_find_and_add_position(a, b);
		ft_push_back(a, b);
		ft_step_to_up(a);
		ft_step_to_up(b);
	}
}
