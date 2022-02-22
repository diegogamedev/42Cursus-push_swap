/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:31:06 by dienasci          #+#    #+#             */
/*   Updated: 2022/02/20 18:30:48 by dienasci         ###   ########.fr       */
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

int	is_sorted(int *a, size_t size)
{
	size_t	index;
	int		temp;

	temp = a[0];
	index = 0;
	while (index++ < size - 1)
	{
		if (temp > a[index])
			return (0);
		else
			temp = a[index];
	}
	return (1);
}

int	is_backwards_sorted(int *a, size_t size)
{
	size_t	index;
	int		temp;

	temp = a[0];
	index = 0;
	while (index++ < size - 1)
	{
		if (temp < a[index])
			return (0);
		else
			temp = a[index];
	}
	return (1);
}

int	contains(int *array, int elem, size_t size)
{
	size_t	index;

	index = 0;
	while(index < size)
	{
		if (array[index] == elem)
			return (1);
		index++;
	}
	return (0);
}

