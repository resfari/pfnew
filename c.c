/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charconc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:19:03 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/06/21 13:19:03 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "./libft/libft.h"

int		ft_charhelp(t_fl *fl, int arg, t_pf *pf)
{
	while (fl->width - 1 > 0)
	{
		write (1, " ", 1);
		pf->value++;
		fl->width--;
	}
	ft_putchar((char)arg);
	pf->value++;
	return (1);
}

int		ft_conclusionchar(t_fl *fl, int arg, t_pf *pf)
{
	if (fl->flagminus == 1)
	{
		ft_putchar((char)arg);
		pf->value++;
		if (fl->width > 0)
		{
			while (fl->width - 1 > 0)
			{
				write(1, " ", 1);
				pf->value++;
				fl->width--;
			}
		}
	}
	if (fl->flagminus == 0)
	{
		ft_charhelp(fl, arg, pf);
	}
	return (1);
}

int		ft_concchar(char *s, va_list list, t_pf *pf)
{
	int c;
	t_fl *fl;

	fl = (t_fl*)malloc(sizeof(t_fl) * 1);
	c = va_arg(list, int);
	ft_flags(s, fl);
	ft_width(s, fl);
	ft_accuracy_str(s, fl);
	ft_conclusionchar(fl, c, pf);
	return (0);
}
