/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:58:19 by dienasci          #+#    #+#             */
/*   Updated: 2022/02/24 23:09:26 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void	push_and_sort_to_a(int **a, size_t *a_size, int **b, size_t *b_size)
{
	int pivot;

	while(*b_size)
	{
		pivot = find_smallest_number(*b, *b_size);
		while (contains(*b, pivot, *b_size))
		{
			if ((*b)[0] == pivot)
				push_a(&(*a), &(*a_size), &(*b), &(*b_size));
			else if ((*b)[1] == pivot)
				swap_b(&(*b), 0, *b_size);
			else if (*b_size / 2 > get_index(*b, pivot))
				rotate_b(&(*b), 0, *b_size);
			else
				reverse_rotate_b(&(*b), 0, *b_size);
		}
	}
}

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
	int		it;
	int		key_nbr;
	int		*sorted_a;
	size_t	sorted_size;

	sorted_a = get_sorted_array(a, a_size);
	sorted_size = a_size;
	print_array(sorted_a, a_size, "Sorted array is: ");
	it = 1;
	while(it <= 4)
	{
		key_nbr = sorted_a[((sorted_size / 4) * it) - 1];
		printf("new key_nbr: |%d|\n", key_nbr);
		while(1 && !is_sorted(a, a_size))
		{
			if (!split(&a, &a_size, &b, &b_size, key_nbr))
				break;
		}
		it++;
	}
	if(a_size == 3)
		sort_three(&(a[0]), a_size);
	else if(a_size == 2 && !is_sorted(a, a_size))
		rotate_a(&a, 0, a_size);
	push_and_sort_to_a(&a, &a_size, &b, &b_size);
	free(sorted_a);
	return (a);
}
