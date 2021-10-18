/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:32:38 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 20:56:09 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_d(t_struct *flag, va_list arg)
{
	int			dlinna;
	long long	number;

	number = va_arg(arg, int);
	if (!number && flag->tochka == 1 && flag->precsion == 0 && flag->widht == 0)
		return (0);
	dlinna = ft_add_flag(flag, number);
	return (dlinna);
}
