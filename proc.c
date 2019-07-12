/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:11:50 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/05 19:11:50 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

int		ft_procenthelp(t_fl *fl, t_pf *pf)
{
	if (fl->nol == 1)
	{
		while (fl->width - 1 > 0)
		{
			write(1, "0", 1);
			pf->value++;
			fl->width--;
		}
		write(1, "%", 1);
		pf->value++;
	}
	else
	{
		while (fl->width - 1 > 0)
		{
			write(1, " ", 1);
			pf->value++;
			fl->width--;
		}
		write(1, "%", 1);
		pf->value++;
	}
	return (1);
}

int		ft_conclusionproc(t_fl *fl, t_pf *pf)
{
	if (fl->flagminus == 1)
	{
		write(1, "%", 1);
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
		ft_procenthelp(fl, pf);
	return (1);
}

int		ft_concproc(char *s, t_pf *pf)
{
	t_fl *fl1;

	fl1 = (t_fl*)malloc(sizeof(t_fl) * 1);
	ft_flags(s, fl1);
	ft_width(s, fl1);
	ft_conclusionproc(fl1, pf);
	free(fl1);
	return (pf->value);
}
