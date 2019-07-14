/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longarifmetika.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:10:44 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/06/24 16:10:44 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

void		ft_summastart_p3(t_mean *mean, t_summ *summ, int masssize)
{
	ft_zero(mean->new, masssize);
	mean->j = 0;
	mean->numbnol = summ->numbnol;
	mean->size = summ->size;
	mean->mod = 0;
}

void		ft_summastart_p2(t_mean *mean, t_summ *summ, int masssize)
{
	while (mean->i < mean->exp)
	{
		ft_summastart_p3(mean, summ, masssize);
		if (summ->mass[summ->numbnol] == 1)
			summ->numbnol++;
		while (mean->j < masssize && mean->size >= 0)
		{
			mean->help = summ->mass[mean->size + mean->numbnol];
			mean->new[mean->j] = (mean->help * 5) % 10 + mean->mod;
			mean->mod = 0;
			mean->mod = (mean->help * 5) / 10;
			mean->j++;
			mean->size--;
			if (mean->size < 0 && mean->mod > 0)
			{
				mean->new[mean->j] = mean->mod;
				summ->size++;
			}
		}
		summ->mass = ft_reverse(mean->new, summ->numbnol, summ->size, masssize);
		mean->i++;
	}
}

t_summ		*ft_summastart(int exp, t_summ *summ, int masssize)
{
	t_mean *mean;

	mean = (t_mean*)malloc(sizeof(t_mean) * 1);
	mean->i = 1;
	mean->exp = exp;
	mean->new = (int*)malloc(sizeof(int) * masssize);
	summ->mass = (int*)malloc(sizeof(int) * masssize);
	ft_zero(mean->new, masssize);
	ft_zero(summ->mass, masssize);
	summ->mass[0] = 5;
	summ->size = 0;
	summ->numbnol = 0;
	if (mean->exp != 1)
		ft_summastart_p2(mean, summ, masssize);
	return (summ);
}

void		ft_fivemulti_p2(t_mean *mean, t_summ *summ, int masssize)
{
	while (mean->i < mean->exp)
	{
		mean->size = summ->size;
		mean->numbnol = summ->numbnol;
		mean->mod = 0;
		if (summ->mass[summ->numbnol] == 1)
			summ->numbnol++;
		while (mean->j < masssize && mean->size >= 0)
		{
			mean->help = summ->mass[mean->size + mean->numbnol];
			mean->new[mean->j] = (mean->help * 5) % 10 + mean->mod;
			mean->mod = (mean->help * 5) / 10;
			mean->j++;
			mean->size--;
			if (mean->size < 0 && mean->mod > 0)
			{
				mean->new[mean->j] = mean->mod;
				summ->size++;
			}
		}
		mean->i++;
	}
}

t_summ		*ft_fivemulti(int exp, t_summ *summ, int masssize)
{
	t_mean *mean;

	mean = (t_mean*)malloc(sizeof(t_mean) * 1);
	mean->new = (int*)malloc(sizeof(int) * masssize);
	ft_zero(mean->new, masssize);
	mean->i = 0;
	mean->j = 0;
	mean->exp = exp;
	ft_fivemulti_p2(mean, summ, masssize);
	summ->mass = ft_reverse(mean->new, summ->numbnol, summ->size, masssize);
	return (summ);
}
