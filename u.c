/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:09:52 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/05 19:09:52 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

int		ft_uint_width_display_minus(t_fl *fl, t_pf *pf)
{
	while (fl->width > 0)
	{
		write(1, " ", 1);
		pf->value++;
		fl->width--;
	}
	return (0);
}

int		ft_uint_width_display_offminus(int acc, int len, t_fl *fl, t_pf *pf)
{
	while (fl->width > acc + len)
	{
		fl->nol == 1 && fl->accuracy == -1? write(1, "0", 1) : write(1, " ", 1);
		pf->value++;
		fl->width--;
	}
	return (0);
}

void	ft_uint_accuracy_display(int acc, t_fl *fl, t_pf *pf)
{
	while (acc > 0)
	{
		write(1, "0", 1);
		fl->width--;
		pf->value++;
		acc--;
	}
}

void	ft_uint_display_str(char *str, int len, t_pf *pf, t_fl *fl)
{
	write(1, str, len);
	pf->value = pf->value + len;
	fl->width = fl->width - len;
}

void	ft_uint_display(char *str, t_fl *fl, t_pf *pf)
{
	int len;
	int acc;

	acc = 0;
	len = ft_strlen(str);
	if (len == 1 && str[0] == '0' && fl->accuracy == 0)
		len = 0;
	if (fl->accuracy > len)
		acc = fl->accuracy - len;
	if (fl->flagminus == 1)
	{

		ft_uint_accuracy_display(acc, fl, pf);
		ft_uint_display_str(str, len, pf, fl);
		ft_uint_width_display_minus(fl, pf);
	}
	else
	{
		ft_uint_width_display_offminus(acc, len, fl, pf);
		ft_uint_accuracy_display(acc, fl, pf);
		ft_uint_display_str(str, len, pf, fl);
	}
}

uintmax_t		ft_uint_ditsribution(va_list list, char c, t_fl *fl, t_pf *pf)
{
	intmax_t num;
	char *str;
	int i;

	i = 0;
	if (c == 'U')
		num = (unsigned long)(va_arg(list, unsigned long int));
	else if (fl->shh == 1)
		num = (unsigned char)(va_arg(list, unsigned int));
	else if (fl->sh == 1)
		num = (unsigned short)(va_arg(list, unsigned int));
	else if (fl->sll == 1)
		num = (unsigned long long)(va_arg(list, unsigned long long int));
	else if (fl->sl == 1)
		num = (unsigned long)(va_arg(list, unsigned long int));
	else
		num = (unsigned int)(va_arg(list, unsigned int));
	num = (uintmax_t)num;
	str = ft_utoa(num);
	ft_uint_display(str, fl, pf);
	return (0);
}

int 	ft_concu(char *s, va_list list, char c, t_pf *pf)
{
	uintmax_t x;
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
	x = ft_uint_ditsribution(list, c, fl1, pf);
	return (0);
}
