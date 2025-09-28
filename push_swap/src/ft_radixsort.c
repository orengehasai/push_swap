#include "../push_swap.h"

void 	ft_radixsort(t_list *sentinel_a, t_list *sentinel_b, int max_bits)
{
	int		i;
	int		j;
	int		size;
	t_list	*head_node;

	i = 0;
	while(i < max_bits)
	{
		j = 0;
		size = ft_lstsize(sentinel_a) - 1 ;
		while(j < size)
		{
			head_node = sentinel_a->next;
			if (((head_node -> content >> i) & 1) == 1)
				rotate(sentinel_a);
			else
				push(sentinel_a, sentinel_b);
			j++;
		}
		while (ft_lstsize(sentinel_b) > 1)
            push(sentinel_b, sentinel_a);
        i++;
	}
}

int ft_max(int a, int b)
{
	if(a < b)
		return (b);
	else
		return (a);
}

int max_bits(t_list *sentinel_stack_a)
{
	t_list *current_node;
	int	max_num;
	int	max_bits;

	current_node = sentinel_stack_a->next;
	max_num = current_node->content;
	while(current_node->next)
	{
		current_node = current_node->next;
		max_num = ft_max(max_num, current_node->content);
	}
	max_bits = 0;
	while((max_num >> max_bits) != 0)
		max_bits++;
	return max_bits;
}