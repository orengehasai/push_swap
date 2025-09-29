/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takenakatakeshiichirouta <takenakatakes    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 02:40:19 by takenakatak       #+#    #+#             */
/*   Updated: 2025/09/29 14:04:49 by takenakatak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_handler(t_program p, int size)
{
	if (size <= 1)
		return ;
	else if (size == 2)
		sort_two(p.stack_a);
	else if (size == 3)
		sort_three(p.stack_a);
	else if (size <= 5)
		sort_five(p.stack_a, p.stack_b);
	else
		ft_radixsort(p.stack_a, p.stack_b, max_bits(p.stack_a));
}

static t_list	*create_stack(t_program p)
{
	int		i;
	int		content;
	t_list	*current_node;
	t_list	*new_node;

	p.stack_a = ft_lstnew(STACK_A);
	if (!p.stack_a)
		print_error(p);
	i = 0;
	current_node = p.stack_a;
	while (i < p.args.ac)
	{
		content = p.dict[i].key;
		new_node = ft_lstnew(content);
		if (!new_node)
			print_error(p);
		current_node->next = new_node;
		new_node->back = current_node;
		current_node = current_node -> next;
		i++;
	}
	return (p.stack_a);
}

static t_dict	*validate_and_create_ranks(t_program p)
{
	p.dict = dict_maker(p);
	check_duplicates(p);
	p.dict = sort(p);
	if (is_originally_sorted(p))
	{
		free(p.dict);
		p.dict = NULL;
		return (NULL);
	}
	p.dict = originate(p);
	return (p.dict);
}

static t_args	init_args(int main_ac, char *main_av[], t_program p)
{
	t_args	args;

	if (main_ac == 1)
		exit(EXIT_FAILURE);
	else if (main_ac == 2)
	{
		args.needs_free = 1;
		args.av = ft_split(main_av[1], ' ', &args.ac);
		if (!args.av)
			print_error(p);
	}
	else
	{
		args.needs_free = 0;
		args.ac = main_ac - 1;
		args.av = main_av + 1;
	}
	return (args);
}

int	main(int ac, char *av[])
{
	t_program	p;

	ft_bzero(&p, sizeof(t_program));
	p.args = init_args(ac, av, p);
	p.dict = validate_and_create_ranks(p);
	if (!p.dict)
	{
		if (p.args.needs_free)
			free_split(p.args.av);
		return (0);
	}
	p.stack_a = create_stack(p);
	free(p.dict);
	p.dict = NULL;
	p.stack_b = ft_lstnew(STACK_B);
	if (!p.stack_b)
		print_error(p);
	sort_handler(p, ft_lstsize(p.stack_a) - 1);
	if (p.args.needs_free)
		p.args.av = free_split(p.args.av);
	return (ft_lstclear(&p.stack_a), ft_lstclear(&p.stack_b), 0);
}
