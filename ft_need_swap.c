#include "push_swap.h"

static void ft_check_swap(t_stack **stack)
{
	t_stack *swap1;
	t_stack *swap2;

	if (!*stack || !(*stack)->next)
		return;
	swap1 = *stack;
	swap2 = (*stack)->next;
	swap1->next = (*stack)->next->next;
	swap2->next = swap1;
	(*stack) = swap2;

}

static int	ft_find_big_markup(t_stack **a)
{
	t_stack	*head1;
	int 	big;
	int 	index;

	head1 = *a;
	big = head1->num_markup;
	index = head1->index;
	head1 = head1->next;
	while (head1)
	{
		if (big < head1->num_markup)
		{
			big = head1->num_markup;
			index = head1->index;
		}
		if (big == head1->num_markup)
			if (index > head1->index)
				index = head1->index;
		head1 = head1->next;
	}
	return (big);
}

void	ft_add_new_markup(int index, t_stack **a)
{
	t_stack *head;

	head = *a;
	while(head)
	{
		if (head->index == index)
			ft_add_markup(&head, a);
		head = head->next;
	}
}

int	ft_need_swap(int index, t_stack **a)
{
	t_stack *head;
	int		first;
	int 	second;

	head = *a;
	first = ft_find_big_markup(a);
	ft_check_swap(a);

	ft_add_new_markup(index, a);
	second = ft_find_big_markup(a);
	ft_check_swap(a);
	ft_add_new_markup(index, a);
	if (first >= second)
		return (0);
	else
		return (1);
}
