/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:49:21 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 19:27:14 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

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
	ft_clear(&a);
	return (0);
}
