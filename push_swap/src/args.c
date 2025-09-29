/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takenakatakeshiichirouta <takenakatakes    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 02:30:44 by takenakatak       #+#    #+#             */
/*   Updated: 2025/09/29 14:13:12 by takenakatak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	my_atoi(const char *str, t_program p)
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
		print_error(p);
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	res *= sign;
	if (res < INT_MIN || res > INT_MAX)
		print_error(p);
	if (*str != '\0')
		print_error(p);
	return ((int)res);
}

t_dict	*dict_maker(t_program p)
{
	int		i;

	p.dict = malloc(sizeof(t_dict) * p.args.ac);
	if (!p.dict)
		print_error(p);
	i = 0;
	while (i < p.args.ac)
	{
		(p.dict[i]).original_index = i;
		(p.dict[i]).value = my_atoi(p.args.av[i], p);
		i++;
	}
	return (p.dict);
}

void	check_duplicates(t_program p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p.args.ac)
	{
		j = i + 1;
		while (j < p.args.ac)
		{
			if (p.dict[i].value == p.dict[j].value)
				print_error(p);
			j++;
		}
		i++;
	}
}

t_dict	*sort(t_program p)
{
	int		i;
	int		j;
	t_dict	tmp;

	i = 0;
	while (i < p.args.ac - 1)
	{
		j = 0;
		while (j < p.args.ac - 1 - i)
		{
			if (p.dict[j].value > p.dict[j + 1].value)
			{
				tmp = p.dict[j];
				p.dict[j] = p.dict[j + 1];
				p.dict[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (p.dict);
}

int	is_originally_sorted(t_program p)
{
	int	i;

	i = 0;
	while (i < p.args.ac)
	{
		if (p.dict[i].original_index != i)
			return (0);
		i++;
	}
	return (1);
}
