#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define RED		"\x1b[31m"
#define BRED	"\x1b[101m"
#define GREEN	"\x1b[32m"
#define RESET	"\x1b[0m"
#define STACK_A	0
#define STACK_B	1

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>
// #include "./libftprintf/libft/libft.h"
#include "./libftprintf/includes/ft_printf.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*back;
}	t_list;

typedef struct s_dict
{
	int original_index;
	int key;
	int value;
}	t_dict;

typedef struct s_args
{
    int     ac;
    char    **av;
    int     needs_free;
}   t_args;

int	my_atoi(const char *str, t_dict *i_array, t_args args);

t_dict *dict_maker(t_args args);

t_dict *sort(int ac, t_dict *original_dict);

int	is_originally_sorted(int ac, t_dict *sorted_dict);

t_dict *originate(int ac, t_dict *sorted_dict);

void 	ft_radixsort(t_list *sentinel_a, t_list *sentinel_b, int max_bit);

int ft_max(int a, int b);

int max_bits(t_list *sentinel_stack_a);

char	**ft_split(char const *s, char c, int *ac);

t_list	*ft_lstnew(int content);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstclear(t_list **lst);

int	ft_lstsize(t_list *lst);

void push(t_list *sentinel_source, t_list *sentinel_dest);

void rotate(t_list *sentinel);

void rr(t_list *sentinel_a, t_list *sentinel_b);

void reverse_rotate(t_list *sentinel);

void rrr(t_list *sentinel_a, t_list *sentinel_b);

void swap(t_list *sentinel);

void ss(t_list *sentinel_a, t_list *sentinel_b);

void	print_error(char *massage, t_list *sentinel, t_dict *dict, t_args args);

size_t	ft_strlen(const char *s);

char **free_split(char **av);

int	ft_isdigit(int c);

void sort_two(t_list *sentinel_a);

void sort_three(t_list *sentinel_a);

void	sort_five(t_list *sentinel_a, t_list *sentinel_b);

void    sort_handler(t_list *sentinel_a, t_list *sentinel_b, int size);

#endif