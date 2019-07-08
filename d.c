/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:10:49 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/05 19:10:49 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

void	ft_size_width_check_flags(int sign, t_fl *fl)
{
	if (fl->flagplus == 1 || fl->flagspace == 1)
		fl->width--;
	else
	{
		if (sign < 0)
			fl->width--;
	}
}

int		ft_int_sign_display(int sign, t_fl *fl, t_pf *pf)
{
	if (fl->flagplus == 1)
	{
		sign < 0 ? write(1, "-", 1) : write(1, "+", 1);
		pf->value++;
	}
	else if (fl->flagspace == 1)
	{
		sign < 0 ? write(1, "-", 1) : write(1, " ", 1);
		pf->value++;
	}
	else
	{
		if (sign < 0)
		{
			write(1, "-", 1);
			pf->value++;
		}
	}
	return (0);
}

int		ft_int_width_display_minus(t_fl *fl, t_pf *pf)
{
	while (fl->width > 0)
	{
		write(1, " ", 1);
		pf->value++;
		fl->width--;
	}
	return (0);
}

int		ft_int_width_display_offminus(int acc, int len, t_fl *fl, t_pf *pf, int sign)
{

	if (fl->nol == 1)
		ft_int_sign_display(sign, fl, pf);
	while (fl->width > acc + len)
	{
		fl->nol == 1 && fl->accuracy == -1? write(1, "0", 1) : write(1, " ", 1);
		pf->value++;
		fl->width--;
	}
	if (fl->nol != 1)
		ft_int_sign_display(sign, fl, pf);
	return (0);
}

void	ft_int_accuracy_display(int acc, t_fl *fl, t_pf *pf)
{
	while (acc > 0)
	{
		write(1, "0", 1);
		fl->width--;
		pf->value++;
		acc--;
	}
}

void	ft_int_display_str(char *str, int len, t_pf *pf, t_fl *fl)
{
	write(1, str, len);
	pf->value = pf->value + len;
	fl->width = fl->width - len;
}

void	ft_int_display(char *str, t_fl *fl, t_pf *pf, int sign)
{
	int len;
	int acc;

	acc = 0;
	len = ft_strlen(str);
	ft_size_width_check_flags(sign, fl);
	if (fl->accuracy > len)
		acc = fl->accuracy - len;
	if (fl->flagminus == 1)
	{
		ft_int_sign_display(sign, fl, pf);
		ft_int_accuracy_display(acc, fl, pf);
		ft_int_display_str(str, len, pf, fl);
		ft_int_width_display_minus(fl, pf);
	}
	else
	{
		ft_int_width_display_offminus(acc, len, fl, pf, sign);
		ft_int_accuracy_display(acc, fl, pf);
		ft_int_display_str(str, len, pf, fl);
	}
}

intmax_t		ft_int_ditsribution(va_list list, char c, t_fl *fl, t_pf *pf)
{
	intmax_t num;
	char *str;
	int i;
	int sign;

	i = 0;
	sign = 0;
	if (c == 'D')
		num = (long)(va_arg(list, long int));
	else if (fl->shh == 1)
		num = (signed char)(va_arg(list, int));
	else if (fl->sh == 1)
		num = (short)(va_arg(list, int));
	else if (fl->sll == 1)
		num = (long long)(va_arg(list, long long int));
	else if (fl->sl == 1)
		num = (long)(va_arg(list, long int));
	else
	num = (int)(va_arg(list, int));
	num >= 0 ? sign++ : sign--;
	if (num < 0)
		num = num * (-1);
	num = (intmax_t)num;
	str = ft_ltoa(num);
	ft_int_display(str, fl, pf, sign);
	return (0);
}

int 	ft_concint(char *s, va_list list, char c, t_pf *pf)
{
	intmax_t x;
	t_fl *fl1;

	fl1 = (t_fl*)malloc(sizeof(t_fl) * 1);
	fl1->sl = 0;
	fl1->sll = 0;
	fl1->sh = 0;
	fl1->shh = 0;
	ft_flags(s, fl1);
	ft_width(s, fl1);
	ft_accuracy_str(s, fl1);
	ft_lllhhh(s, fl1);
	x = ft_int_ditsribution(list, c, fl1, pf);
	return (0);
}
