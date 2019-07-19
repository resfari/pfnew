/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floatconc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:12:54 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/06/22 20:12:54 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

void	ft_your_soul_is_mine2(t_final *final, t_fl *fl)
{
	char c;

	while (final->i < fl->accuracy)
	{
		c = final->after[final->i++] + 48;
		write(1, &c, 1);
		fl->value++;
	}
	if (fl->flagminus == 1)
		while (fl->width-- > fl->f + 1)
			ft_float_write(fl, 4);
}

void	ft_your_soul_is_mine(t_final *final, t_fl *fl)
{
	fl->f = final->perenos2 + fl->finalsize + fl->accuracy + 1;
	if (fl->nol == 1 && fl->width > fl->f)
		ft_sign_put(fl);
	if (fl->flagminus == 0)
	{
		while (fl->width > fl->f + 1)
		{
			fl->nol == 1 ? write(1, "0", 1) : write(1, " ", 1);
			fl->width--;
			fl->value++;
		}
	}
	if (fl->puted == 0)
		ft_sign_put(fl);
	final->i = 0;
	if (final->perenos2 == 1)
		ft_float_write(fl, 1);
}

void	ft_finish_him(t_final *final, t_fl *fl)
{
	char	c;

	ft_your_soul_is_mine(final, fl);
	while (final->i < fl->masssize && fl->finalsize-- >= 0)
	{
		if (fl->edinica == 1)
		{
			ft_float_write(fl, 1);
			fl->edinica = 0;
		}
		c = final->before[final->i++] + 48;
		write(1, &c, 1);
		fl->value++;
	}
	if ((fl->accuracy == -1 || fl->accuracy == 0) && fl->flaglattice != 1)
		return ;
	else if ((fl->accuracy == -1 || fl->accuracy == 0) && fl->flaglattice == 1)
	{
		ft_float_write(fl, 2);
		return ;
	}
	final->i = 0;
	ft_float_write(fl, 2);
	ft_your_soul_is_mine2(final, fl);
}

void	ft_else(t_fl *fl, t_final *fin, t_summ *summ, int accuracy)
{
	ft_create_massive_for_accuracy(fin, fl, summ);
	if ((fl->accuracy == -1 || fl->accuracy == 0) && summ->mass[0] > 5)
		fin->perenos = 1;
	if (accuracy == 0 && ft_check_elements(summ->mass, fl) == 1
	&& summ->mass[0] == 5)
		fin->perenos = 1;
	if (fin->perenos == 1)
	{
		ft_zero(fin->acc, fl->masssize);
		fin->acc[fl->finalsize] = 1;
		ft_calcsumm_final(fin->acc, fl->final, fl->masssize, fin);
	}
	else
		fin->before = fl->final;
}

void	ft_accuracy_in_work(t_fl *fl, t_summ *summ)
{
	t_final	*fin;
	int		accuracy;

	accuracy = fl->accuracy;
	if (accuracy == -1)
		accuracy = 0;
	fin = (t_final*)malloc(sizeof(t_final) * 1);
	fin->perenos2 = 0;
	fin->count = 0;
	if (summ->mass[accuracy] >= 5)
		ft_else(fl, fin, summ, accuracy);
	else
	{
		fin->after = summ->mass;
		fin->before = fl->final;
	}
	ft_finish_him(fin, fl);
	free(fin);
}
