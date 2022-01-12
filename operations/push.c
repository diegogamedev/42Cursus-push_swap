#include "../includes/push_swap.h"
#include "../includes/libft.h"
#include <stdio.h>
#include <string.h>

void	push_a(int **a, size_t sza, int **b, size_t szb)
{
	int	temp;
	int	*x;
	int	*z;
	int	i;

	write(1, "pa\n", 4);
	i = 0;
	if(szb != 0)
	{
		x = malloc(sza * sizeof(int));
		ft_memcpy(x, *a, sza);
		printf("Copying A:");
		print_array(x, sza);
		z = malloc(szb * sizeof(int));
		ft_memcpy(z, *b, szb);
		printf("Copying B:");
		print_array(z, szb);
		temp = (*b)[0];

		free(*a);
		*a = malloc((sza + 1) * sizeof(int));
		(*a)[0] = temp;
		while (i++ < (sza))
			(*a)[i] = x[i - 1];
		free(*b);
		*b = malloc((szb - 1) * sizeof(int));
		while (i++ < (szb))
			(*b)[i - 1] = z[i];
		free(x);
		free(z);
	}
}

void	push_b(int **a, size_t sza, int **b, size_t szb)
{
	int temp;
	int *x;
	int *z;

	write(1, "pb\n", 4);
	if (sza != 0)
	{
		x = ft_memcpy(x, *a, sza);
		z = ft_memcpy(z, *b, szb);
		temp = (*a)[0];
	}
}
