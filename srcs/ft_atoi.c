/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 20:55:38 by dienasci          #+#    #+#             */
/*   Updated: 2022/03/03 23:42:29 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\f')
		return (1);
	if (c == '\r' || c == '\n' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long			num;
	int				i;
	int				np;

	np = 1;
	i = 0;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			np = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(np * num));
}

int	ft_atoi_validator(const char *str)
{
	long num;
	int i;
	int np;

	np = 1;
	i = 0;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			np = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if ((np * num) > -2147483648 && (np * num) < 2147483647)
		return (1);
	else
		return (0);
}
