/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takenakatakeshiichirouta <takenakatakes    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:25:54 by takenakatak       #+#    #+#             */
/*   Updated: 2025/05/05 11:45:23 by takenakatak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_x(int n, char spe)
{
	int				cnt;
	int				is_init_zeros;
	char			*base;

	cnt = 0;
	is_init_zeros = 0;
	if (spe == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	put_hex((unsigned int)n, base, &cnt, &is_init_zeros);
	return (cnt);
}
