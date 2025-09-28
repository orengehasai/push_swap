/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takenakatakeshiichirouta <takenakatakes    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:25:59 by takenakatak       #+#    #+#             */
/*   Updated: 2025/05/05 11:48:35 by takenakatak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	put_hex(uintptr_t num, char *base, int *cnt, int *is_init_zeros)
{
	char	c;

	if (num == 0)
		return ((void)((*cnt) += write(1, "0", 1)));
	if (num >= 16)
		put_hex(num / 16, base, cnt, is_init_zeros);
	c = base[num % 16];
	if (c != '0')
		*is_init_zeros = 1;
	if (*is_init_zeros)
		(*cnt) += write(1, &c, 1);
}

void	put_nbr(long int num, int *cnt)
{
	char	c;

	if (num < 0)
	{
		(*cnt) += write(1, "-", 1);
		num *= -1;
	}
	if (num >= 10)
		put_nbr(num / 10, cnt);
	c = num % 10 + '0';
	(*cnt) += write(1, &c, 1);
}

// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
// 	int n = -311341;
// 	printf("%x\n",n);
// 	int cnt = 0;
// 	int is_init_zeros = 0;

// 	//write(1,"0x",2);
// 	int res = put_hex((unsigned int)n, "0123456789abcdef",&cnt, &is_init_zeros);
// 	printf("\n%d\n",res);
// 	return 0;
// }
