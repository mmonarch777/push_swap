/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:38:11 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 18:52:46 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	error_int(char *str, int *integer)
{
	free(integer);
	ft_printf("%s\n", str);
	exit(1);
}
