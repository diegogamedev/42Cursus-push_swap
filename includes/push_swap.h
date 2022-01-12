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

#endif
