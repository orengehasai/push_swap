/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takenakatakeshiichirouta <takenakatakes    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:05:03 by takenakatak       #+#    #+#             */
/*   Updated: 2025/09/29 14:05:44 by takenakatak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list *sentinel)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;

	if (sentinel->content == STACK_A)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
	head = sentinel->next;
	if (!head || !head->next)
		return ;
	second = head->next;
	third = second->next;
	head->back = second;
	head->next = third;
	if (third)
		third->back = head;
	second->back = sentinel;
	second->next = head;
	sentinel->next = second;
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;
	t_list	*sentinel;
	int		i;

	ft_printf("ss\n");
	i = 0;
	sentinel = stack_a;
	while (i++ < 2)
	{
		head = sentinel->next;
		if (!head || !head->next)
			return ;
		second = head->next;
		third = second->next;
		head->back = second;
		head->next = third;
		if (third)
			third->back = head;
		second->back = sentinel;
		second->next = head;
		sentinel->next = second;
		sentinel = stack_b;
	}
}
