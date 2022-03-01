/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ten.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:57:57 by dienasci          #+#    #+#             */
/*   Updated: 2022/03/01 12:51:44 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int *sort_ten(int *a, size_t a_size, int *b, size_t b_size)
{
	size_t final_size;
	int pivot;

	final_size = a_size;
	while (1)
	{
		// if(a) print_array(a, a_size, "(sort) A stack: ");
		// if(b) print_array(b, b_size, "(sort) B stack: ");
		if (is_sorted(a, a_size) && a_size == final_size)
			return a;
		else if (a_size != final_size && is_sorted(a, a_size))
		{
			push_a_until_empty(&a, &a_size, &b, &b_size);
			// print_array(a, a_size, "(sort) A stack: ");
			return a;
		}
		else if (a_size == 3 && !is_sorted(a, a_size))
		{
			sort_three(a, a_size);
			push_a_until_empty(&a, &a_size, &b, &b_size);
			// print_array(a, a_size, "(sort) A stack: ");
			return a;
		}
		pivot = find_smallest_number(a, a_size);
		if (a[0] == pivot)
			push_b(&a, &a_size, &b, &b_size);
		else if (a[1] == pivot)
			swap_a(&a, 0, a_size);
		else if (a_size / 2 > get_index(a, pivot))
			rotate_a(&a, 0, a_size);
		else
			reverse_rotate_a(&a, 0, a_size);
	}
}
