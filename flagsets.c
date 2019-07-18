/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagsetc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:20:53 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/06/21 13:20:53 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

int		ft_check_max(char *str, int count, t_fl *fl)
{
	int i;
	const char *MAX_I;
	int num;
	int j;

	j = 0;
	num = 0;
	MAX_I = "2147483649";
	i = count;
	if (str[i]== '.')
		i++;
	while (MAX_I[j] != '\0' && str[i] != '\0')
	{
		if (str[i] == MAX_I[j])
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

int		ft_accuracy(char *str, t_fl *fl)
{
	int i;
	int count;

	i = fl->lastpos;
	count = 0;
	if (ft_check_max(str, fl->lastpos, fl) == 1)
	{
		fl->masssize = 5000;
		return (1);
	}
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit((int)str[i]) == 1)
		{
			fl->accuracy = fl->accuracy * 10 + (str[i] - 48);
			count++;
			i++;
		}
	}
	else
		fl->accuracy = 6;
	if (i > fl->lastpos && count == 0)
		fl->accuracy = -1;
	fl->masssize = 5000;
	fl->lastpos = i;
	return (1);
}

int		ft_width(char *str, t_fl *fl)
{
	int i;

	i = fl->lastpos;
	while (ft_isdigit((int)str[i]) == 1)
	{
		fl->width = fl->width * 10 + (str[i] - 48);
		i++;
	}
	fl->lastpos = i;
	return (1);
}

char	ft_flagdefenition(t_fl *fl, char c)
{
	if (c == '+')
	{
		fl->flagplus = 1;
		return (c);
	}
	if (c == '-')
	{
		fl->flagminus = 1;
		return (c);
	}
	if (c == '#')
	{
		fl->flaglattice = 1;
		return (c);
	}
	if (c == '0')
	{
		fl->nol = 1;
		return (c);
	}
	else
	{
		fl->flagspace = 1;
		return (c);
	}
}

int		ft_flags(char *str, t_fl *fl)
{
	int			i;
	const char	*flags;
	char		c;

	i = 0;
	ft_flagsinit(fl);
	flags = "-+ #0";
	while (ft_strchr(flags, str[i]) != NULL)
	{
		c = ft_flagdefenition(fl, str[i]);
		while (str[i] == c)
			i++;
	}
	fl->lastpos = i;
	return (1);
}

void	ft_flagsinit(t_fl *fl)
{
	fl->flaglattice = 0;
	fl->flagminus = 0;
	fl->flagplus = 0;
	fl->flagspace = 0;
	fl->accuracy = 0;
	fl->width = 0;
	fl->nol = 0;
	fl->lastpos = 0;
	fl->puted = 0;
	fl->perehod_in_acc = 0;
	fl->edinica = 0;
	fl->masssize = 0;
}
