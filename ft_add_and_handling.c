#include "push_swap.h"

void 	*ft_lstnew_ps(int number)
{
	t_stack	*mass;

	mass = malloc(sizeof (t_stack));
	if (!mass)
		return (NULL);
	mass->number = number;
	mass->next = NULL;
	return (mass);
}

static int	ft_atoi_long(const char *str)
{
	int		i;
	int		nb;
	long	num;

	i = 0;
	num = 0;
	nb = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'\
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nb = nb * (-1);
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (num * nb > 2147483647 || num * nb < -2147483648)
		error("I want a number from the INT range :p");
	return ((int)num * nb);
}

void	ft_add_to_list(char **mass, t_stack **a)
{
	t_stack *first;
	t_stack	*new;
	int		i;

	i = 0;
	while (mass[i])
	{
		new = (t_stack *)ft_lstnew_ps(ft_atoi_long(mass[i]));
		if (*a == NULL)
			*a = new;
		else
		{
			first = *a;
			while (first->next)
				first = first->next;
			first->next = new;
		}
		i++;
	}
}

void	ft_check_duplicate(t_stack **a)
{
	t_stack	*first;
	t_stack	*check;

	first = *a;
	while (first)
	{
		check = first->next;
		while(check)
		{
			if (first->number == check->number)
				error("Arguments have duplicates");
			check = check->next;
		}
		first = first->next;
	}
}

void ft_add_and_handling(char **argv, t_stack **a)
{
	int 	i;
	char	**mass;

	i = 1;
	while (argv[i])
	{
		mass = ft_split(argv[i], ' ');
		ft_check_digit(mass);
		ft_add_to_list(mass, a);
		free(mass);
		i++;
	}
	ft_check_duplicate(a);

}