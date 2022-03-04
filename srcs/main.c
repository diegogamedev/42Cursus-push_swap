/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:01:45 by dienasci          #+#    #+#             */
/*   Updated: 2022/03/03 23:36:53 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
			write(1, "Error\n", 6);
			exit(1);
		}
		if (s[i])
			i++;
	}
	return (count);
}

int	check_for_repetition(int *a, size_t size)
{
	size_t	index;
	size_t	aux;

	index = 0;
	while (index < size)
	{
		aux = size - 1;
		while (aux > index)
		{
			if (a[index] == a[aux])
				return (0);
			aux--;
		}
		index++;
	}
	return (1);
}

int	*setup(char **args, size_t *size)
{
	char	**s;
	int		*final;
	int		*i;

	final = 0;
	i = ft_calloc(3, sizeof(int));
	while (args[i[0]++] != 0)
		*size += count(args[i[0]]);
	final = ft_calloc(*size, sizeof(int));
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
		free_2d_array(s);
	}
	free(i);
	return (final);
}

int	main(int argc, char **argv)
{
	int		*a;
	int		*b;
	int		*temp;
	size_t	size;

	if (argc <= 1)
		exit(EXIT_FAILURE);
	a = 0;
	b = 0;
	size = 0;
	temp = setup(argv, &size);
	if (check_for_repetition(temp, size) && check_overunderflow(argv))
		a = sort(temp, b, size);
	else
	{
		free(temp);
		write(1, "Error\n", 6);
	}
	free(a);
}
