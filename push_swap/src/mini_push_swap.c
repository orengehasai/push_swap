#include "../includes/push_swap.h"

void sort_two(t_list *sentinel_a)
{
	t_list *top;
	t_list *second;

	top = sentinel_a->next;
	second = top->next;
	if (top->content > second->content)
		swap(sentinel_a);
	return;
}
void sort_three(t_list *sentinel_a)
{
	t_list *top;
	t_list *second;
	int		max_rank;

	max_rank = 2;
    top = sentinel_a->next;
    second = top->next;
	if (top->content == max_rank)
		rotate(sentinel_a);
	else if (second->content)
		reverse_rotate(sentinel_a);
	top = sentinel_a->next;
    if (top->content > top->next->content)
        swap(sentinel_a);
}

static int is_sorted(t_list *sentinel_a)
{
	t_list *head;

	head = sentinel_a->next;
    while (head->next)
    {
        if (head->content > head->next->content)
            return (0);
        head = head->next;
    }
    return (1);
}

void	sort_five(t_list *sentinel_a, t_list *sentinel_b)
{
    int size;
    int pushed_count;
    int threshold;

    size = ft_lstsize(sentinel_a) - 1;
    pushed_count = 0;
    threshold = size - 3;
    while (pushed_count < threshold)
    {
        if (sentinel_a->next->content < threshold)
        {
            push(sentinel_a, sentinel_b);
            pushed_count++;
        }
        else
            rotate(sentinel_a);
    }
    if (!is_sorted(sentinel_a))
        sort_three(sentinel_a);
    while (pushed_count > 0)
    {
        push(sentinel_b, sentinel_a);
        pushed_count--;
    }
	if (sentinel_a->next->content > sentinel_a->next->next->content)
        swap(sentinel_a);
}