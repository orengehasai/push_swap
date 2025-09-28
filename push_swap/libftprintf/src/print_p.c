/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takenakatakeshiichirouta <takenakatakes    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:25:44 by takenakatak       #+#    #+#             */
/*   Updated: 2025/05/05 11:44:28 by takenakatak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_p(void *p)
{
	int		cnt;
	int		is_init_zeros;
	char	*base;

	cnt = write(1, "0x", 2);
	is_init_zeros = 0;
	base = "0123456789abcdef";
	put_hex((uintptr_t)p, base, &cnt, &is_init_zeros);
	return (cnt);
}
