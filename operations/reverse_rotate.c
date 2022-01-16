/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:59:03 by dienasci          #+#    #+#             */
/*   Updated: 2022/01/16 20:00:13 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_a(int **a, int silent, size_t size)
{
	int	temp;
	int	index;

	if (!silent)
		write(1, "rra\n", 4);
	temp = (*a)[size - 1];
	index = size - 2;
	while (index >= 0)
	{
		(*a)[index + 1] = (*a)[index];
		index--;
	}
	(*a)[0] = temp;
}

void	reverse_rotate_b(int **b, int silent, size_t size)
{
	if (!silent)
		write(1, "rrb\n", 4);
	rotate_a(b, 1, size);
}

void	reverse_rotate_rotate(int **a, int **b, size_t size)
{
	write(1, "rrr\n", 4);
	rotate_a(a, 1, size);
	rotate_b(b, 1, size);
}
