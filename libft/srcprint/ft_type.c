/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:34:46 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 20:55:57 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_type(char **mass, t_struct *flag, va_list arg)
{
	int	nb;

	nb = 0;
	if (**mass == 'd' || **mass == 'i')
		nb = ft_print_d(flag, arg);
	if (**mass == 's')
		nb = ft_print_s(flag, arg);
	if (**mass == 'c' || **mass == '%')
		nb = ft_print_c(flag, arg, mass);
	if (**mass == 'p')
		nb = ft_print_ptr(flag, arg);
	if (**mass == 'u')
		nb = ft_print_u(flag, arg);
	if (**mass == 'x' || **mass == 'X')
		nb = ft_print_xxx(flag, arg, mass);
	if (!(ft_strchr("cspdiuxX%", **mass)))
		return (0);
	(*mass)++;
	return (nb);
}
