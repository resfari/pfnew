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

//int		*ft_add_one(int *res, int masssize, t_summ *summ)
//{
//	int *final;
//	int i;
//	int j;
//
//	i = 1;
//	j = 0;
//	final = (int*)malloc(sizeof(int) * (masssize + 1));
//	final[0] = 1;
//	while (j < masssize)
//	{
//		final[i] = res[j];
//		i++;
//		j++;
//	}
//	free(res);
//	res = final;
//	summ->size++;
//
//	return (res);
//}

t_summ		*ft_first_mean_two(int exp, t_summ *summ, int masssize)
{
	int i;
	int j;
	int size;
	int help;
	int mod;
	int *new;

	i = 1;
	new = (int*)malloc(sizeof(int) * masssize);
	ft_zero(new, masssize);
	summ->mass = (int*)malloc(sizeof(int) * masssize);
	ft_zero(summ->mass, masssize);
	summ->mass[0] = 2;
	summ->size = 0;

	if (exp == 1)
		return (summ);
	else if (exp == 0)
	{
		summ->mass[0] = 1;
		return (summ);
	}
	else
	{
		while (i < exp)
		{
			ft_zero(new, masssize);
			j = 0;
			size = summ->size;
			mod = 0;
			while (j < masssize && size >= 0)
			{
				help = summ->mass[size];
				new[j] = (help * 2) % 10 + mod;
				mod = 0;
				mod = (help * 2) / 10;
				j++;
				size--;
				if (size < 0 && mod > 0)
				{
					new[j] = mod;
					summ->size++;
				}
			}
			summ->mass = ft_reverse(new, 0, summ->size, masssize);
			i++;
		}
	}
	summ->et_size = summ->size;
	return (summ);
}

t_summ		*ft_delete_two(t_summ *summ, int masssize)
{
	int i;
	int j;
	int size;
	int help;
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
		help = summ->mass[i];
		new[j] = (help + mod * 10) / 2;
		mod = help % 2;
		j++;
		i++;
	}
	summ->mass = new;
	return (summ);
}

int		*ft_final_summ(int *res, t_summ *summ)
{
	int *final;
	int i;

	i = 1;
	final = (int*)malloc(sizeof(int) * 50);
	final[0] = 1;
	while (i < 50)
	{
		final[i] = res[i - 1];
		i++;
	}
	summ->size++;
	return (final);
}

int		*ft_calcsumm_two(int *first, int *second, t_summ *summ, int masssize)
{
	int i;
	int *res;
	int mod;
	int size;
	int equal;

	res = (int*)malloc(sizeof(int) * masssize);
	i = masssize - 1;
	mod = 0;
	size = summ->size;
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
		size--;
	}
	if (i < 0 && mod > 0)
		summ->edinica = 1;
	return (res);
}
