/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takenakatakeshiichirouta <takenakatakes    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:33:26 by takenakatak       #+#    #+#             */
/*   Updated: 2025/09/29 13:34:47 by takenakatak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dict	*originate(t_program p)
{
	int		i;
	t_dict	*tmp;

	tmp = malloc(sizeof(t_dict) * p.args.ac);
	if (!tmp)
		print_error(p);
	i = 0;
	while (i < p.args.ac)
	{
		p.dict[i].key = i;
		i++;
	}
	i = 0;
	while (i < p.args.ac)
	{
		tmp[p.dict[i].original_index] = p.dict[i];
		i++;
	}
	i = 0;
	while (i < p.args.ac)
	{
		p.dict[i] = tmp[i];
		i++;
	}
	return (free(tmp), p.dict);
}
