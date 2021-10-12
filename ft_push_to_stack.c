#include "push_swap.h"

void	ft_push_to_stack(char *str, t_stack **from, t_stack **to)
{
	t_stack *push;

	if (!*from)
		return;
	push = *from;
	*from = (*from)->next;
	push->next = *to;
	*to = push;
	ft_printf("%s\n", str);
}

