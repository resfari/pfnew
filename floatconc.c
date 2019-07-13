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

void	ft_finish_him(t_final *final, t_fl *fl)
{
	char	c;

	final->i = 0;
	if (final->perenos2 == 1)
		ft_float_write(fl, 1);
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
	final->i = 0;
	ft_float_write(fl, 2);
	while (final->i < fl->accuracy)
	{
		c = final->after[final->i++] + 48;
		write(1, &c, 1);
		fl->value++;
	}
	free(final);
}

void	ft_accuracy_in_work(t_fl *fl, t_summ *summ)
{
	t_final	*fin;

	fin = (t_final*)malloc(sizeof(t_final) * 1);
	fin->perenos2 = 0;
	if (summ->mass[fl->accuracy] >= 5)
	{
		fin->acc = (int*)malloc(sizeof(int) * fl->masssize);
		ft_zero(fin->acc, fl->masssize);
		fin->acc[fl->accuracy - 1] = 1;
		ft_calcsumm_final(fin->acc, summ->mass, fl->masssize, fin);
		if (fin->perenos == 1)
		{
			ft_zero(fin->acc, fl->masssize);
			fin->acc[fl->finalsize] = 1;
			ft_calcsumm_final_before(fin->acc, fl->final, fl->masssize, fin);
		}
		else
			fin->before = fl->final;
	}
	else
	{
		fin->after = summ->mass;
		fin->before = fl->final;
	}
	ft_finish_him(fin, fl);
}

int		ft_conclusiondouble(t_fl *fl1, double x)
{
	char	*str;
	int		sign;
	int		*mantissa;

	fl1->value = 0;
	fl1->i = 0;
	str = ft_checkbindouble(fl1, x);
	sign = ft_check_sign(str[0]);
	fl1->exp = ft_check_exp(str, fl1) - fl1->e;
	mantissa = ft_check_mantissa(str, fl1);
	ft_calc_mantissa_before(mantissa, fl1);
	return (fl1->value);
}

int		ft_conclusionfloat(t_fl *fl1, float x)
{
	char	*str;
	int		sign;
	int		*mantissa;

	fl1->value = 0;
	fl1->i = 0;
	str = ft_checkbinfloat(fl1, x);
	sign = ft_check_sign(str[0]);
	fl1->exp = ft_check_exp(str, fl1) - fl1->e;
	mantissa = ft_check_mantissa(str, fl1);
	ft_calc_mantissa_before(mantissa, fl1);
	return (fl1->value);
}

int		ft_conclusionlongdouble(t_fl *fl1, long double x)
{
	char	*str;
	int		sign;
	int		*mantissa;

	fl1->value = 0;
	fl1->i = 0;
	str = ft_checkbinlongdouble(fl1, x);
	sign = ft_check_sign(str[0]);
	fl1->exp = ft_check_exp(str, fl1) - fl1->e;
	mantissa = ft_check_mantissa(str, fl1);
	ft_calc_mantissa_before(mantissa, fl1);
	return (fl1->value);
}
