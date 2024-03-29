/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrconc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:05:07 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/05 19:05:07 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

void			ft_hex_display_norm(t_fl *fl, char *str, int i)
{
	int nol;

	nol = fl->nol;
	fl->len = ft_strlen(str);
	if (fl->len == 1 && str[i] == '0')
	{
		fl->flaglattice = 0;
		fl->len = 0;
		fl->nol = 0;
		if (fl->accuracy == -1)
		{
			fl->len = 1;
			fl->nol = nol;
		}
	}
	if (fl->accuracy != -1)
		fl->nol = 0;
}

void			ft_ptr_display_minus(char *str, t_fl *fl, t_pf *pf, int len)
{
	int i;

	i = 0;
	while (i + len + 2 < fl->width)
	{
		write(1, " ", 1);
		i++;
		pf->value++;
	}
	i = 0;
	write(1, "0x", 2);
	pf->value = pf->value + 2;
	fl->width = fl->width - 2;
	while (str[i] != '\0')
	{
		ft_isalpha((int)str[i]) == 1 ? ft_putchar(str[i] + 32)
		: ft_putchar(str[i]);
		pf->value++;
		i++;
	}
}

void			ft_ptr_display(char *str, t_fl *fl, t_pf *pf)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(str);
	if (fl->flagminus == 1)
	{
		write(1, "0x", 2);
		pf->value = pf->value + 2;
		fl->width = fl->width - 2;
		while (str[i] != '\0')
		{
			ft_isalpha((int)str[i]) == 1 ?
			ft_putchar(str[i] + 32) : ft_putchar(str[i]);
			pf->value++;
			i++;
		}
		while (i < fl->width)
		{
			ft_pf_write_norm(pf, fl, 2);
			i++;
		}
	}
	else
		ft_ptr_display_minus(str, fl, pf, len);
}

uintmax_t		ft_pointer_ditsribution(va_list list, t_fl *fl, t_pf *pf)
{
	intmax_t	num;
	char		*str;
	int			i;

	i = 0;
	num = (unsigned long)(va_arg(list, unsigned long int));
	num = (uintmax_t)num;
	str = ft_itoa_base(num, 16);
	ft_ptr_display(str, fl, pf);
	if (num != 0)
		free(str);
	return (0);
}

int				ft_concpointer(char *s, va_list list, t_pf *pf)
{
	intmax_t	x;
	t_fl		*fl1;

	fl1 = (t_fl*)malloc(sizeof(t_fl) * 1);
	ft_flags(s, fl1);
	ft_width(s, fl1);
	ft_accuracy_str(s, fl1);
	if (fl1->accuracy != -1 || (s[0] == '0' && ft_strlen(s) == 1))
		return (0);
	x = ft_pointer_ditsribution(list, fl1, pf);
	free(fl1);
	return (0);
}
