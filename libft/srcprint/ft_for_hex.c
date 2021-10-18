/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:31:19 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 20:56:09 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_count_ptr(unsigned long adres)
{
	int	i;

	i = 0;
	while (adres > 15)
	{
		adres /= 16;
		i++;
	}
	return (i + 1);
}

void	ft_putnbr_hex(unsigned long adres, t_struct *flag)
{
	unsigned long	copy;
	unsigned long	i;
	unsigned long	nb;

	copy = adres;
	i = 1;
	while (copy > 15)
	{
		copy /= 16;
		i *= 16;
	}
	while (i > 0)
	{
		nb = adres / i;
		if (flag->hex == 'x')
			write(1, &"0123456789abcdef"[nb], 1);
		else
			write(1, &"0123456789ABCDEF"[nb], 1);
		adres %= i;
		i /= 16;
	}
}
