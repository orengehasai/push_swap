/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takenakatakeshiichirouta <takenakatakes    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 02:37:40 by takenakatak       #+#    #+#             */
/*   Updated: 2025/09/29 14:28:07 by takenakatak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(t_program p)
{
	if (p.stack_a)
		ft_lstclear(&p.stack_a);
	if (p.dict)
		free(p.dict);
	if (p.args.needs_free)
		free_split(p.args.av);
	ft_printf(RED "Error" RESET "\n");
	exit(EXIT_FAILURE);
}

size_t	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (*s != '\0')
	{
		s++;
		cnt++;
	}
	return (cnt);
}

char	**free_split(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		av[i] = NULL;
		i++;
	}
	free(av);
	av = NULL;
	return (NULL);
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
		*str++ = 0;
}
