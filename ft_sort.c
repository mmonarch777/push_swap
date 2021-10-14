#include "push_swap.h"

static int	ft_find_start_index(t_stack **a)
{
	t_stack	*head;
	int 	big;
	int 	index;

	head = *a;
	big = head->num_markup;
	index = head->index;
	head = head->next;
	while (head)
	{
		if (big < head->num_markup)
		{
			big = head->num_markup;
			index = head->index;
		}
		if (big == head->num_markup)
			if (index > head->index)
				index = head->index;
		head = head->next;
	}
	head = *a;
	return (index);
}

static int	ft_check_false(t_stack **a)
{
	t_stack *head;

	head = *a;
	while (head)
	{
		if (head->markup == 0)
			return (1);
		head = head->next;
	}
	return (0);
}

void	ft_big_markup(int index, t_stack **a)
{
	t_stack  *head;

	head = *a;
	while (head)
	{
		if (index == head->index)
			ft_add_markup(&head, a);
		head = head->next;
	}
}

void	ft_sort(t_stack **a, t_stack **b)
{
	int 	index;

	index = ft_find_start_index(a);
	ft_big_markup(index, a);
	while (ft_check_false(a))
	{
		if (ft_need_swap(index, a))
		{
			ft_swap("sa", a);
			ft_add_new_markup(index, a);
		}
		else if ((*a)->markup == 0)
			ft_push_to_stack("pb", a, b);
		else
			ft_rotate("ra", a);
	}

}
