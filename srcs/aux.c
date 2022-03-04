/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:31:06 by dienasci          #+#    #+#             */
/*   Updated: 2022/03/02 23:25:43 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	while (index < size)
	{
		if (array[index] == elem)
			return (1);
		index++;
	}
	return (0);
}
