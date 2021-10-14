#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	int 			number;
	int 			index;
	int 			markup;
	int 			num_markup;
	int 			position;
	int 			step_up;
	struct s_stack	*next;
}	t_stack;

void	error(char *str);
void	ft_check_digit(char **mass);
void	ft_add_and_handling(char **argv, t_stack **a);
void	ft_push_to_stack(char *str, t_stack **from, t_stack **to);
void	ft_swap(char *str, t_stack **stack);
void	ft_swap_ss(char *str, t_stack **a, t_stack **b);
void	ft_rotate(char *str, t_stack **stack);
void	ft_rotate_rr(char *str, t_stack **a, t_stack **b);
void	ft_revers_rotate(char *str, t_stack **stack);
void	ft_revers_rotate_rrr(char *str, t_stack **a, t_stack **b);
void	ft_index(t_stack **a);
void	ft_markup(t_stack **a);
void	ft_sort(t_stack **a, t_stack **b);
void	ft_add_markup(t_stack **head, t_stack **a);
void	ft_big_markup(int index, t_stack **a);
int		ft_need_swap(int index, t_stack **a);
void	ft_add_new_markup(int index, t_stack **a);
void	ft_position(t_stack **stack);
int		ft_size(t_stack **stack);
void	ft_sort_back(t_stack **a, t_stack **b);
int		ft_last_index(t_stack **stack);
#endif
