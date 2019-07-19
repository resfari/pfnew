/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:50:29 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/19 18:50:29 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

void	ft_mantissa_p4(t_fl *fl)
{
	if (fl->accuracy == -1 && fl->flaglattice == 1)
		ft_float_write(fl, 2);
	if (fl->accuracy == -1)
		return ;
	ft_float_write(fl, 2);
	if (fl->accuracy == 0)
		ft_float_write(fl, 3);
	while (fl->accuracy-- > 0)
		ft_float_write(fl, 3);
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

int		ft_conclongdouble(va_list list, t_fl *fl1)
{
	long double x;

	x = va_arg(list, long double);
	return (ft_conclusionlongdouble(fl1, x));
}

int		ft_concdouble(char *s, va_list list, t_pf *pf)
{
	double	x;
	t_fl	*fl1;

	fl1 = (t_fl*)malloc(sizeof(t_fl) * 1);
	ft_flags(s, fl1);
	ft_width(s, fl1);
	ft_accuracy(s, fl1);
	ft_lorllcheck(s, fl1);
	if (fl1->l == 80)
		pf->value = pf->value + ft_conclongdouble(list, fl1);
	else
	{
		x = va_arg(list, double);
		pf->value = pf->value + ft_conclusiondouble(fl1, x);
	}
	ft_free_fl1(fl1);
	return (0);
}
