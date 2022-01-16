/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:01:45 by dienasci          #+#    #+#             */
/*   Updated: 2022/01/16 20:02:51 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"
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

int	validate(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9') || (s[i] == '+' || s[i] == '-'))
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_sorted(int *a, size_t size)
{
	size_t	index;
	int		temp;

	temp = a[0];
	while (index < size)
		if (temp < a[index])
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*a;
	int	*b;

	i = 0;
	a = malloc((argc - 1) * sizeof(int));
	b = 0;
	while (i++ < (argc - 1))
	{
		if (validate(argv[i]))
			a[i - 1] = ft_atoi(argv[i]);
		else
		{
			write(1, "Error.", 7);
			break ;
		}
	}
	if (a)
		free(a);
	if (b)
		free(b);
}
