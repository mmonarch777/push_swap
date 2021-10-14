#include "push_swap.h"

void	ft_position(t_stack **stack)
{
	t_stack *head;
	int		position;

	position = 1;
	head = *stack;
	while (head)
	{
		head->position = position;
		position++;
		head = head->next;
	}
}
