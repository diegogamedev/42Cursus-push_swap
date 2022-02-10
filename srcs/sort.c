/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:08:07 by dienasci          #+#    #+#             */
/*   Updated: 2022/02/06 13:03:18 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"
#include <stdio.h>

//Hard-coded the 5 possible cases (could be better)
void	sort_three(int *a, size_t a_size)
{
	if (is_backwards_sorted(a, a_size))
	{
		swap_a(&a, 0, a_size);
		reverse_rotate_a(&a, 0, a_size);
	}
	else if (a[1] > a[2] && a[0] < a[2] && a[0] < a[1])
	{
		swap_a(&a, 0, a_size);
		rotate_a(&a, 0, a_size);
	}
	else if (a[0] > a[1] && a[0] > a[2])
		rotate_a(&a, 0, a_size);
	else if (a[0] < a[2])
		swap_a(&a, 0, a_size);
	else
		reverse_rotate_a(&a, 0, a_size);
}

void	sort_ten(int *a, size_t a_size, int *b, size_t b_size)
{
	size_t	final_size;
	int		pivot;

	final_size = a_size;
	while (1)
	{
		printf("new cycle: a address: %p, b address: %p\n", a, b);
		if (is_sorted(a, a_size) && a_size == final_size)
			break ;
		else if (a_size != final_size && is_sorted(a, a_size))
		{
			push_a_until_empty(&a, &a_size, &b, &b_size);
			break ;
		}
		else if (a_size == 3 && !is_sorted(a, a_size))
		{
			sort_three(a, a_size);
			push_a_until_empty(&a, &a_size, &b, &b_size);
			break ;
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

void	sort_hundred(int *a, size_t a_size, int *b, size_t b_size)
{
	(void)a;
	(void)b;
	a_size++;
	b_size++;
	write(1, "PANIC!\n", 8);
}

void	sort_default(int *a, size_t a_size, int *b, size_t b_size)
{
	(void)a;
	(void)b;
	a_size++;
	b_size++;
	write(1, "PANIC!\n", 8);
}

void	sort(int *a, int *b, size_t size)
{
	(void)b;
	if (is_sorted(a, size))
		return ;
	if (size == 2)
		rotate_a(&a, 0, size);
	else if (size == 3)
		sort_three(a, size);
	else if (size <= 10)
		sort_ten(a, size, b, 0);
	else if (size)
		sort_hundred(a, size, b, 0);
	else
		sort_default(a, size, b, 0);
}
