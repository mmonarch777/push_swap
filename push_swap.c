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
//	ft_push_to_stack("pb", &a, &b);
//	ft_push_to_stack("pb", &a, &b);
//	ft_push_to_stack("pb", &a, &b);
//	ft_rotate("ra", &b);
//	ft_push_to_stack("pa", &b, &a);
//	ft_swap("sa", &a);
	ft_markup(&a);
	ft_sort(&a, &b);

	while (a)
	{
		ft_printf("a:  number %10d,  index %10d,  markup %10d,  num_markup %10d,  position %10d\n", a->number, a->index, a->markup, a->num_markup, a->position);
		a = a->next;
	}
	ft_printf("----------------------------------------------------------------------------------------------------------\n");
	while (b)
	{
		ft_printf("b:  number %10d,  index %10d,  markup %10d,  num_markup %10d,  position %10d\n", b->number, b->index, b->markup, b->num_markup, b->position);
		b = b->next;
	}
	return 0;
}
