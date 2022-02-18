/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:57:55 by dienasci          #+#    #+#             */
/*   Updated: 2022/02/17 22:25:04 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

void	push_a(int **a, size_t *sza, int **b, size_t *szb);
void	push_b(int **a, size_t *sza, int **b, size_t *szb);
void	swap_a(int **a, int silent, size_t size);
void	swap_b(int **b, int silent, size_t size);
void	swap_swap(int **a, int **b, size_t size);
void	rotate_a(int **a, int silent, size_t size);
void	rotate_b(int **b, int silent, size_t size);
void	rotate_rotate(int **a, int **b, size_t size);
void	reverse_rotate_a(int **a, int silent, size_t size);
void	reverse_rotate_b(int **b, int silent, size_t size);
void	reverse_rotate_rotate(int **a, int **b, size_t size);
void	print_array(int *a, size_t size, const char *id); //Remove this
int*	sort(int *a, int *b, size_t size);
int		is_sorted(int *a, size_t size);
int		is_backwards_sorted(int *a, size_t size);
int		find_smallest_number(int *list, size_t size);
size_t	get_index(int *list, int element);
void	free_2d_array(char **a);
void	push_a_until_empty(int **a, size_t *sza, int **b, size_t *szb);

//Libft
int		ft_atoi(const char *str);
void *ft_memset(void *s, int c, size_t len);
void *ft_calloc(size_t nmemb, size_t size);
int		ft_isspace(int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);

#endif
