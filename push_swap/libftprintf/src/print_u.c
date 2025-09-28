/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takenakatakeshiichirouta <takenakatakes    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:25:51 by takenakatak       #+#    #+#             */
/*   Updated: 2025/05/05 11:44:45 by takenakatak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_u(unsigned int n)
{
	int	cnt;

	cnt = 0;
	put_nbr((long int)n, &cnt);
	return (cnt);
}
