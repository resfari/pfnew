/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:29:36 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/13 17:29:36 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

void	ft_float_write(t_fl *fl, int norm)
{
	if (norm == 1)
	{
		write(1, "1", 1);
		fl->value++;
	}
	if (norm == 2)
	{
		write(1, ".", 1);
		fl->value++;
	}
	if (norm == 3)
	{
		write(1, "0", 1);
		fl->value++;
	}
}

int		ft_check_str(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			count++;
		i++;
	}
	return (count);
}

void	ft_zero(int *mass, int masssize)
{
	int i;

	i = 0;
	while (i < masssize)
	{
		mass[i] = 0;
		i++;
	}
}

int		*ft_reverse(int *mass, int count, int size, int masssize)
{
	int *res;
	int i;

	i = 0;
	res = (int*)malloc(sizeof(int) * masssize);
	while (count > 0)
	{
		res[i] = 0;
		i++;
		count--;
	}
	while (size >= 0)
	{
		res[i] = mass[size];
		i++;
		size--;
	}
	return (res);
}

void	ft_create_massive_for_accuracy(t_final *fin, t_fl *fl, t_summ *summ)
{
	fin->acc = (int*)malloc(sizeof(int) * fl->masssize);
	ft_zero(fin->acc, fl->masssize);
	fin->acc[fl->accuracy - 1] = 1;
	ft_calcsumm_final(fin->acc, summ->mass, fl->masssize, fin);
}
