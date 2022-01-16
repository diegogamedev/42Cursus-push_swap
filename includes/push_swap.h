/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:57:55 by dienasci          #+#    #+#             */
/*   Updated: 2022/01/16 19:59:31 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

void	push_a(int **a, size_t sza, int **b, size_t szb);
void	push_b(int **a, size_t sza, int **b, size_t szb);
void	swap_a(int **a, int silent, size_t size);
void	swap_b(int **b, int silent, size_t size);
void	swap_swap(int **a, int **b, size_t size);
void	rotate_a(int **a, int silent, size_t size);
void	rotate_b(int **b, int silent, size_t size);
void	rotate_rotate(int **a, int **b, size_t size);
void	reverse_rotate_a(int **a, int silent, size_t size);
void	reverse_rotate_b(int **b, int silent, size_t size);
void	reverse_rotate_rotate(int **a, int **b, size_t size);
void	print_array(int *a, size_t size);
int		is_sorted(int *a, size_t size);

#endif
