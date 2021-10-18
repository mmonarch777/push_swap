/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:31:38 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 20:56:09 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_parsing(char **mass, va_list arg, t_struct *flag)
{
	while (ft_isalpha(**mass) != 1)
	{
		if (**mass == '-')
			flag->minus = 1;
		if (**mass == '0' && (*(*mass - 1) == '%' || *(*mass - 1) == '-'))
			flag->zero = 1;
		if (ft_isdigit(**mass) && flag->tochka < 1)
			flag->widht = (flag->widht * 10) + (**mass - 48);
		if (**mass == '*' && flag->tochka < 1)
			flag->widht = va_arg(arg, int);
		if (**mass == '.')
			flag->tochka = 1;
		if (ft_isdigit(**mass) && flag->tochka == 1)
			flag->precsion = (flag->precsion * 10) + (**mass - 48);
		if (**mass == '*' && flag->tochka == 1)
			flag->precsion = va_arg(arg, int);
		if (**mass == '%')
			break ;
		if (!(ft_strchr_printf("1234567890*%.-", **mass)))
			break ;
		(*mass)++;
	}
}

static void	ft_initialize_flag(t_struct *flag)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->widht = 0;
	flag->tochka = 0;
	flag->precsion = 0;
	flag->ch = ' ';
	flag->hex = 'x';
}

int	ft_parsing_flag(char **mass, va_list arg)
{
	int			nb;
	t_struct	flag;

	ft_initialize_flag(&flag);
	ft_parsing(mass, arg, &flag);
	nb = ft_type(mass, &flag, arg);
	return (nb);
}
