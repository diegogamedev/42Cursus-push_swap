/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:57:55 by dienasci          #+#    #+#             */
/*   Updated: 2022/03/03 23:41:00 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

////////////////////////// * Operations

//Inserts the top element of stack A into B
void	push_a(int **a, size_t *sza, int **b, size_t *szb);
// Inserts the top element of stack B into A
void	push_b(int **a, size_t *sza, int **b, size_t *szb);
// Swaps the two uppermost elements from stack A
void	swap_a(int **a, int silent, size_t size);
// Swaps the two uppermost elements from stack B
void	swap_b(int **b, int silent, size_t size);
// Swaps the two uppermost elements from stack A AND B
void	swap_swap(int **a, int **b, size_t size);
// Shifts all the elements up and puts the topmost element on the last position
// in stack A
void	rotate_a(int **a, int silent, size_t size);
// Shifts all the elements up and puts the topmost element on the last position
// in stack B
void	rotate_b(int **b, int silent, size_t size);
// Shifts all the elements up and puts the topmost element on the last position
// in stack A AND B
void	rotate_rotate(int **a, int **b, size_t size);
// Shifts all the elements down and puts the lowest element on the top position
// in stack A
void	reverse_rotate_a(int **a, int silent, size_t size);
// Shifts all the elements down and puts the lowest element on the top position
// in stack B
void	reverse_rotate_b(int **b, int silent, size_t size);
// Shifts all the elements down and puts the lowest element on the top position
// in stack A AND B
void	reverse_rotate_rotate(int **a, int **b, size_t size);

////////////////////////// * Auxiliars / Checkers / Flags

// returns 0 if it's not sorted in crescent order
int		is_sorted(int *a, size_t size);
// returns 0 if it's not sorted in decrescent order (sort three case)
int		is_backwards_sorted(int *a, size_t size);
// returns 0 if elem is not in the array
int		contains(int *array, int elem, size_t size);
// checks for int under or overflow
int		check_overunderflow(char **args);

//////////////////////////  * Getters

// Find the smallest element in list, constrained by size
int		find_smallest_number(int *list, size_t size);
// Find the biggest element in list, constrained by size
int		find_biggest_number(int *list, size_t size);
// Get the index of element in list.
size_t	get_index(int *list, int element);

//////////////////////////  * Utils

// Free a **void
void	free_2d_array(char **a);
// runs push_a until b is empty, without sorting.
void	push_a_until_empty(int **a, size_t *sza, int **b, size_t *szb);

//////////////////////////  * LIBFT (system library functions)

// converts char to int
int		ft_atoi(const char *str);
// same thing as ft_atoi, but returns 1 if the number is a int
int		ft_atoi_validator(const char *str);
// sets len bytes of memory to c
void	*ft_memset(void *s, int c, size_t len);
// returns a pointer of nmemb * size bytes, with all it's values equal to zero
void	*ft_calloc(size_t nmemb, size_t size);
// returns 1 if c is a "space", this includes \n, \t, \r and so on...
int		ft_isspace(int c);
// copies n bytes of a block of memory src to dest
void	*ft_memcpy(void *dest, const void *src, size_t n);
// splits a word using c as a separator
char	**ft_split(char const *s, char c);

////////////////////////// * Sorting

// Takes two pointers and the size of A, and calls the appropriate algorithm
int		*sort(int *a, int *b, size_t size);
// Returns a sorted array (Insertion sort)
int		*get_sorted_array(const int *sample, const size_t size);
// Hard-coded solution for all the combinations of an array of size 3
void	sort_three(int *a, size_t a_size);
// Sorts arrays from size 4 to 10
int		*sort_ten(int *a, size_t a_size, int *b, size_t b_size);
// Sorts arrays from size 11 to 100
int		*sort_hundred(int *a, size_t a_size, int *b, size_t b_size);
// Sorts arrays bigger than 100
int		*sort_big(int *a, size_t a_size, int *b, size_t b_size);

#endif
