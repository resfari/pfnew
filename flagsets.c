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
	int  i;

	i = fl->lastpos;
	if (str[i] == 'l')
	{
		fl->l = 64;
		fl->lastpos = i;
		fl->e = 1023;
		fl->m = 52;
		fl->start = 12;
		return (1);
	}
	else if (str[i] == 'L')
	{
			fl->l = 80;
			fl->lastpos = i;
			fl->e = 16383;
			fl->m = 63;
			fl->start = 16;
			return (2);
	}
	else
	{
		fl->e = 127;
		fl->l = 32;
		fl->m = 23;
		fl->start = 9;
		return (0);
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

int		ft_accuracy(char *str, t_fl *fl)
{
	int i;

	i = fl->lastpos;
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit((int)str[i]) == 1)
		{
			fl->accuracy = fl->accuracy * 10 + (str[i] - 48);
			i++;
		}
	}
	else
		fl->accuracy = 6;
	if (fl->accuracy < 50)
		fl->masssize = 50;
	else
		fl->masssize = fl->accuracy + 1;
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
	if (c == ' ')
	{
		fl->flagspace = 1;
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
	return (c);
}

int		ft_flags(char *str, t_fl *fl)
{
	int i;
	const char *flags;
	char c;

	i = 0;
	ft_flagsinit(fl);
	flags = "-+ #0";
	if (ft_strchr(flags, str[i]) != NULL)
	{
		c = ft_flagdefenition(fl, str[i]);
		while (str[i] == c)
			i++;
		if (ft_strchr(flags, str[i]) != NULL)
		{
			c = ft_flagdefenition(fl, str[i]);
			while (str[i] == c)
				i++;
			if (ft_strchr(flags, str[i]) != NULL)
			{
				c = ft_flagdefenition(fl, str[i]);
				while (str[i] == c)
					i++;
				if (ft_strchr(flags, str[i]) != NULL)
				{
					c = ft_flagdefenition(fl, str[i]);
					while (str[i] == c)
						i++;
					if (ft_strchr(flags, str[i]) != NULL)
					{
						c = ft_flagdefenition(fl, str[i]);
						while (str[i] == c)
							i++;
					}
				}
			}
		}
		fl->lastpos = i;
		return (1);
	}
	return (0);
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
}