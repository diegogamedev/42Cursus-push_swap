/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:58:19 by dienasci          #+#    #+#             */
/*   Updated: 2022/02/21 23:03:20 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static int	split(int **a, size_t *a_size, int **b, size_t *b_size, int key_nbr)
{
	int	pivot;

	pivot = find_smallest_number(*a, *a_size);
	if (pivot <= key_nbr)
	{
		while(contains(*a, pivot, *a_size))
		{
			if ((*a)[0] == pivot)
				push_b(&(*a), &(*a_size), &(*b), &(*b_size));
			else if ((*a)[1] == pivot)
				swap_a(&(*a), 0, *a_size);
			else if (*a_size / 2 > get_index(*a, pivot))
				rotate_a(&(*a), 0, *a_size);
			else
				reverse_rotate_a(&(*a), 0, *a_size);

			print_array(*a, *a_size, "A operation: ");
			print_array(*b, *b_size, "B operation: ");
		}
		return (1);
	}
	else
	{
		return (0);
	}
}

int *sort_hundred(int *a, size_t a_size, int *b, size_t b_size)
{
	int	it;
	int	key_nbr;
	int	*sorted_a;

	sorted_a = get_sorted_array(a, a_size);
	print_array(sorted_a, a_size, "Sorted array is: ");
	it = 1;
	while(it <= 4)
	{
		key_nbr = sorted_a[(a_size / 4) * it];
		printf("new key_nbr: |%d|\n", key_nbr);
		while(1)
		{
			if (!split(&a, &a_size, &b, &b_size, key_nbr))
				break;
		}
		it++;
	}
	free(sorted_a);
	return (a);
}
