/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:39:10 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 18:39:14 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_digit(char **mass)
{
	int	i;
	int	j;

	i = 0;
	if (mass[i] == NULL)
		error ("There is an invalid argument after split");
	while (mass[i])
	{
		j = 0;
		while (mass[i][j])
		{
			if (mass[i][j] == '-' || mass[i][j] == '+')
				j++;
			if (ft_isdigit(mass[i][j]))
			{
				j++;
				if (!ft_isdigit(mass[i][j]) && mass[i][j])
					error("The argument has an extraneous character");
			}
			else
				error("The argument has an extraneous character");
		}
		i++;
	}
}
