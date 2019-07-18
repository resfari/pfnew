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

void			ft_hex_display_minus_p2(char *str, t_fl *fl, t_pf *pf, char c)
{
	int i;

	i = 0;
	if ((fl->len != 1 && str[0] != '0') && fl->flaglattice == 1 && fl->nol == 0)
	{
		c == 'x' ? write(1, "0x", 2) : write(1, "0X", 2);
		pf->value = pf->value + 2;
	}
	while (fl->acc_x-- > 0)
	{
		pf->value++;
		write(1, "0", 1);
	}
	while (fl->len != 0 && str[i] != '\0')
	{
		if (ft_isalpha((int)(str[i])))
			c == 'X' ? ft_putchar(str[i]) : ft_putchar(str[i] + 32);
		else
			write(1, &str[i], 1);
		pf->value++;
		i++;
	}
}

void			ft_hex_display_minus(char *str, t_fl *fl, t_pf *pf, char c)
{
	int i;

	i = 0;
	fl->acc_x = 0;
	if ((fl->len == 1 && str[i] == '0') && fl->accuracy == 0)
	{
		fl->flaglattice = 0;
		fl->len = 0;
	}
	if (fl->accuracy > fl->len)
		fl->acc_x = fl->accuracy - fl->len;
	if (fl->flaglattice == 1)
		fl->width = fl->width - 2;
	if ((fl->len != 1 && str[0] != '0') && fl->flaglattice == 1 && fl->nol == 1)
	{
		c == 'x' ? write(1, "0x", 2) : write(1, "0X", 2);
		pf->value = pf->value + 2;
	}
	while (i++ + fl->len + fl->acc_x < fl->width)
	{
		fl->nol == 1 && (fl->accuracy == -1 || fl->accuracy == 0) ?
		write(1, "0", 1) : write(1, " ", 1);
		pf->value++;
	}
	ft_hex_display_minus_p2(str, fl, pf, c);
}

void			ft_hex_display(char *str, t_fl *fl, t_pf *pf, char c)
{
	int i;

	i = 0;
	fl->len = ft_strlen(str);
	if (fl->flagminus == 1)
	{
		if (fl->flaglattice == 1)
			c == 'x' ? ft_hex_norm(fl, pf, 3) : ft_hex_norm(fl, pf, 4);
		while (fl->accuracy-- > fl->len)
			ft_hex_norm(fl, pf, 2);
		while (str[i] != '\0')
		{
			if (ft_isalpha((int)(str[i])))
				c == 'X' ? ft_putchar(str[i]) : ft_putchar(str[i] + 32);
			else
				write(1, &str[i], 1);
			pf->value++;
			i++;
		}
		while (i++ < fl->width)
			ft_hex_norm(fl, pf, 1);
	}
	else
		ft_hex_display_minus(str, fl, pf, c);
}

uintmax_t		ft_hex_ditsribution(va_list list, char c, t_fl *fl, t_pf *pf)
{
	intmax_t	num;
	char		*str;
	int			i;

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
	if (num != 0)
		free(str);
	return (0);
}

int				ft_concx(char *s, va_list list, char c, t_pf *pf)
{
	uintmax_t	x;
	t_fl		*fl1;

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
	free(fl1);
	return (0);
}
