/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mantisa_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 19:11:58 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/13 19:11:58 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

int		*ft_calc_if_man_equal_1(t_fl *fl, int *result, t_summ *qwer, int norm)
{
	int *old;

	if (norm == 1)
	{
		old = ft_copymass(result, fl->masssize);
		qwer = ft_delete_two(qwer, fl->masssize);
		return (ft_calcsumm_two(old, qwer->mass, qwer, fl->masssize));
	}
	else
	{
		old = ft_copymass(result, fl->masssize);
		qwer = ft_fivemulti(1, qwer, fl->masssize);
		return (ft_calcsumm(old, qwer->mass, fl->masssize));
	}
}

void	ft_calc_man(t_fl *fl, int *result, t_summ *qwer)
{
	if (result == NULL)
	{
		result = (int*)malloc(sizeof(int) * 1);
		qwer->size = 0;
		result[0] = 0;
	}
	fl->final = result;
	fl->finalsize = qwer->size;
	fl->edinica = qwer->edinica;
}

void	ft_calc_mantissa_before(int *man, t_fl *fl)
{
	int		*result;
	t_summ	*qwer;

	result = NULL;
	qwer = (t_summ*)malloc(sizeof(t_summ) * 1);
	qwer->edinica = 0;
	if (fl->exp >= 0)
	{
		ft_first_mean_two(fl->exp, qwer, fl->masssize);
		result = ft_copymass(qwer->mass, fl->masssize);
		fl->exp--;
		fl->i++;
	}
	while (fl->exp >= 0 && fl->i <= fl->m)
	{
		if (man[fl->i] == 1)
			result = ft_calc_if_man_equal_1(fl, result, qwer, 1);
		else
			qwer = ft_delete_two(qwer, fl->masssize);
		fl->i++;
		fl->exp--;
	}
	ft_calc_man(fl, result, qwer);
	ft_calc_mantissa_over(man, fl);
	return ;
}

void	ft_calc_man_over_p2(int *man, t_fl *fl)
{
	int		*result;
	t_summ	*summ;

	summ = (t_summ*)malloc(sizeof(t_summ) * 1);
	while (man[fl->i] != 1)
	{
		fl->i++;
		fl->exp++;
	}
	summ = ft_summastart(fl->exp, summ, fl->masssize);
	result = ft_copymass(summ->mass, fl->masssize);
	fl->i++;
	fl->exp++;
	while (fl->i <= fl->m)
	{
		if (man[fl->i] == 1)
			result = ft_calc_if_man_equal_1(fl, result, summ, 2);
		else
			summ = ft_fivemulti(1, summ, fl->masssize);
		fl->i++;
		fl->exp++;
	}
	summ->mass = result;
	ft_accuracy_in_work(fl, summ);
}

void	ft_calc_mantissa_over(int *man, t_fl *fl)
{
	char	c;

	fl->exp = fl->exp * (-1);
	if (fl->i > fl->m)
	{
		fl->i = 0;
		if (fl->itsf == 1 && (ft_check_infinity(fl) == 1 || ft_check_nan(fl) == 1))
			return ;
		ft_sign_put(fl);
		if (fl->edinica == 1)
		{
			ft_float_write(fl, 1);
			fl->edinica = 0;
		}
		while (fl->i < fl->masssize && fl->finalsize >= 0)
		{
			c = fl->final[fl->i++] + 48;
			write(1, &c, 1);
			fl->value++;
			fl->finalsize--;
		}
		if (fl->accuracy == -1 && fl->flaglattice == 1)
			ft_float_write(fl, 2);
		if (fl->accuracy == -1)
			return ;
		ft_float_write(fl, 2);
		if (fl->accuracy == 0)
			ft_float_write(fl, 3);
		while (fl->accuracy-- > 0)
			ft_float_write(fl, 3);
		return ;
	}
	ft_calc_man_over_p2(man, fl);
}
