/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <mmonarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:03:37 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/08 15:49:13 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_struct
{
	int	minus;
	int	zero;
	int	widht;
	int	tochka;
	int	precsion;
	int	ch;
	int	hex;
}		t_struct;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	*ft_memset(void *mass, int a, size_t b);
int		ft_isalpha(int a);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *last, const void *mass, size_t n);
void	*ft_memccpy(void *dast, const void *cat, int c, size_t n);
void	*ft_memmove(void *dst, const void *stc, size_t len);
void	*ft_memchr(const void *arr, int c, size_t n);
int		ft_memcmp(const void *arr, const void *arr2, size_t n);
size_t	ft_strlen(const char *str);
int		get_next_line(int fd, char **line);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isnotprint(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t nb);
size_t	ft_strlcat(char *dst, const char *src, size_t nb);
char	*ft_strnstr(const char *haystack, const char*needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_itoa(int n);
char	*ft_strtrim(const char *s, const char *set);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char ));
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(const char *s, char c);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_printf(const char *format, ...);
int		ft_parsing_flag(char **mass, va_list arg);
int		ft_type(char **mass, t_struct *flag, va_list arg);
int		ft_print_d(t_struct *flag, va_list arg);
int		ft_add_flag(t_struct *flag, long long nb);
int		ft_print_negative(t_struct *flag, long long nb, int toch, int shir);
void	ft_putnbr_printf(long long n, int fd);
int		ft_count(long long b);
int		ft_print_s(t_struct *flag, va_list arg);
int		ft_print_c(t_struct *flag, va_list arg, char **mass);
int		ft_print_ptr(t_struct *flag, va_list arg);
int		ft_strchr_printf(const char *s, int c);
int		ft_print_u(t_struct *flag, va_list arg);
int		ft_count_ptr(unsigned long adres);
void	ft_putnbr_hex(unsigned long adres, t_struct *flag);
int		ft_print_xxx(t_struct *flag, va_list arg, char **mass);
#endif
