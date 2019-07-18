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

void	ft_sign_put(t_fl *fl)
{
	fl->puted = 1;
	if (fl->sign == 1)
	{
		fl->value++;
		write(1, "-", 1);
	}
	else if (fl->flagplus == 1 && fl->sign == 0)
	{
		fl->value++;
		write(1, "+", 1);
	}
	else if (fl->flagspace == 1 && fl->sign == 0)
	{
		fl->value++;
		write(1, " ", 1);
	}
	else
		return ;
}

void	ft_finish_him(t_final *final, t_fl *fl)
{
	char	c;
	int 	FULL_SIZE;

	FULL_SIZE = final->perenos2 + fl->finalsize + fl->accuracy + 1;
	if (fl->nol == 1 && fl->width > FULL_SIZE)
		ft_sign_put(fl);
	if (fl->flagminus == 0)
	{
		while (fl->width > FULL_SIZE + 1)
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
	while (final->i < fl->masssize && fl->finalsize-- >= 0)
	{
		if (fl->edinica == 1)
		{
			write(1, "1", 1);
			fl->edinica = 0;
			fl->value++;
		}
		c = final->before[final->i++] + 48;
		write(1, &c, 1);
		fl->value++;
	}
	if ((fl->accuracy == -1 || fl->accuracy == 0) && fl->flaglattice != 1)
		return ;
	else if ((fl->accuracy == -1 || fl->accuracy == 0) && fl->flaglattice == 1)
	{
		write(1, ".", 1);
		fl->value++;
		return ;
	}
	final->i = 0;
	ft_float_write(fl, 2);
	while (final->i < fl->accuracy)
	{
		c = final->after[final->i++] + 48;
		write(1, &c, 1);
		fl->value++;
	}
	if (fl->flagminus == 1)
	{
		while (fl->width > FULL_SIZE + 1)
		{
			fl->width--;
			write(1, " ", 1);
			fl->value++;
		}
	}
}

int	ft_check_elements(int *mass, t_fl *fl)
{
	int i;

	i = 1;
	while (i < 6)
	{
		if (mass[i] > 0)
			return (1);
		i++;
	}
	if (fl->final[fl->finalsize] % 2 != 0)
		return (1);
	return (0);
}

void	ft_accuracy_in_work(t_fl *fl, t_summ *summ)
{
	t_final	*fin;
	int accuracy;

	accuracy = fl->accuracy;
	if (accuracy == -1)
		accuracy = 0;
	fin = (t_final*)malloc(sizeof(t_final) * 1);
	fin->perenos2 = 0;
	fin->count = 0;
	if (summ->mass[accuracy] >= 5)
	{
		ft_create_massive_for_accuracy(fin, fl, summ);
		if ((fl->accuracy == -1 ||  fl->accuracy == 0) &&  summ->mass[0] > 5)
			fin->perenos = 1;
		if (accuracy == 0 && ft_check_elements(summ->mass, fl) == 1 && summ->mass[0] == 5)
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
	int		*mantissa;

	fl1->value = 0;
	fl1->i = 0;
	str = ft_checkbindouble(fl1, x);
	fl1->sign = ft_check_sign(str[0], fl1);
	fl1->exp = ft_check_exp(str, fl1) - fl1->e;
	mantissa = ft_check_mantissa(str, fl1);
	ft_calc_mantissa_before(mantissa, fl1);
	return (fl1->value);
}

int		ft_conclusionfloat(t_fl *fl1, float x)
{
	char	*str;
	int		*mantissa;

	fl1->value = 0;
	fl1->i = 0;
	str = ft_checkbinfloat(fl1, x);
	fl1->sign = ft_check_sign(str[0], fl1);
	fl1->exp = ft_check_exp(str, fl1) - fl1->e;
	mantissa = ft_check_mantissa(str, fl1);
	ft_calc_mantissa_before(mantissa, fl1);
	return (fl1->value);
}

int		ft_conclusionlongdouble(t_fl *fl1, long double x)
{
	char	*str;
	int		*mantissa;

	fl1->value = 0;
	fl1->i = 0;
	str = ft_checkbinlongdouble(fl1, x);
	fl1->sign = ft_check_sign(str[0], fl1);
	fl1->exp = ft_check_exp(str, fl1) - fl1->e;
	mantissa = ft_check_mantissa(str, fl1);
	ft_calc_mantissa_before(mantissa, fl1);
	return (fl1->value);
}
