#include "push_swap.h"

static int	ft_check_min(t_stack **a)
{
	t_stack *head;

	head = *a;
	while (head)
	{
		if(head->index == -1)
			return (head->number);
		head = head->next;
	}
	return (0);
}

static void	ft_add_index(int *ind, t_stack **a)
{
	t_stack *head;
	int min;

	head = *a;
	min = ft_check_min(a);
	while (head)
	{
		if(min > head->number && head->index == -1)
			min = head->number;
		head = head->next;
	}
	head = *a;
	while (head)
	{
		if(head->number == min)
			head->index = *ind;
		head = head->next;
	}
}

static int ft_check_index(t_stack **a)
{
	t_stack *head;

	head = *a;
	while (head)
	{
		if(head->index == -1)
			return (1);
		head = head->next;
	}
	return (0);
}

void	ft_index(t_stack **a)
{
	t_stack *head;
	int		ind;

	ind = 1;
	head = *a;
	while (head)
	{
		head->index = -1;
		head = head->next;
	}
	head = *a;
	while (ft_check_index(a))
	{
		ft_add_index(&ind, a);
		ind++;
	}
}