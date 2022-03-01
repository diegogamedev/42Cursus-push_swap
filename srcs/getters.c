/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:45:09 by dienasci          #+#    #+#             */
/*   Updated: 2022/03/01 14:02:34 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_smallest_number(int *list, size_t size)
{
	size_t	i;
	int		hold;

	i = 0;
	hold = list[0];
	while (i < size)
	{
		if (hold > list[i])
			hold = list[i];
		i++;
	}
	return (hold);
}

int	find_biggest_number(int *list, size_t size)
{
	size_t	i;
	int		hold;

	i = 0;
	hold = list[0];
	while (i < size)
	{
		if (hold < list[i])
			hold = list[i];
		i++;
	}
	return (hold);
}

size_t	get_index(int *list, int element)
{
	int	i;

	i = 0;
	while (1)
	{
		if (list[i] == element)
			return (i);
		i++;
	}
}
