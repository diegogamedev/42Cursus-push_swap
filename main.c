#include "includes/push_swap.h"
#include "includes/libft.h"
#include <stdio.h>

void print_array(int *a, size_t size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("[%d] ", a[i]);
		i++;
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	int	i;
	int	*a;
	int	*b;

	i = 0;
	a = malloc((argc - 1) * sizeof(int));
	b = malloc((argc - 1) * sizeof(int));
	while(i++ < (argc - 1))
	{
		a[i - 1] = ft_atoi(argv[i]);
		b[i - 1] = rand() % 50;
	}
	printf("A:");
	print_array(a, argc - 1);
	printf("B:");
	print_array(b, argc - 1);
	push_a(&a, argc - 1, &b, argc - 1);
	printf("A depois do Push:");
	print_array(a, argc);
	printf("B depois do Push:");
	print_array(b, argc - 2);
	free(a);
}
