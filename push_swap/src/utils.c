#include "../push_swap.h"

void	print_error(char *massage, t_list *sentinel, t_dict *dict, t_args args)
{
	char *std_error_message;

	if (sentinel)
		ft_lstclear(&sentinel);
	if (dict)
		free(dict);
	if (args.needs_free)
		free_split(args.av);
	std_error_message = RED "\nError" RESET "\n";
	write(2, std_error_message, ft_strlen(std_error_message));
	// ft_putstr_fd(std_error_message, 2);
	ft_printf(BRED "%s" RESET "\n" , massage);
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

char **free_split(char **av)
{
	int i;

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
