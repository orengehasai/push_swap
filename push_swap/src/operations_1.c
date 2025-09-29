/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takenakatakeshiichirouta <takenakatakes    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:24:39 by takenakatak       #+#    #+#             */
/*   Updated: 2025/09/29 13:26:04 by takenakatak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_list *source_stack, t_list *dest_stack)
{
	t_list	*head_source;
	t_list	*second_source;
	t_list	*head_dest;

	if (dest_stack->content == STACK_A)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
	head_source = source_stack->next;
	if (!head_source)
		return ;
	head_dest = dest_stack->next;
	second_source = head_source->next;
	source_stack->next = second_source;
	if (second_source)
		second_source->back = source_stack;
	head_source->next = head_dest;
	if (head_dest)
		head_dest->back = head_source;
	dest_stack->next = head_source;
	head_source->back = dest_stack;
}

void	rotate(t_list *sentinel)
{
	t_list	*head;
	t_list	*second;
	t_list	*end;

	if (sentinel->content == STACK_A)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
	head = sentinel->next;
	if (!head || !head->next)
		return ;
	second = head->next;
	end = ft_lstlast(head);
	sentinel->next = second;
	second->back = sentinel;
	head->next = NULL;
	head->back = end;
	end->next = head;
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	t_list	*head;
	t_list	*second;
	t_list	*end;
	t_list	*sentinel;
	int		i;

	ft_printf("rr\n");
	i = 0;
	sentinel = stack_a;
	while (i++ < 2)
	{
		head = sentinel->next;
		if (!head || !head->next)
			return ;
		second = head->next;
		end = ft_lstlast(head);
		sentinel->next = second;
		second->back = sentinel;
		head->next = NULL;
		head->back = end;
		end->next = head;
		sentinel = stack_b;
	}
}

void	reverse_rotate(t_list *sentinel)
{
	t_list	*head;
	t_list	*second_from_end;
	t_list	*end;

	if (sentinel->content == STACK_A)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
	head = sentinel->next;
	if (!head || !head->next)
		return ;
	end = ft_lstlast(head);
	second_from_end = end->back;
	sentinel->next = end;
	end->back = sentinel;
	end->next = head;
	head->back = end;
	second_from_end->next = NULL;
}

void	rrr(t_list *stack_a, t_list *stack_b)
{
	t_list	*head;
	t_list	*second_from_end;
	t_list	*end;
	t_list	*sentinel;
	int		i;

	ft_printf("rrr\n");
	i = 0;
	sentinel = stack_a;
	while (i++ < 2)
	{
		head = sentinel->next;
		if (!head || !head->next)
			return ;
		end = ft_lstlast(head);
		second_from_end = end->back;
		sentinel->next = end;
		end->back = sentinel;
		end->next = head;
		head->back = end;
		second_from_end->next = NULL;
		sentinel = stack_b;
	}
}
