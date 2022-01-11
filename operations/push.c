#include "../includes/push_swap.h"

void	push_a(int **a, int **b, size_t size)
{
	int		temp;

	write(1, "pa\n", 4);
	if(size > 0)
	{
		temp = (*b)[0];
		(*b)[0] = (*a)[0];
		(*a)[0] = temp;
	}
}

void	push_b(int **a, int **b, size_t size)
{
	write(1, "pb\n", 4);
	int temp;

	write(1, "pa\n", 4);
	if (size > 0)
	{
		temp = (*a)[0];
		(*a)[0] = (*b)[0];
		(*a)[0] = temp;
	}
}
