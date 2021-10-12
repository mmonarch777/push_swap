#include "push_swap.h"

void	ft_add_markup(t_stack **head, t_stack **a)
{
	int 	nb;
	int 	numb;
	int 	big_index;

	nb = 1;
	big_index = (*head)->index;
	numb = (*head)->number;
	(*head)->markup = 1;
	*head = (*head)->next;
	if (*head == NULL)
		*head = *a;
	while (*head)
	{
		if (big_index < (*head)->index)
		{
			big_index = (*head)->index;
			(*head)->markup = 1;
			nb++;
		}
		else
			(*head)->markup = 0;
		(*head) = (*head)->next;
		if (*head == NULL)
			*head = *a;
		if (numb == (*head)->number)
			break;
	}
	(*head)->num_markup = nb;
}

void	ft_markup(t_stack **a)
{
	t_stack *head;

	head = *a;
	while (head)
	{
		ft_add_markup(&head, a);
		head = head->next;
	}
}
