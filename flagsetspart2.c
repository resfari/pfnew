/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagsetspart2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 21:00:04 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/12 21:00:04 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

int		ft_lllhhh(char *str, t_fl *fl)
{
	int i;

	i = fl->lastpos;
	if (str[i] == 'l')
	{
		i++;
		if (str[i] == 'l')
		{
			fl->sll = 1;
		}
		fl->sl = 1;
	}
	else if (str[i] == 'h')
	{
		i++;
		if (str[i] == 'h')
		{
			fl->shh = 1;
		}
		fl->sh = 1;
	}
	i = fl->lastpos;
	return (0);
}

int		ft_lorllcheck(char *str, t_fl *fl)
{
	if (str[fl->lastpos] == 'L')
	{
		fl->l = 80;
		fl->e = 16383;
		fl->m = 63;
		fl->start = 16;
		return (2);
	}
	else
	{
		if (str[fl->lastpos] != 'l')
			fl->itsf = 1;
		fl->l = 64;
		fl->e = 1023;
		fl->m = 52;
		fl->start = 12;
		return (1);
	}
}

int		ft_accuracy_str(char *str, t_fl *fl)
{
	int i;

	i = fl->lastpos;
	fl->accuracy = -1;
	if (str[i] == '.')
	{
		i++;
		fl->accuracy = 0;
		while (ft_isdigit((int)str[i]) == 1)
		{
			fl->accuracy = fl->accuracy * 10 + (str[i] - 48);
			i++;
		}
	}
	fl->lastpos = i;
	return (1);
}
