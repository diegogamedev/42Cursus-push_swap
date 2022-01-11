#include "../includes/push_swap.h"

void	swap_a(int **a, int silent, size_t size)
{
	int		temp;

	if(!silent)
		write(1, "sa\n", 4);
	if((*a) == NULL)
		return;
	if(size > 1)
	{
		temp = (*a)[0];
		(*a)[0] = (*a)[1];
		(*a)[1] = temp;
	}
}

void	swap_b(int **b, int silent, size_t size)
{
	if(!silent)
		write(1, "sb\n", 4);
	swap_a(b, 1, size);
}

void	swap_swap(int **a, int **b, size_t size)
{
	write(1, "ss\n", 4);
	swap_a(a, 1, size);
	swap_b(b, 1, size);
}
