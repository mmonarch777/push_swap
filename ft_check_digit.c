#include "push_swap.h"

void	ft_check_digit(char **mass)
{
	int i;
	int j;

	i = 0;
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
