/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:52:52 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/18 16:52:52 by lgeorgia         ###   ########.fr       */
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
	int i;
	char c;
	const char *inf;

	i = 0;
	inf = "17976931348623159077293051907890247336179769789423065727343008115773"
		  "26758055009631327084773224075360211201138798713933576587897688144166"
	"22492847430639474124377767893424865485276302219601246094119453082952085005"
 "76883815068234246288147391311054082723716335051068458629823994724593847971630"
 "4835356329624224137216";
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
