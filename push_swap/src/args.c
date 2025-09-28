#include "../push_swap.h"

int	my_atoi(const char *str, t_dict *i_array, t_args args)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	if (*str == '-')
	{
		sign *= (-1);
		str++;
	}
	if (ft_strlen(str) > 10)
		print_error("Some arguments exceed the int limits or is not integers.", NULL, i_array, args);
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	res *= sign;
	if (res < INT_MIN || res >INT_MAX)
		print_error("Some arguments exceed the int limits.", NULL, i_array, args);
	if(*str != '\0')
		print_error("Some arguments are not integers.", NULL, i_array, args);
	return ((int)res);
}

t_dict *dict_maker(t_args args)
{
	t_dict	*i_array;
	int	i;

	i_array = malloc(sizeof(t_dict) * args.ac);
	if (!i_array)
		print_error("memory allocation failed.", NULL, NULL, args);
	i = 0;
	while(i < args.ac)
	{
		(i_array[i]).original_index = i;
		(i_array[i]).value = my_atoi(args.av[i], i_array, args);
		// ft_printf("i : %d, key : %d, value : %d, original index : %d\n", i,(i_array[i]).key, (i_array[i]).value, (i_array[i]).original_index);
		i++;
	}
	return (i_array);
}

t_dict *sort(int ac, t_dict *original_dict)
{
	int		i;
	int		j;
	t_dict	tmp;

	i = 0;
	while(i < ac - 1)
	{
		j = 0;
		while(j < ac - 1 - i)
		{
			if (original_dict[j].value > original_dict[j + 1].value)
			{
				tmp = original_dict[j];
				original_dict[j] = original_dict[j + 1];
				original_dict[j + 1]= tmp;
			}
			j++;
		}
		i++;
	}
	return (original_dict);
}

int	is_originally_sorted(int ac, t_dict *sorted_dict)
{
	int i;

	i = 0;
	while(i < ac)
	{
		if (sorted_dict[i].original_index != i)
			return (0);
		i++;
	}
	return (1);
}

t_dict *originate(int ac, t_dict *sorted_dict)
{
	int i;
	int original_index;
	t_dict	tmp[ac];

	i = 0;
	while (i < ac)
	{
		sorted_dict[i].key = i;
		i++;
	}
	i = 0;
	while (i < ac)
	{
		original_index = sorted_dict[i].original_index;
		tmp[original_index] = sorted_dict[i];
		i++;
	}
	i = 0;
	while (i < ac)
	{
		sorted_dict[i] = tmp[i];
		i++;
	}
	// i = 0;
	// ft_printf("sorting completed\n");
	// while (i < ac)
	// {
	// 	ft_printf("key : %d, original_index : %d, value : %d\n", sorted_dict[i].key, sorted_dict[i].original_index, sorted_dict[i].value);
	// 	i++;
	// }
	return (sorted_dict);
}
