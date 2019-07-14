/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longarifmetikaanother.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:04:07 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/06/28 15:04:07 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

void	ft_first_mean_two_p2(t_mean *mean, t_summ *summ, int masssize)
{
	while (mean->i < mean->exp)
	{
		ft_zero(mean->new, masssize);
		mean->j = 0;
		mean->size = summ->size;
		mean->mod = 0;
		while (mean->j < masssize && mean->size >= 0)
		{
			mean->help = summ->mass[mean->size];
			mean->new[mean->j] = (mean->help * 2) % 10 + mean->mod;
			mean->mod = 0;
			mean->mod = (mean->help * 2) / 10;
			mean->j++;
			mean->size--;
			if (mean->size < 0 && mean->mod > 0)
			{
				mean->new[mean->j] = mean->mod;
				summ->size++;
			}
		}
		summ->mass = ft_reverse(mean->new, 0, summ->size, masssize);
		mean->i++;
	}
}

t_summ	*ft_first_mean_two(int exp, t_summ *summ, int masssize)
{
	t_mean *mean;

	mean = (t_mean*)malloc(sizeof(t_mean) * 1);
	mean->exp = exp;
	mean->i = 1;
	mean->new = (int*)malloc(sizeof(int) * masssize);
	ft_zero(mean->new, masssize);
	summ->mass = (int*)malloc(sizeof(int) * masssize);
	ft_zero(summ->mass, masssize);
	summ->mass[0] = 2;
	summ->size = 0;
	if (mean->exp == 0)
		summ->mass[0] = 1;
	else if (mean->exp != 1 && mean->exp != 0)
		ft_first_mean_two_p2(mean, summ, masssize);
	summ->et_size = summ->size;
	return (summ);
}

t_summ	*ft_delete_two(t_summ *summ, int masssize)
{
	int i;
	int j;
	int size;
	int mod;
	int *new;

	new = (int*)malloc(sizeof(int) * masssize);
	ft_zero(new, masssize);
	i = 0;
	j = 0;
	mod = 0;
	size = summ->size;
	if (summ->mass[i] == 1)
		summ->numbnol++;
	while (j < masssize && i <= size)
	{
		new[j] = (summ->mass[i] + mod * 10) / 2;
		mod = summ->mass[i] % 2;
		j++;
		i++;
	}
	summ->mass = new;
	return (summ);
}

void	ft_calcsumm_two_p2(int *first, int *second, t_plus *plus)
{
	while (plus->i >= 0)
	{
		plus->equal = first[plus->i] + second[plus->i];
		if (plus->equal > 9)
		{
			plus->res[plus->i] = plus->equal % 10 + plus->mod;
			plus->mod = 1;
		}
		else
		{
			if (plus->equal + plus->mod > 9)
			{
				plus->res[plus->i] = 0;
				plus->mod = 1;
			}
			else
			{
				plus->res[plus->i] = plus->equal + plus->mod;
				plus->mod = 0;
			}
		}
		plus->i--;
		plus->size--;
	}
}

int		*ft_calcsumm_two(int *first, int *second, t_summ *summ, int masssize)
{
	t_plus *plus;

	plus = (t_plus*)malloc(sizeof(t_plus) * 1);
	plus->res = (int*)malloc(sizeof(int) * masssize);
	plus->i = masssize - 1;
	plus->mod = 0;
	plus->size = summ->size;
	ft_calcsumm_two_p2(first, second, plus);
	if (plus->i < 0 && plus->mod > 0)
		summ->edinica = 1;
	return (plus->res);
}
