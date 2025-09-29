/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takenakatakeshiichirouta <takenakatakes    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 02:36:50 by takenakatak       #+#    #+#             */
/*   Updated: 2025/09/29 13:27:35 by takenakatak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	count_words(char const *s, char c)
{
	int	cntwords;
	int	is_not_c;

	cntwords = 0;
	while (*s)
	{
		is_not_c = 0;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			s++;
			is_not_c = 1;
		}
		if (is_not_c)
			cntwords++;
	}
	return (cntwords);
}

static int	*count_lens(char const *s, char c, int cntwords)
{
	int	*res;
	int	index;

	res = malloc(sizeof(int) * cntwords);
	if (!res)
		return (NULL);
	index = 0;
	while (*s)
	{
		res[index] = 0;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			res[index]++;
			s++;
		}
		index++;
	}
	return (res);
}

static char	**set_strs(char const *s, char c, int cntwords, int *cntlens)
{
	int		index;
	int		instrindex;
	char	**strs;

	strs = malloc(sizeof(char *) * (cntwords + 1));
	if (!strs)
		return (NULL);
	index = -1;
	while (++index < cntwords)
	{
		instrindex = 0;
		strs[index] = malloc(sizeof(char) * (cntlens[index] + 1));
		if (!strs[index])
			return (free_split(strs));
		strs[index][cntlens[index]] = '\0';
		while (*s == c)
			s++;
		while (*s != c && *s)
			strs[index][instrindex++] = *s++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c, int *ac)
{
	int		cntwords;
	int		*cntlens;
	char	**res;

	if (!s)
		return (NULL);
	cntwords = count_words(s, c);
	cntlens = count_lens(s, c, cntwords);
	if (!cntlens)
		return (NULL);
	res = set_strs(s, c, cntwords, cntlens);
	free(cntlens);
	if (!res)
		return (NULL);
	res[cntwords] = NULL;
	*ac = cntwords;
	return (res);
}
