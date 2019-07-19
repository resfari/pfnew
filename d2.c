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

int		ft_check_max(char *str, int count, t_fl *fl)
{
	int			i;
	const char	*mlg;
	int			num;
	int			j;

	j = 0;
	num = 0;
	mlg = "2147483649";
	i = count;
	if (str[i] == '.')
		i++;
	while (mlg[j] != '\0' && str[i] != '\0')
	{
		if (str[i] == mlg[j])
			num++;
		i++;
		j++;
	}
	if (num == 10)
	{
		fl->lastpos = i;
		fl->accuracy = 6;
		return (1);
	}
	return (0);
}

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
