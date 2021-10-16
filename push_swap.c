#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		error("Not enough arguments");
	ft_add_and_handling(argv, &a);
	ft_index(&a);
	ft_markup(&a);
	ft_sort(&a, &b);
	ft_sort_back(&a, &b);
	ft_last_move(&a);
//	while (a)
//	{
//		ft_printf("a:  number %5d,  index %5d,  markup %5d,  num_markup %5d,  position %5d,  push_up %5d\n", a->number, a->index, a->markup, a->num_markup, a->position, a->step_up);
//		a = a->next;
//	}
//	ft_printf("----------------------------------------------------------------------------------------------------------\n");
//	while (b)
//	{
//		ft_printf("b:  number %5d,  index %5d,  markup %5d,  num_markup %5d,  position %5d,  push_up %5d\n", b->number, b->index, b->markup, b->num_markup, b->position, b->step_up);
//		b = b->next;
//	}
	return 0;
}
