/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:59:10 by dienasci          #+#    #+#             */
/*   Updated: 2022/01/23 17:33:23 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

static size_t	insert_at(int ***array, size_t og_sz, int value, int index)
{
	int	*hold;
	int	i;

	i = 0;
	hold = malloc(og_sz * sizeof(int));
	ft_memcpy(hold, (*(*array)), og_sz * sizeof(int));
	free((*(*array)));
	(*(*array)) = malloc((og_sz + 1) * sizeof(int));
	(*(*array))[index] = value;
	while ((size_t)i++ < (og_sz))
		(*(*array))[i] = hold[i - 1];
	free(hold);
	return (og_sz + 1);
}

static size_t	remove_head(int ***array, size_t og_sz)
{
	int	*hold;
	int	i;

	i = 0;
	hold = malloc(og_sz * sizeof(int));
	ft_memcpy(hold, (*(*array)), og_sz * sizeof(int));
	free((*(*array)));
	(*(*array)) = malloc((og_sz - 1) * sizeof(int));
	while ((size_t)i++ < (og_sz))
		(*(*array))[i - 1] = hold[i];
	free(hold);
	return (og_sz - 1);
}

void	push_a(int **a, size_t *sza, int **b, size_t *szb)
{
	write(1, "pa\n", 4);
	if (*szb != 0)
	{
		*sza = insert_at(&a, *sza, (*b)[0], 0);
		*szb = remove_head(&b, *szb);
	}
}

void	push_b(int **a, size_t *sza, int **b, size_t *szb)
{
	write(1, "pb\n", 4);
	if (*sza != 0)
	{
		*szb = insert_at(&b, *szb, (*a)[0], 0);
		*sza = remove_head(&a, *sza);
	}
}

void	push_a_until_empty(int **a, size_t *sza, int **b, size_t *szb)
{
	while (1)
	{
		if (*szb != 0)
			push_a(&(*a), &(*sza), &(*b), &(*szb));
		else
			break ;
	}
}
