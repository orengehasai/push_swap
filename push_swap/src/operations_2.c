#include "../includes/push_swap.h"

void swap(t_list *sentinel)
{
	t_list *head;
	t_list *second;
	t_list *third;

	if (sentinel->content == STACK_A)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
	head = sentinel->next;
	if (!head || !head->next)
		return;
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

void ss(t_list *sentinel_a, t_list *sentinel_b)
{
	t_list *head;
	t_list *second;
	t_list *third;
	t_list *sentinel;
	int		i;

	ft_printf("ss\n");
	i = 0;
	sentinel = sentinel_a;
	while(i++ < 2)
	{
		head = sentinel->next;
		if (!head || !head->next)
			return;
		second = head->next;
		third = second->next;
		head->back = second;
		head->next = third;
		if (third)
			third->back = head;
		second->back = sentinel;
		second->next = head;
		sentinel->next = second;
		sentinel = sentinel_b;
	}
}