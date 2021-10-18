/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:34:29 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 20:55:57 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(const char *format, ...)
{
	int			length;
	char		*mass;
	va_list		arg;

	length = 0;
	mass = (char *)format;
	va_start(arg, format);
	while (*mass)
	{
		if (*mass == '%')
		{
			mass++;
			length += ft_parsing_flag(&mass, arg);
		}
		if (*mass && *mass != '%')
			length += write(1, mass++, 1);
	}
	va_end(arg);
	return (length);
}
