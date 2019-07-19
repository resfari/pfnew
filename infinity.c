/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:52:52 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/19 18:12:01 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

void	ft_display_inf_no_minus(t_fl *fl)
{
	while (fl->width-- > 3)
		ft_float_write(fl, 4);
	ft_sign_put(fl);
	write(1, "inf", 3);
	fl->value = fl->value + 3;
	return ;
}

void	ft_display_inf(t_fl *fl)
{
	if (fl->flagminus == 1)
	{
		ft_sign_put(fl);
		write(1, "inf", 3);
		fl->value = fl->value + 3;
		while (fl->width-- > 3)
			ft_float_write(fl, 4);
		return ;
	}
	else
		ft_display_inf_no_minus(fl);
}

int		ft_check_infinity(t_fl *fl)
{
	int			i;
	char		c;
	const char	*inf;

	i = 0;
	inf = "17976931348623159077293051907890247336179769789423065727343008"
	"115773267580550096313270847732240753602112011387987139335765878976881"
	"441662249284743063947412437776789342486548527630221960124609411945308"
	"295208500576883815068234246288147391311054082723716335051068458629823"
	"9947245938479716304835356329624224137216";
	while (i < 309)
	{
		c = fl->final[i] + 48;
		if (inf[i] == c)
			i++;
		else
			return (0);
	}
	if (i == 309)
	{
		ft_display_inf(fl);
		return (1);
	}
	return (0);
}
