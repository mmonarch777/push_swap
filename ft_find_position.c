#include "push_swap.h"

static int	ft_check_min_index(t_stack **stack)
{
	t_stack *head;
	int		min;

	head = *stack;
	min = head.index;
	while (head)
	{
		if (min > head.index)
			min = head.index;
		head = head.next
	}
	return (min);
}

static int	ft_check_max_index(t_stack **stack)
{
	t_stack *head;
	int		max;

	head = *stack;
	max = head.index;
	while (head)
	{
		if (max < head.index)
			max = head.index;
		head = head.next
	}
	return (max);
}



void ft_find_position(t_stack **a, t_stack **b)
{
	t_stack *ha,
	t_stack *hb;
	int 	min;
	int 	max;
	int 	last;

	ha = *a;
	min = ft_check_min_index(a);
	max = ft_check_max_index(a);
	last = ft_last_index(a);
//	if((*b)->index < min || (*b)->index > max || ((*b)->index > last && (*b)->index < (*a)->index))------------
	while (ha)
	{
		if ((*b)->index > last && (*b)->index < (*a)->index)
		{
			(*b)->num_markup = (*a)->step_up + (*b)->step_up;
			break;
		}
		if ((*b)->index < min || (*b)->index > max)
		{
			if (ha->index == min)
			{
				(*b)->num_markup = ha->step_up + (*b)->step_up;
				break;
			}
		}
		ha = ha->next;
	}
	//	else if((*b)->index < (*a)->index) --------------------
	while (ha->next)
	{
		if (ha->next->index > (*b)->index)
		{
			(*b)->num_markup = ha->step_up + (*b)->step_up;
			break;
		}
		ha = ha->next;
	}
//	else
	while(ha)
	{
		if (ha->index > (*b)->index)
		{
			(*b)->num_markup = ha->step_up + (*b)->step_up;
			break;
		}
		ha = ha->next;
	}
}

