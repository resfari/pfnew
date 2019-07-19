/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strconc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:19:10 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/06/21 13:19:10 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "./libft/libft.h"

int		ft_str_no_accuracy_no_minus(t_fl *fl, char *arg, t_pf *pf, int len)
{
	int i;

	i = 0;
	if (fl->width > len)
	{
		while (fl->width > len)
		{
			fl->nol == 1 ? write(1, "0", 1) : write(1, " ", 1);
			pf->value++;
			fl->width--;
		}
	}
	while (arg[i] != '\0')
	{
		write(1, &arg[i], 1);
		pf->value++;
		i++;
		fl->accuracy--;
		fl->width--;
	}
	return (0);
}

int		ft_str_check_width(t_fl *fl, char *arg, t_pf *pf)
{
	int i;
	int len;

	i = 0;
	len = (int)ft_strlen(arg);
	if (fl->accuracy < len && fl->accuracy != -1)
	{
		if (fl->width > fl->accuracy)
		{
			while (fl->width-- > fl->accuracy)
			{
				write(1, " ", 1);
				pf->value++;
			}
		}
		while (fl->accuracy-- > 0 && arg[i] != '\0')
		{
			write(1, &arg[i], 1);
			i++;
			pf->value++;
		}
	}
	else
		ft_str_no_accuracy_no_minus(fl, arg, pf, len);
	return (0);
}

int		ft_str_no_accuracy(t_fl *fl, char *arg, t_pf *pf)
{
	int i;

	i = 0;
	while (arg[i] != '\0')
	{
		write(1, &arg[i], 1);
		pf->value++;
		i++;
		fl->accuracy--;
		fl->width--;
	}
	return (0);
}

int		ft_conclusionstr(t_fl *fl, char *arg, t_pf *pf)
{
	int i;

	i = 0;
	if (fl->flagminus == 1)
	{
		if (fl->accuracy >= 0)
		{
			while (fl->accuracy-- > 0 && arg[i] != '\0')
			{
				write(1, &arg[i], 1);
				pf->value++;
				i++;
				fl->width--;
			}
		}
		else
			ft_str_no_accuracy(fl, arg, pf);
		while (fl->width-- > 0)
			ft_hex_norm(fl, pf, 1);
	}
	else
		ft_str_check_width(fl, arg, pf);
	return (0);
}

int		ft_concstr(char *s, va_list list, t_pf *pf)
{
	char *str;
	t_fl *fl;

	fl = (t_fl*)malloc(sizeof(t_fl) * 1);
	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	ft_flags(s, fl);
	ft_width(s, fl);
	ft_accuracy_str(s, fl);
	ft_conclusionstr(fl, str, pf);
	s = NULL;
	free(fl);
	return (0);
}
