/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 21:33:43 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/12 21:33:43 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

void		ft_octo_norm(char *str, t_pf *pf, int len)
{
	int i;

	i = 0;
	while (len != 0 && str[i] != '\0')
	{
		write(1, &str[i], 1);
		pf->value++;
		i++;
	}
}

void		ft_free_fl1(t_fl *fl)
{
	if (fl->final)
		free(fl->final);
	free(fl);
}

void		ft_hex_norm(t_fl *fl, t_pf *pf, int norm)
{
	if (norm == 1)
	{
		write(1, " ", 1);
		pf->value++;
	}
	if (norm == 2)
	{
		pf->value++;
		write(1, "0", 1);
		fl->width--;
	}
	if (norm == 3)
	{
		write(1, "0x", 2);
		pf->value = pf->value + 2;
		fl->width = fl->width - 2;
	}
	if (norm == 4)
	{
		write(1, "0X", 2);
		pf->value = pf->value + 2;
		fl->width = fl->width - 2;
	}
}

int			ft_uint_width_display_minus(t_fl *fl, t_pf *pf)
{
	while (fl->width > 0)
	{
		write(1, " ", 1);
		pf->value++;
		fl->width--;
	}
	return (0);
}

int			ft_uint_width_display_offminus(int acc, int len, t_fl *fl, t_pf *pf)
{
	while (fl->width > acc + len)
	{
		fl->nol == 1 && fl->accuracy == -1
		? write(1, "0", 1) : write(1, " ", 1);
		pf->value++;
		fl->width--;
	}
	return (0);
}
