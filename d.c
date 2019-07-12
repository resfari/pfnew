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

int			ft_int_width_display_offminus(int acc, t_fl *fl,
		t_pf *pf, char *str)
{
	if (fl->nol == 1)
		ft_int_sign_display(fl, pf);
	if (fl->len == 1 && str[0] == '0' && fl->accuracy == 0)
		fl->width++;
	while (fl->width > acc + fl->len)
	{
		fl->nol == 1 && fl->accuracy == -1 ? write(1, "0", 1) :
		write(1, " ", 1);
		pf->value++;
		fl->width--;
	}
	if (fl->nol != 1)
		ft_int_sign_display(fl, pf);
	return (0);
}

void		ft_int_display_str(char *str, t_pf *pf, t_fl *fl)
{
	if (fl->len == 1 && str[0] == '0' && fl->accuracy == 0)
		fl->len = 0;
	else
	{
		write(1, str, fl->len);
		pf->value = pf->value + fl->len;
		fl->width = fl->width - fl->len;
	}
}

void		ft_int_display(char *str, t_fl *fl, t_pf *pf)
{
	int acc;

	acc = 0;
	fl->len = ft_strlen(str);
	ft_size_width_check_flags(fl);
	if (fl->len == 1 && str[0] == '0' && fl->accuracy == 0)
		fl->len = 0;
	if (fl->accuracy > fl->len)
		acc = fl->accuracy - fl->len;
	if (fl->flagminus == 1)
	{
		ft_int_sign_display(fl, pf);
		ft_int_accuracy_display(acc, fl, pf);
		ft_int_display_str(str, pf, fl);
		ft_int_width_display_minus(fl, pf);
	}
	else
	{
		ft_int_width_display_offminus(acc, fl, pf, str);
		ft_int_accuracy_display(acc, fl, pf);
		ft_int_display_str(str, pf, fl);
	}
}

intmax_t	ft_int_ditsribution(va_list list, char c, t_fl *fl, t_pf *pf)
{
	intmax_t	num;
	char		*str;
	int			i;

	i = 0;
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
	num >= 0 ? fl->sign++ : fl->sign--;
	if (num < 0)
		num = num * (-1);
	num = (intmax_t)num;
	str = ft_ltoa(num);
	ft_int_display(str, fl, pf);
	free(str);
	return (0);
}

int			ft_concint(char *s, va_list list, char c, t_pf *pf)
{
	intmax_t	x;
	t_fl		*fl1;

	fl1 = (t_fl*)malloc(sizeof(t_fl) * 1);
	fl1->sl = 0;
	fl1->sll = 0;
	fl1->sh = 0;
	fl1->shh = 0;
	fl1->sign = 0;
	ft_flags(s, fl1);
	ft_width(s, fl1);
	ft_accuracy_str(s, fl1);
	ft_lllhhh(s, fl1);
	x = ft_int_ditsribution(list, c, fl1, pf);
	free(fl1);
	return (0);
}
