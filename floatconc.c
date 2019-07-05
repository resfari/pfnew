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

int		ft_check_sign(char c)
{
	if (c == '1')
	{
		write(1, "-", 1);
		return (-1);
	}
	else
		return (1);
}

int		ft_check_exp(char *str, t_fl *fl)
{
	char *s;
	int i;
	int last;
	int start;

	if (fl->l == 80)
	{
		last = 15;
		start = 1;
	}
	else if (fl->l == 64)
	{
		last = 11;
		start = 1;
	}
	else
	{
		last = 8;
		start = 1;
	}
	s = ft_strsub(str, start, last);
	i = ft_atoi_base(s, 2);
	return (i);
}

char	*ft_checkbindouble(t_fl *fl1, double x)
{
	unsigned char *p;
	int i;
	int j;
	char *str;
	int d;

	d = 0;
	str = (char*)malloc(sizeof(char) * (fl1->l + 1));
	str[fl1->l] = '\0';
	p = ((unsigned char*) &x);
	j = fl1->l - 1;
	while (d < fl1->l / 8)
	{
		i = 0;
		while (i < 8)
		{
			if (p[d] & 1 << i)
				str[j] = '1';
			else
				str[j] = '0';
			j--;
			i++;
		}
		d++;
	}
	return (str);
}

char	*ft_checkbinfloat(t_fl *fl1, float x)
{
	unsigned char *p;
	int i;
	int j;
	char *str;
	int d;

	d = 0;
	str = (char*)malloc(sizeof(char) * (fl1->l + 1));
	str[fl1->l] = '\0';
	p = ((unsigned char*) &x);
	j = fl1->l - 1;
	while (d < fl1->l / 8)
	{
		i = 0;
		while (i < 8)
		{
			if (p[d] & 1 << i)
				str[j] = '1';
			else
				str[j] = '0';
			j--;
			i++;
		}
		d++;
	}
	return (str);
}

char	*ft_checkbinlongdouble(t_fl *fl1, long double x)
{
	unsigned char *p;
	int i;
	int j;
	char *str;
	int d;

	d = 0;
	str = (char*)malloc(sizeof(char) * (fl1->l + 1));
	str[fl1->l] = '\0';
	p = ((unsigned char*) &x);
	j = fl1->l - 1;
	while (d < fl1->l / 8)
	{
		i = 0;
		while (i < 8)
		{
			if (p[d] & 1 << i)
				str[j] = '1';
			else
				str[j] = '0';
			j--;
			i++;
		}
		d++;
	}
	return (str);
}

int		*ft_check_mantissa(char *str, t_fl *fl)
{
	int i;
	int *mass;
	int j;

	i = fl->start;
	mass = (int*)malloc(sizeof(int) * (fl->m) + 1);
	if (fl->l == 64 || fl->l == 32)
	{
		mass[0] = 1;
		j = 1;
	}
	else
	{
		j = 0;
	}
	while(i <= fl->l)
	{
		if (str[i] == '1')
			mass[j] = 1;
		else
			mass[j] = 0;
		j++;
		i++;
	}
	return (mass);
}

double		ft_square(int d, int power)
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

int 	*ft_copymass(int *mass, int size)
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


void	ft_calc_mantissa_before(int *man, int exp, t_fl *fl)
{
	int i;
	int *old;
	int *result;
	t_summ *qwer;

	result = NULL;
	qwer = (t_summ*)malloc(sizeof(t_summ) * 1);
	qwer->edinica = 0;
	i = 0;
	if (exp >= 0)
	{
		ft_first_mean_two(exp, qwer, fl->masssize);
		result = ft_copymass(qwer->mass, fl->masssize);
		exp--;
		i++;
	}
	while (exp >= 0 && i <= fl->m)
	{
		if (man[i] == 1)
		{
			old = ft_copymass(result, fl->masssize);
			qwer = ft_delete_two(qwer, fl->masssize);
			result = ft_calcsumm_two(old, qwer->mass, qwer, fl->masssize);
		}
		else
			qwer= ft_delete_two(qwer, fl->masssize);
		i++;
		exp--;
	}
	if (result == NULL)
	{
		result = (int*)malloc(sizeof(int) * 1);
		qwer->size = 0;
		result[0] = 0;
	}
	fl->final = result;
	fl->finalsize = qwer->size;
	fl->edinica = qwer->edinica;
	ft_calc_mantissa_over(man, exp, i, fl);
	return ;
}

void		ft_calc_mantissa_over(int *man, int exp, int i, t_fl *fl)
{
	int *old;
	t_summ *summ;
	int *result;
	char c;

	summ = (t_summ*)malloc(sizeof(t_summ) * 1);
	exp = exp * (-1);
	if (i > fl->m)
	{
		i = 0;
		if (fl->edinica == 1)
		{
			write(1, "1", 1);
			fl->edinica = 0;
		}
		while (i < fl->masssize && fl->finalsize >= 0)
		{
			c = fl->final[i] + 48;
			write(1, &c, 1);
			i++;
			fl->finalsize--;
		}
		write(1, ".", 1);
		while (fl->accuracy > 0)
		{
			write(1, "0", 1);
			fl->accuracy--;
		}
		return;
	}
	else
	{
		while (man[i] != 1)
		{
			i++;
			exp++;
		}
		summ = ft_summastart(exp, summ, fl->masssize);
		result = ft_copymass(summ->mass, fl->masssize);
		i++;
		exp++;
		while (i <= fl->m)
		{
			if (man[i] == 1)
			{
				old = ft_copymass(result, fl->masssize);
				summ = ft_fivemulti(1, summ, fl->masssize);
				result = ft_calcsumm(old, summ->mass, fl->masssize);
			}
			else
				summ = ft_fivemulti(1, summ, fl->masssize);
			i++;
			exp++;
		}
		summ->mass = result;
		ft_accuracy_in_work(fl, summ);
	}
}

void	ft_finish_him(t_final *final, t_fl *fl)
{
	int i;
	char c;

	i = 0;
	if (final->perenos2 == 1)
		write(1, "1", 1);
	while (i < fl->masssize && fl->finalsize >= 0)
	{
		if (fl->edinica == 1)
		{
			write(1, "1", 1);
			fl->edinica = 0;
		}
		c = final->before[i] + 48;
		write(1, &c, 1);
		i++;
		fl->finalsize--;
	}
	i = 0;
	write(1, ".",  1);
	while (i < fl->accuracy)
	{
		c = final->after[i] + 48;
		write(1, &c, 1);
		i++;
	}
}

void	ft_accuracy_in_work(t_fl *fl, t_summ *summ)
{
	int *acc;
	t_final *final;

	final = (t_final*)malloc(sizeof(t_final) * 1);
	final->perenos2 = 0;
	if (summ->mass[fl->accuracy] >= 5)
	{
		acc = (int*)malloc(sizeof(int) * fl->masssize);
		ft_zero(acc, fl->masssize);
		acc[fl->accuracy - 1] = 1;
		ft_calcsumm_final(acc, summ->mass, fl->masssize, final);
		if (final->perenos == 1)
		{
			ft_zero(acc, fl->masssize);
			acc[fl->finalsize] = 1;
			ft_calcsumm_final_before(acc, fl->final, fl->masssize, final);
		}
		else
			final->before = fl->final;
	}
	else
	{
		final->after = summ->mass;
		final->before = fl->final;
	}
	ft_finish_him(final, fl);
}


void	ft_conclusiondouble(t_fl *fl1, double x)
{
	char *str;
	int sign;
	int exp;
	int *mantissa;

	str = ft_checkbindouble(fl1, x);
	sign = ft_check_sign(str[0]);
	exp = ft_check_exp(str, fl1) - fl1->e;
	mantissa = ft_check_mantissa(str, fl1);
	ft_calc_mantissa_before(mantissa, exp, fl1);
}

void	ft_conclusionfloat(t_fl *fl1, float x)
{
	char *str;
	int sign;
	int exp;
	int *mantissa;

	str = ft_checkbinfloat(fl1, x);
	sign = ft_check_sign(str[0]);
	exp = ft_check_exp(str, fl1) - fl1->e;
	mantissa = ft_check_mantissa(str, fl1);
	ft_calc_mantissa_before(mantissa, exp, fl1);
}

void	ft_conclusionlongdouble(t_fl *fl1, long double x)
{
	char *str;
	int sign;
	int exp;
	int *mantissa;

	str = ft_checkbinlongdouble(fl1, x);
	sign = ft_check_sign(str[0]);
	exp = ft_check_exp(str, fl1) - fl1->e;
	mantissa = ft_check_mantissa(str, fl1);
	ft_calc_mantissa_before(mantissa, exp, fl1);
}
