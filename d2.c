/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 19:56:40 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/12 19:56:40 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

void	ft_size_width_check_flags(t_fl *fl)
{
	if (fl->flagplus == 1 || fl->flagspace == 1)
		fl->width--;
	else
	{
		if (fl->sign < 0)
			fl->width--;
	}
}

int		ft_int_sign_display(t_fl *fl, t_pf *pf)
{
	if (fl->flagplus == 1)
	{
		fl->sign < 0 ? write(1, "-", 1) : write(1, "+", 1);
		pf->value++;
	}
	else if (fl->flagspace == 1)
	{
		fl->sign < 0 ? write(1, "-", 1) : write(1, " ", 1);
		pf->value++;
	}
	else
	{
		if (fl->sign < 0)
		{
			write(1, "-", 1);
			pf->value++;
		}
	}
	return (0);
}

int		ft_int_width_display_minus(t_fl *fl, t_pf *pf)
{
	while (fl->width > 0)
	{
		write(1, " ", 1);
		pf->value++;
		fl->width--;
	}
	return (0);
}

void	ft_int_accuracy_display(int acc, t_fl *fl, t_pf *pf)
{
	while (acc > 0)
	{
		write(1, "0", 1);
		fl->width--;
		pf->value++;
		acc--;
	}
}
