/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_otther.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 19:08:48 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/13 19:08:48 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

int		ft_check_sign(char c, t_fl *fl)
{
	if (c == '1')
	{
		fl->width--;
		return (1);
	}
	else if (fl->flagplus == 1 && c == '0')
	{
		fl->width--;
		return (0);
	}
	else if (fl->flagspace == 1 && c == '0')
	{
		fl->width--;
		return (0);
	}
	else
		return (0);
}

double	ft_square(int d, int power)
{
	double res;

	res = d;
	if (power == 0)
		return (1);
	if (power == 1)
		return (d);
	while (power > 1)
	{
		res = res * d;
		power--;
	}
	return (res);
}

int		*ft_copymass(int *mass, int size)
{
	int *qwer;
	int i;

	i = 0;
	qwer = (int*)malloc(sizeof(int) * size);
	while (i < size)
	{
		qwer[i] = mass[i];
		i++;
	}
	return (qwer);
}
