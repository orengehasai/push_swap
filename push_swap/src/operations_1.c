#include "../includes/push_swap.h"

void push(t_list *sentinel_source, t_list *sentinel_dest)
{
	t_list *head_source;
	t_list *second_source;
	t_list *head_dest;


	if (sentinel_dest->content == STACK_A)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
	head_source = sentinel_source->next;
	if (!head_source)
		return;
	head_dest = sentinel_dest->next;
	second_source = head_source->next;
	sentinel_source->next = second_source;
	if (second_source)
		second_source->back = sentinel_source;
	head_source->next = head_dest;
	if (head_dest)
		head_dest->back = head_source;
	sentinel_dest->next = head_source;
	head_source->back = sentinel_dest;
}

void rotate(t_list *sentinel)
{
	t_list *head;
	t_list *second;
	t_list *end;

	if (sentinel->content == STACK_A)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
	head = sentinel->next;
	if (!head || !head->next)
		return;
	second = head->next;
	end = ft_lstlast(head);
	sentinel->next = second;
	second->back = sentinel;
	head->next = NULL;
	head->back = end;
	end->next = head;
}

void rr(t_list *sentinel_a, t_list *sentinel_b)
{
	t_list *head;
	t_list *second;
	t_list *end;
	t_list *sentinel;
	int		i;

	ft_printf("rr\n");
	i = 0;
	sentinel = sentinel_a;
	while(i++ < 2)
	{
		head = sentinel->next;
		if (!head || !head->next)
			return;
		second = head->next;
		end = ft_lstlast(head);
		sentinel->next = second;
		second->back = sentinel;
		head->next = NULL;
		head->back = end;
		end->next = head;
		sentinel = sentinel_b;
	}
}

void reverse_rotate(t_list *sentinel)
{
	t_list *head;
	t_list *second_from_end;
	t_list *end;

	if (sentinel->content == STACK_A)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");

	head = sentinel->next;
	if (!head || !head->next)
		return;
	end = ft_lstlast(head);
	second_from_end = end->back;
	sentinel->next = end;
	end->back = sentinel;
	end->next = head;
	head->back = end;
	second_from_end->next = NULL;
}

void rrr(t_list *sentinel_a, t_list *sentinel_b)
{
	t_list *head;
	t_list *second_from_end;
	t_list *end;
	t_list *sentinel;
	int		i;

	ft_printf("rrr\n");
	i = 0;
	sentinel = sentinel_a;
	while(i++ < 2)
	{
		head = sentinel->next;
		if (!head || !head->next)
			return;
		end = ft_lstlast(head);
		second_from_end = end->back;
		sentinel->next = end;
		end->back = sentinel;
		end->next = head;
		head->back = end;
		second_from_end->next = NULL;
		sentinel = sentinel_b;
	}
}



// int main(void)
// {
// 	t_list	*head;
// 	t_list	*current;
// 	t_list	*back_node;
// 	t_list	*b_head;

// 	head = ft_lstnew(-100);
// 	b_head = ft_lstnew(-99);
// 	current = head;
// 	for (int i = 0 ; i < 3 ; i++){
// 		current->next = ft_lstnew(i);
// 		back_node = current;
// 		current = current->next;
// 		current->back = back_node;
// 	}
// 	current = b_head;
// 	for (int i = 0 ; i < 5 ; i++){
// 		current->next = ft_lstnew(i);
// 		back_node = current;
// 		current = current->next;
// 		current->back = back_node;
// 	}

// 	push(head, b_head);

// 	current = head;
// 	while (current)
// 	{
// 		printf("stack_a : %d\n",current->content);
// 		current = current->next;
// 	}
// 	current = b_head;
// 	while (current)
// 	{
// 		printf("stack_b : %d\n",current->content);
// 		current = current->next;
// 	}
// 	printf("\n");
// 	current = ft_lstlast(b_head);
// 	while(current)
// 	{
// 		printf("stack_b : %d\n",current->content);
// 		current = current->back;
// 	}
// 	current = ft_lstlast(head);
// 	while(current)
// 	{
// 		printf("stack_a : %d\n",current->content);
// 		current = current->back;
// 	}
// }