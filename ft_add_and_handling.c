/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_and_handling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:38:36 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 18:55:28 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atoi_long(const char *str)
{
	int		i;
	int		nb;
	long	num;

	i = 0;
	num = 0;
	nb = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'\
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nb = nb * (-1);
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * nb);
}

static int	ft_find_number(char **argv)
{
	char	**mass;
	int		size;
	int		i;
	int		j;

	i = 1;
	size = 0;
	while (argv[i])
	{
		if (!ft_strncmp(argv[i], "", 1))
			error ("There is an invalid argument");
		j = 0;
		mass = ft_split(argv[i], ' ');
		while (mass[j])
		{
			ft_check_digit(mass);
			free(mass[j]);
			j++;
			size++;
		}
		free(mass);
		i++;
	}
	return (size);
}

static void	ft_add_to_integer(char **argv, int *integer)
{
	char	**mass;
	int		i;
	int		j;
	int		num;

	i = 1;
	num = 0;
	while (argv[i])
	{
		j = 0;
		mass = ft_split(argv[i], ' ');
		while (mass[j])
		{
			if (ft_atoi_long(mass[j]) > 2147483647
				|| ft_atoi_long(mass[j]) < -2147483648)
				error_int("I want a number from the INT range :p", integer);
			integer[num] = (int)ft_atoi_long(mass[j]);
			free(mass[j]);
			num++;
			j++;
		}
		i++;
		free(mass);
	}
}

void	ft_add_and_handling(char **argv, t_stack **a)
{
	int	number;
	int	*integer;

	number = ft_find_number(argv);
	integer = malloc(sizeof (int) * number);
	ft_add_to_integer(argv, integer);
	ft_check_duplicat(integer, number);
	ft_add_to_list(integer, number, a);
	free(integer);
	ft_check_sort(a);
}
