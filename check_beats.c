/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_beats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:57:56 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/13 18:57:56 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

int		ft_check_exp(char *str, t_fl *fl)
{
	char	*s;
	int		i;
	int		last;
	int		start;

	if (fl->l == 80)
	{
		last = 15;
		start = 1;
	}
	else if (fl->l == 64)
	{
		last = 11;
		start = 1;
	}
	else
	{
		last = 8;
		start = 1;
	}
	s = ft_strsub(str, start, last);
	i = ft_atoi_base(s, 2);
	return (i);
}

char	*ft_checkbindouble(t_fl *fl1, double x)
{
	unsigned char	*p;
	int				i;
	int				j;
	char			*str;
	int				d;

	d = 0;
	str = (char*)malloc(sizeof(char) * (fl1->l + 1));
	str[fl1->l] = '\0';
	p = ((unsigned char*)&x);
	j = fl1->l - 1;
	while (d < fl1->l / 8)
	{
		i = 0;
		while (i < 8)
		{
			if (p[d] & 1 << i++)
				str[j] = '1';
			else
				str[j] = '0';
			j--;
		}
		d++;
	}
	return (str);
}

char	*ft_checkbinfloat(t_fl *fl1, float x)
{
	unsigned char	*p;
	int				i;
	int				j;
	char			*str;
	int				d;

	d = 0;
	str = (char*)malloc(sizeof(char) * (fl1->l + 1));
	str[fl1->l] = '\0';
	p = ((unsigned char*)&x);
	j = fl1->l - 1;
	while (d < fl1->l / 8)
	{
		i = 0;
		while (i < 8)
		{
			if (p[d] & 1 << i++)
				str[j] = '1';
			else
				str[j] = '0';
			j--;
		}
		d++;
	}
	return (str);
}

char	*ft_checkbinlongdouble(t_fl *fl1, long double x)
{
	unsigned char	*p;
	int				i;
	int				j;
	char			*str;
	int				d;

	d = 0;
	str = (char*)malloc(sizeof(char) * (fl1->l + 1));
	str[fl1->l] = '\0';
	p = ((unsigned char*)&x);
	j = fl1->l - 1;
	while (d < fl1->l / 8)
	{
		i = 0;
		while (i < 8)
		{
			if (p[d] & 1 << i++)
				str[j] = '1';
			else
				str[j] = '0';
			j--;
		}
		d++;
	}
	return (str);
}

int		*ft_check_mantissa(char *str, t_fl *fl)
{
	int i;
	int *mass;
	int j;

	i = fl->start;
	mass = (int*)malloc(sizeof(int) * (fl->m) + 1);
	if (fl->l == 64 || fl->l == 32)
	{
		mass[0] = 1;
		j = 1;
	}
	else
	{
		j = 0;
	}
	while (i <= fl->l)
	{
		if (str[i] == '1')
			mass[j] = 1;
		else
			mass[j] = 0;
		j++;
		i++;
	}
	return (mass);
}
