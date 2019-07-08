/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octoconc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:06:26 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/05 19:06:26 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

void	ft_octo_display_minus(char *str, t_fl *fl, t_pf *pf, int len)
{
	int i;
	int acc;

	i = 0;
	acc = 0;
	if (fl->flaglattice == 1)
		fl->width--;
	if (fl->accuracy > len)
		acc = fl->accuracy - len;
	while (i + len + acc < fl->width)
	{
		fl->nol == 1 && fl->accuracy == -1 ? write(1, "0", 1) : write(1, " ", 1);
		i++;
		pf->value++;
	}
	i = 0;
	if (fl->flaglattice == 1)
	{
		write(1, "0", 1);
		pf->value++;
	}
	while (acc > 0)
	{
		acc--;
		pf->value++;
		write(1, "0", 1);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		pf->value++;
		i++;
	}
}

void	ft_octo_display(char *str, t_fl *fl, t_pf *pf)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(str);
	if (fl->flagminus == 1)
	{
		if (fl->flaglattice == 1)
		{
			write(1, "0", 1);
			pf->value++;
			fl->width--;
		}
		while (fl->accuracy > len)
		{
			fl->accuracy--;
			pf->value++;
			write(1, "0", 1);
			fl->width--;
		}
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			pf->value++;
			i++;
		}
		while (i < fl->width)
		{
			write(1, " ", 1);
			i++;
			pf->value++;
		}
	}
	else
		ft_octo_display_minus(str, fl, pf, len);
}

uintmax_t		ft_octo_ditsribution(va_list list, char c, t_fl *fl, t_pf *pf)
{
	intmax_t num;
	char *str;
	int i;

	i = 0;
	if (c == 'O')
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
	str = ft_itoa_base(num, 8);
	ft_octo_display(str, fl, pf);
	return (0);
}

int		ft_conco(char *s, va_list list, char c, t_pf *pf)
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
	x = ft_octo_ditsribution(list, c, fl1, pf);
	return (0);
}
