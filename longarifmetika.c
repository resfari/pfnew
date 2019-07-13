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

t_summ		*ft_summastart(int exp, t_summ *summ, int masssize)
{
	int i;
	int j;
	int size;
	int help;
	int mod;
	int *new;
	int numbnol;

	i = 1;
	new = (int*)malloc(sizeof(int) * masssize);
	ft_zero(new, masssize);
	summ->mass = (int*)malloc(sizeof(int) * masssize);
	ft_zero(summ->mass, masssize);
	summ->mass[0] = 5;
	summ->size = 0;
	summ->numbnol = 0;
	if (exp == 1)
		return (summ);
	else
	{
		while (i < exp)
		{
			ft_zero(new, masssize);
			j = 0;
			numbnol = summ->numbnol;
			size = summ->size;
			mod = 0;
			if (summ->mass[summ->numbnol] == 1)
			{
				summ->numbnol++;
			}
			while (j < masssize && size >= 0)
			{
				help = summ->mass[size + numbnol];
				new[j] = (help * 5) % 10 + mod;
				mod = 0;
				mod = (help * 5) / 10;
				j++;
				size--;
				if (size < 0 && mod > 0)
				{
					new[j] = mod;
					summ->size++;
				}
			}
			free(summ->mass);
			summ->mass = ft_reverse(new, summ->numbnol, summ->size, masssize);
			i++;
		}
	}
	return (summ);
}

t_summ		*ft_fivemulti(int exp, t_summ *summ, int masssize)
{
	int i;
	int j;
	int size;
	int help;
	int mod;
	int *new;
	int numbnol;

	new = (int*)malloc(sizeof(int) * masssize);
	ft_zero(new, masssize);
	i = 0;
	j = 0;
	while (i < exp)
	{
		size = summ->size;
		numbnol = summ->numbnol;
		mod = 0;
		if (summ->mass[summ->numbnol] == 1)
		{
			summ->numbnol++;
		}
		while (j < masssize && size >= 0)
		{
			help = summ->mass[size + numbnol];
			new[j] = (help * 5) % 10 + mod;
			mod = 0;
			mod = (help * 5) / 10;
			j++;
			size--;
			if (size < 0 && mod > 0)
			{
				new[j] = mod;
				summ->size++;
			}
		}
		i++;
	}
	free(summ->mass);
	summ->mass = ft_reverse(new, summ->numbnol, summ->size, masssize);
	return (summ);
}

int		*ft_calcsumm(int *first, int *second, int masssize)
{
	int i;
	int *res;
	int mod;
	int equal;

	res = (int*)malloc(sizeof(int) * masssize);
	i = masssize - 1;
	mod = 0;
	while (i >= 0)
	{
		equal = first[i] + second[i];
		if (equal > 9)
		{
			res[i] = equal % 10 + mod;
			mod = 1;
		}
		else
		{
			if (equal + mod > 9)
			{
				res[i] = 0;
				mod = 1;
			}
			else
			{
				res[i] = equal + mod;
				mod = 0;
			}
		}
		i--;
	}
	free(first);
	return (res);
}

void	ft_calcsumm_final(int *first, int *second, int masssize, t_final *final)
{
	int i;
	int *res;
	int mod;
	int equal;

	res = (int*)malloc(sizeof(int) * masssize);
	i = masssize - 1;
	mod = 0;
	while (i >= 0)
	{
		equal = first[i] + second[i];
		if (equal > 9)
		{
			res[i] = equal % 10 + mod;
			mod = 1;
		}
		else
		{
			if (equal + mod > 9)
			{
				res[i] = 0;
				mod = 1;
			}
			else
			{
				res[i] = equal + mod;
				mod = 0;
			}
		}
		i--;
	}
	if (mod > 0)
		final->perenos = 1;
	else
		final->perenos = 0;
	final->after = res;
}

void	ft_calcsumm_final_before(int *first, int *second, int masssize, t_final *final)
{
	int i;
	int *res;
	int mod;
	int equal;

	res = (int*)malloc(sizeof(int) * masssize);
	i = masssize - 1;
	mod = 0;
	while (i >= 0)
	{
		equal = first[i] + second[i];
		if (equal > 9)
		{
			res[i] = equal % 10 + mod;
			mod = 1;
		}
		else
		{
			if (equal + mod > 9)
			{
				res[i] = 0;
				mod = 1;
			}
			else
			{
				res[i] = equal + mod;
				mod = 0;
			}
		}
		i--;
	}
	if (mod > 0)
		final->perenos2 = 1;
	else
		final->perenos2 = 0;
	final->before = res;
}


int		ft_check_result(int *mass)
{
	int i;

	i = 6;
	if (mass[i] == 9)
	{
		while (i >= 0 && mass[i] + 1 == 10)
		{
			mass[i] = 0;
			i--;
		}
	}
	return (0);
}
