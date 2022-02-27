/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:59:17 by dienasci          #+#    #+#             */
/*   Updated: 2022/02/26 13:29:02 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(int **a, int silent, size_t size)
{
	int	temp;
	int	index;

	if (!silent)
		write(1, "ra\n", 3);
	temp = (*a)[0];
	index = 0;
	while ((size_t)index < size - 1)
	{
		(*a)[index] = (*a)[index + 1];
		index++;
	}
	(*a)[index] = temp;
}

void	rotate_b(int **b, int silent, size_t size)
{
	if (!silent)
		write(1, "rb\n", 3);
	rotate_a(b, 1, size);
}

void	rotate_rotate(int **a, int **b, size_t size)
{
	write(1, "rr\n", 3);
	rotate_a(a, 1, size);
	rotate_b(b, 1, size);
}
