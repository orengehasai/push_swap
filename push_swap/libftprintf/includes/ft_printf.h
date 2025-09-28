/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takenakatakeshiichirouta <takenakatakes    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:32:38 by takenakatak       #+#    #+#             */
/*   Updated: 2025/05/05 18:18:47 by takenakatak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);

int		print_c(char c);

int		print_di(int n);

int		print_p(void *p);

int		print_s(char *str);

int		print_u(unsigned int n);

int		print_x(int n, char spe);

void	put_hex(unsigned long int num, char *base\
				, int *cnt, int *is_init_zeros);

void	put_nbr(long int num, int *cnt);

#endif