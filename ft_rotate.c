#include "push_swap.h"

void	ft_rotate(char *str, t_stack **stack)
{
	t_stack *swap1;
	t_stack *swap2;

	if (!*stack || !(*stack)->next)
		return;
	swap1 = *stack;
	swap2 = (*stack)->next;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = swap1;
	swap1->next = NULL;
	*stack = swap2;
	if (ft_strncmp(str, "rr", 2))
		ft_printf("%s\n", str);

}

void	ft_rotate_rr(char *str, t_stack **a, t_stack **b)
{
	ft_rotate("rr", a);
	ft_rotate("rr", b);
	ft_printf("%s\n", str);
}