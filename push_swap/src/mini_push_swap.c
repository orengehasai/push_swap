/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takenakatakeshiichirouta <takenakatakes    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:07:01 by takenakatak       #+#    #+#             */
/*   Updated: 2025/09/29 14:10:55 by takenakatak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_list *stack_a)
{
	t_list	*top;
	t_list	*second;

	top = stack_a->next;
	second = top->next;
	if (top->content > second->content)
		swap(stack_a);
	return ;
}

void	sort_three(t_list *stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = stack_a->next->content;
	middle = stack_a->next->next->content;
	bottom = stack_a->next->next->next->content;
	if (top > middle && middle < bottom && top < bottom)
		swap(stack_a);
	else if (top > middle && middle > bottom)
	{
		swap(stack_a);
		reverse_rotate(stack_a);
	}
	else if (top > middle && middle < bottom && top > bottom)
		rotate(stack_a);
	else if (top < middle && middle > bottom && top < bottom)
	{
		swap(stack_a);
		rotate(stack_a);
	}
	else if (top < middle && middle > bottom && top > bottom)
		reverse_rotate(stack_a);
}

static int	is_sorted(t_list *stack_a)
{
	t_list	*head;

	head = stack_a->next;
	while (head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

void	sort_five(t_list *stack_a, t_list *stack_b)
{
	int	size;
	int	pushed_count;
	int	threshold;

	size = ft_lstsize(stack_a) - 1;
	pushed_count = 0;
	threshold = size - 3;
	while (pushed_count < threshold)
	{
		if (stack_a->next->content < threshold)
		{
			push(stack_a, stack_b);
			pushed_count++;
		}
		else
			rotate(stack_a);
	}
	if (!is_sorted(stack_a))
		sort_three(stack_a);
	while (pushed_count-- > 0)
		push(stack_b, stack_a);
	if (stack_a->next->content > stack_a->next->next->content)
		swap(stack_a);
}
