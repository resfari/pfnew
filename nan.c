/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nan.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:01:27 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/18 17:01:27 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

void	ft_display_nan_no_minus(t_fl *fl)
{
	while (fl->width > 3)
	{
		ft_float_write(fl, 4);
		fl->width--;
	}
	write(1, "nan", 3);
	fl->value = fl->value + 3;
	return ;
}

void	ft_display_nan(t_fl *fl)
{
	if (fl->flagplus == 1 || fl->flagspace == 1)
		fl->width++;
	if (fl->flagminus == 1)
	{
		write(1, "nan", 3);
		fl->value = fl->value + 3;
		while (fl->width > 3)
		{
			ft_float_write(fl, 4);
			fl->width--;
		}
		return ;
	}
	else
		ft_display_nan_no_minus(fl);
}

int		ft_check_nan(t_fl *fl)
{
	int i;
	char c;
	const char *nan;

	i = 0;
	nan = "26965397022934738615939577861835371004269654684134598591014512173659"
	   "90137082514446990627159836113040316801708198070900364881846532216249"
	"33739271145959211186566651840137298227914453329401869141179179624428127"
 "508653257226023513694322210869665811240855745025766026879447359920868907"
 "719574457253034494436336205824";
	while (i < 309)
	{
		c = fl->final[i] + 48;
		if (nan[i] == c)
			i++;
		else
			return (0);
	}
	if (i == 309)
	{
		ft_display_nan(fl);
		return (1);
	}
	return (0);
}