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
		ft_printf("a:  number %d,  index %d,  markup %d,  num_markup %d\n", a->number, a->index, a->markup, a->num_markup);
		a = a->next;
	}
	while (b)
	{
		ft_printf("b:  number %d,  index %d,  markup %d,  num_markup %d\n", b->number, b->index, b->markup, b->num_markup);
		b = b->next;
	}
	return 0;
}
