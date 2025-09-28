#include "../includes/push_swap.h"

#include <stdio.h>
static void	check_duplicates(t_args args, t_dict *original_dict)
{
	int	i;
	int	j;

	i = 0;
	while(i < args.ac)
	{
		j = i + 1;
		while(j < args.ac)
		{
			// printf("i : %d, j : %d\n", original_dict[i].value, original_dict[j].value);
			if (original_dict[i].value == original_dict[j].value)
				print_error("Some arguments are the same.", NULL, NULL, args);
			j++;
		}
		i++;
	}
}

static t_list	*create_stack(t_dict *dict, t_args args)
{
	int		i;
	int		content;
	t_list  *current_node;
	t_list	*sentinel;
	t_list	*new_node;

	sentinel = ft_lstnew(STACK_A);
	if (!sentinel)
		print_error("memory allocation failed.", NULL, dict, args);
	i = 0;
	current_node = sentinel;
	while(i < args.ac)
	{
		content = dict[i].key;
		new_node = ft_lstnew(content);
		if(!new_node)
			print_error("memory allocation failed.", sentinel, dict, args);
		current_node->next = new_node;
		new_node->back = current_node;
		current_node = current_node -> next;
		i++;
	}
	return (sentinel);
}

static t_dict *validate_and_create_ranks(t_args args)
{
	t_dict *original_dict;
	t_dict *sorted_dict;
	t_dict *ranked_dict;

	original_dict = dict_maker(args);
	check_duplicates(args, original_dict);
	sorted_dict = sort(args.ac, original_dict);
	if (is_originally_sorted(args.ac, sorted_dict))
	{
		free(original_dict);
		original_dict = NULL;
		sorted_dict = NULL;
		return (NULL);
	}
	ranked_dict = originate(args.ac, sorted_dict);
	return (ranked_dict);
}

static t_args  init_args(int main_ac, char *main_av[])
{
    t_args  args;

	if (main_ac == 1)
		exit(EXIT_FAILURE);
    else if (main_ac == 2)
    {
		args.needs_free = 1;
        args.av = ft_split(main_av[1], ' ', &args.ac);
        if (!args.av)
            print_error("memory allocation failed", NULL, NULL, args);
    }
    else
    {
        args.needs_free = 0;
        args.ac = main_ac - 1;
        args.av = main_av + 1;
    }
    return (args);
}

void    sort_handler(t_list *sentinel_a, t_list *sentinel_b, int size)
{
    if (size <= 1)
		return;
    else if (size == 2)
        sort_two(sentinel_a);
    else if (size == 3)
        sort_three(sentinel_a);
    else if (size <= 5)
        sort_five(sentinel_a, sentinel_b);
    else
        ft_radixsort(sentinel_a, sentinel_b, max_bits(sentinel_a));
}

int	main(int ac, char *av[])
{
	t_list	*sentinel_a;
	t_list	*sentinel_b;
	t_dict	*ranked_dict;
	t_args	args;

	args = init_args(ac, av);
	ranked_dict = validate_and_create_ranks(args);
	if (!ranked_dict)
    {
        if (args.needs_free)
            free_split(args.av);
        return (0);
    }
	sentinel_a = create_stack(ranked_dict, args);
	free(ranked_dict);
	ranked_dict = NULL;
	sentinel_b = ft_lstnew(STACK_B);
	if (!sentinel_b)
		print_error("memory allocation failed.", sentinel_a, NULL, args);
	sort_handler(sentinel_a, sentinel_b, ft_lstsize(sentinel_a) - 1);
	if (args.needs_free)
		args.av = free_split(args.av);
	return (ft_lstclear(&sentinel_a), ft_lstclear(&sentinel_b), 0);
}