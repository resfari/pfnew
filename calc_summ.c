/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_summ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 19:00:33 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/14 19:00:33 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

void	ft_calcsumm_fin3(t_mean *mean, t_final *final)
{
	if (mean->mod > 0)
	{
		if (final->count == 0)
			final->perenos = 1;
		else
			final->perenos2 = 1;
	}
	else
	{
		if (final->count == 0)
			final->perenos = 0;
		else
			final->perenos2 = 0;
	}
	if (final->count == 0)
		final->after = mean->new;
	else
		final->before = mean->new;
}

void	ft_calcsumm_fin2(t_mean *mean)
{
	if (mean->equal + mean->mod > 9)
	{
		mean->new[mean->i] = 0;
		mean->mod = 1;
	}
	else
	{
		mean->new[mean->i] = mean->equal + mean->mod;
		mean->mod = 0;
	}
}

void	ft_calcsumm_final(int *first, int *second, int masssize, t_final *final)
{
	t_mean *mean;

	mean = (t_mean*)malloc(sizeof(t_mean) * 1);
	mean->new = (int*)malloc(sizeof(int) * masssize);
	mean->i = masssize - 1;
	mean->mod = 0;
	while (mean->i >= 0)
	{
		mean->equal = first[mean->i] + second[mean->i];
		if (mean->equal > 9)
		{
			mean->new[mean->i] = mean->equal % 10 + mean->mod;
			mean->mod = 1;
		}
		else
			ft_calcsumm_fin2(mean);
		mean->i--;
	}
	ft_calcsumm_fin3(mean, final);
	free(first);
	free(mean);
}

int		*ft_calcsumm(int *first, int *second, int masssize)
{
	t_mean *mean;

	mean = (t_mean*)malloc(sizeof(t_mean) * 1);
	mean->new = (int*)malloc(sizeof(int) * masssize);
	mean->i = masssize - 1;
	mean->mod = 0;
	while (mean->i >= 0)
	{
		mean->equal = first[mean->i] + second[mean->i];
		if (mean->equal > 9)
		{
			mean->new[mean->i] = mean->equal % 10 + mean->mod;
			mean->mod = 1;
		}
		else
			ft_calcsumm_fin2(mean);
		mean->i--;
	}
	free(mean);
	free(first);
	return (mean->new);
}
