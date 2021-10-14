#include "push_swap.h"

static void	ft_push_up(t_stack **stack)
{
	t_stack *head;

	int 	size;
	head = *stack;
	size = ft_size(stack);
	while (head)
	{
		if ((size / 2 + 1) >= head->position)
			head->step_up = head->position - 1;
		else
			head->step_up = size - head->position + 1;
		head = head->next;
	}
}
void	ft_sort_back(t_stack **a, t_stack **b)
{
	t_stack *ha;
	t_stack *hb;


	ha = *a;
	hb = *b;
	ft_push_up(a);
	ft_push_up(b);
//	while (b)
//	{
//
//	}
}
