/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:32:20 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 20:56:09 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_print(t_struct *flag, char c, int shir)
{
	int	len;

	len = 0;
	if (flag->minus != 1)
	{
		if (flag->zero == 1)
			flag->ch = '0';
		while (shir-- > 1)
			len += write(1, &flag->ch, 1);
		len += write(1, &c, 1);
	}
	else
	{
		len += write(1, &c, 1);
		while (shir-- > 1)
			len += write(1, " ", 1);
	}
	return (len);
}

int	ft_print_c(t_struct *flag, va_list arg, char **mass)
{
	int		dlinna;
	int		shir;
	char	c;

	if (**mass == '%')
		c = '%';
	else
		c = va_arg(arg, int);
	if (flag->widht < 0)
	{
		flag->minus = 1;
		flag->widht = -flag->widht;
	}
	if (flag->widht > 1)
		shir = flag->widht;
	else
		shir = 1;
	dlinna = ft_print(flag, c, shir);
	return (dlinna);
}
