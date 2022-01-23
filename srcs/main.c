/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:01:45 by dienasci          #+#    #+#             */
/*   Updated: 2022/01/23 17:05:47 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"
#include <stdio.h>

void	print_array(int *a, size_t size)
{
	int	i;

	i = 0;
	while ((size_t)i < size)
	{
		printf("[%d] ", a[i]);
		i++;
	}
	printf("\n");
}

int	is_valid(int c)
{
	return ((c >= '0' && c <= '9') || (c == '+' || c == '-' || ft_isspace(c)));
}

int	count(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (is_valid(s[i]))
		{
			if ((s[i] >= 48 && s[i] <= 57))
				count++;
			while (!(s[i] == '+' || s[i] == '-' || ft_isspace(s[i])) && s[i])
				i++;
		}
		else
		{
			write(1, "Error.\n", 8);
			exit(1);
		}
		if (s[i])
			i++;
	}
	return (count);
}

int	*setup(char **args, size_t *size)
{
	char	**s;
	int		*final;
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (args[i[0]++] != 0)
		*size += count(args[i[0]]);
	final = malloc(*size * sizeof(int));
	i[0] = 1;
	while (args[i[0]])
	{
		s = ft_split(args[i[0]], ' ');
		while (s[i[1]])
		{
			final[i[2]] = ft_atoi(s[i[1]]);
			i[2]++;
			i[1]++;
		}
		i[0]++;
		i[1] = 0;
	}
	return (final);
}

int	main(int argc, char **argv)
{
	int		*a;
	int		*b;
	size_t	size;

	(void)argc;
	a = setup(argv, &size);
	b = 0;
	print_array(a, size);
	sort(a, b, size);
	print_array(a, size);
}
