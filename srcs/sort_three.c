/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:08:07 by dienasci          #+#    #+#             */
/*   Updated: 2022/02/20 14:01:21 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
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
