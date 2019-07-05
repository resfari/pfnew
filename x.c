/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexconc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:07:09 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/05 19:07:09 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

void	ft_hex_display_minus(char *str, t_fl *fl, t_pf *pf, int len, char c)
{
	int i;

	i = 0;
	if (fl->flaglattice == 1)
		fl->width = fl->width - 2;
	while (i + len < fl->width)
	{
		fl->nol == 1 && fl->accuracy == -1 ? write(1, "0", 1) : write(1, " ", 1);
		i++;
		pf->value++;
	}
	i = 0;
	if (fl->flaglattice == 1)
	{
		c == 'x' ? write(1, "0x", 2) : write(1, "0X", 2);
		pf->value = pf->value + 2;
	}
	while (str[i] != '\0')
	{
		if (ft_isalpha((int)(str[i])))
			c == 'X' ? ft_putchar(str[i]) : ft_putchar(str[i] + 32);
		else
			write(1, &str[i], 1);
		pf->value++;
		i++;
	}
}

void	ft_hex_display(char *str, t_fl *fl, t_pf *pf, char c)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(str);
	if (fl->flagminus == 1)
	{
		if (fl->flaglattice == 1)
		{
			c == 'x' ? write(1, "0x", 2) : write(1, "0X", 2);
			pf->value = pf->value + 2;
			fl->width = fl->width - 2;
		}
		while (str[i] != '\0')
		{
			if (ft_isalpha((int)(str[i])))
				c == 'X' ? ft_putchar(str[i]) : ft_putchar(str[i] + 32);
			else
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
		ft_hex_display_minus(str, fl, pf, len, c);
}

uintmax_t		ft_hex_ditsribution(va_list list, char c, t_fl *fl, t_pf *pf)
{
	intmax_t num;
	char *str;
	int i;

	i = 0;
	if (fl->shh == 1)
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
	str = ft_itoa_base(num, 16);
	ft_hex_display(str, fl, pf, c);
	return (0);
}

int		ft_concx(char *s, va_list list, char c, t_pf *pf)
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
	x = ft_hex_ditsribution(list, c, fl1, pf);
	return (0);
}
