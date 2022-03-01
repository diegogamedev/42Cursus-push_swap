/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:01:02 by dienasci          #+#    #+#             */
/*   Updated: 2022/03/01 14:07:32 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*sort(int *a, int *b, size_t size)
{
	if (is_sorted(a, size))
		return (a);
	if (size == 2)
		rotate_a(&a, 0, size);
	else if (size == 3)
		sort_three(a, size);
	else if (size <= 10)
		return (sort_ten(a, size, b, 0));
	else if (size <= 100)
		return (sort_hundred(a, size, b, 0));
	else
		return (sort_big(a, size, b, 0));
	if (b)
		free(b);
	return (a);
}

int	*get_sorted_array(const int *sample, const size_t size)
{
	size_t	i;
	int		element;
	int		j;
	int		*ret;

	i = 1;
	ret = ft_calloc(size, sizeof(int));
	ft_memcpy(ret, sample, size * sizeof(int));
	while (i < size)
	{
		element = ret[i];
		j = i - 1;
		while (j >= 0 && ret[j] > element)
		{
			ret[j + 1] = ret[j];
			j = j - 1;
		}
		ret[j + 1] = element;
		i++;
	}
	return (ret);
}
