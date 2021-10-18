/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_negative.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:33:00 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/18 20:56:09 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_no_minus(t_struct *flag, long long nb, int toch, int shir)
{
	int	dlinna;

	dlinna = 0;
	if (flag->zero == 1 && flag->tochka != 1)
		flag->ch = '0';
	if (flag->ch == '0')
		dlinna += write(1, "-", 1);
	while (shir-- > (toch + 1))
		dlinna += write(1, &flag->ch, 1);
	if (flag->ch == ' ')
		dlinna += write(1, "-", 1);
	while (toch-- > ft_count(nb))
		dlinna += write(1, "0", 1);
	ft_putnbr_fd(nb, 1);
	dlinna += ft_count(nb);
	return (dlinna);
}

static int	ft_minus(t_struct *flag, long long nb, int toch, int shir)
{
	int		dlinna;

	dlinna = 0;
	shir -= (toch + 1);
	dlinna += write(1, "-", 1);
	while (toch-- > ft_count(nb))
		dlinna += write(1, "0", 1);
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
		ft_putnbr_fd(nb, 1);
	dlinna += ft_count(nb);
	while (shir-- > 0)
		dlinna += write(1, &flag->ch, 1);
	return (dlinna);
}

int	ft_print_negative(t_struct *flag, long long nb, int toch, int shir)
{
	int		dlinna;

	dlinna = 0;
	nb = -nb;
	if (flag->minus != 1)
		dlinna = ft_no_minus(flag, nb, toch, shir);
	else
		dlinna = ft_minus(flag, nb, toch, shir);
	return (dlinna);
}
