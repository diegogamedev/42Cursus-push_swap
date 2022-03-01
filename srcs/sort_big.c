/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:58:15 by dienasci          #+#    #+#             */
/*   Updated: 2022/03/01 15:37:42 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_sorting_to_a(int **a, size_t *a_size, int **b, size_t *b_size)
{
	int	pivot;

	while ((*b_size))
	{
		pivot = find_biggest_number((*b), (*b_size));
		while (contains((*b), pivot, (*b_size)))
		{
			if ((*b)[0] == pivot)
				push_a(&(*a), &(*a_size), &(*b), &(*b_size));
			else
			{
				if ((*b_size) / 2 > get_index(*b, pivot))
					rotate_b(&(*b), 0, (*b_size));
				else
					reverse_rotate_b(&(*b), 0, (*b_size));
			}
		}
	}
}

static void	split(int **a, size_t **sizes, int **b, int key_nbr)
{
	int		pivot;
	size_t	index;
	size_t	size;

	pivot = key_nbr;
	index = 0;
	size = *sizes[0];
	while (index < size)
	{
		if ((*a)[0] <= pivot)
			push_b(&(*a), sizes[0], &(*b), sizes[1]);
		else
			rotate_a(&(*a), 0, *sizes[0]);
		index++;
	}
}

int	*sort_big(int *a, size_t a_size, int *b, size_t b_size)
{
	int		it;
	int		*sorted_a;
	size_t	sorted_size;
	size_t	**sizes;

	sizes = ft_calloc(2, sizeof(size_t *));
	sizes[0] = &a_size;
	sizes[1] = &b_size;
	sorted_a = get_sorted_array(a, a_size);
	sorted_size = a_size;
	it = 0;
	while (it++ <= 8)
		split(&a, sizes, &b, sorted_a[((sorted_size / 8) * it) - 1]);
	push_sorting_to_a(&a, &a_size, &b, &b_size);
	free(sorted_a);
	return (a);
}
