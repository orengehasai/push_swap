/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radixsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takenakatakeshiichirouta <takenakatakes    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 02:38:09 by takenakatak       #+#    #+#             */
/*   Updated: 2025/09/29 14:06:36 by takenakatak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_radixsort(t_list *stack_a, t_list *stack_b, int max_bits)
{
	int		i;
	int		j;
	int		size;
	t_list	*head_node;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = ft_lstsize(stack_a) - 1 ;
		while (j < size)
		{
			head_node = stack_a->next;
			if (((head_node -> content >> i) & 1) == 1)
				rotate(stack_a);
			else
				push(stack_a, stack_b);
			j++;
		}
		while (ft_lstsize(stack_b) > 1)
			push(stack_b, stack_a);
		i++;
	}
}

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	max_bits(t_list *stack_a)
{
	t_list	*current_node;
	int		max_num;
	int		max_bits;

	current_node = stack_a->next;
	max_num = current_node->content;
	while (current_node->next)
	{
		current_node = current_node->next;
		max_num = ft_max(max_num, current_node->content);
	}
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
