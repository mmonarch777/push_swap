#include "push_swap.h"
#include <stdio.h>

void 	*ft_lstnew_ps(int number)
{
	t_stack	*stack;

	stack = malloc(sizeof (t_stack));
	if (!stack)
		return (NULL);
	stack->number = number;
	stack->next = NULL;
	return (stack);
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

void	ft_add_to_list(int *integer, int size, t_stack **a)
{
	t_stack	*head;
	int 	i;

	i = 0;
	if (!*a)
	{
		*a = ft_lstnew_ps(integer[i]);
		i++;
	}
	head = *a;
	while (size > i)
	{
		printf("%d\n", head->number);
		head->next = ft_lstnew_ps(integer[i]);
		i++;
		head = head->next;
	}
	printf("%d\n", head->number);
}

static int	ft_find_number(char **argv)
{
	char	**mass;
	int 	size;
	int		i;
	int 	j;

	i = 1;
	size = 0;
	while (argv[i])
	{
		j = 0;
		mass = ft_split(argv[i], ' ');
		while (mass[j])
		{
			ft_check_digit(mass);
			free(mass[j]);
			j++;
			size++;
		}
		free(mass);
		i++;
	}
	return (size);
}

static void	ft_add_to_integer(char **argv, int *integer)
{
	char	**mass;
	int		i;
	int 	j;
	int		num;

	i = 1;
	num = 0;
	while (argv[i])
	{
		j = 0;
		mass = ft_split(argv[i], ' ');
		while (mass[j])
		{
			integer[num] = ft_atoi_long(mass[j]);
			free(mass[j]);
			num++;
			j++;
		}
		i++;
		free(mass);
	}
}

void	ft_check_duplicat(int *integer, int number)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while(i < number)
	{
		j = i + 1;
		while (j < number)
		{
			if (integer[i] == integer[j])
				error("I can't work with duplicates :(");
			j++;
		}
		i++;
	}
}

void	ft_check_sort(t_stack **a)
{
	t_stack	*head;
	int 	numb;

	head = *a;
	numb = head->number;
	head = head->next;
	while (head)
	{
		if (numb < head->number)
			numb = head->number;
		else
			return ;
		head = head->next;
	}
	error("Stack sorted");
}
void	ft_add_and_handling(char **argv, t_stack **a)
{
	int 	i;
	int 	number;
	int 	*integer;

	number = ft_find_number(argv);
	integer = malloc(sizeof (int) * number);
	ft_add_to_integer(argv, integer);
	ft_check_duplicat(integer, number);
//	while (number-- > 0)
//		ft_printf("%d\n", *integer++);
	ft_add_to_list(integer, number, a);
	ft_check_sort(a);
}