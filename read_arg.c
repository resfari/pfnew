/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 20:38:44 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/06/19 20:38:44 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

int		ft_concfloat(va_list list, t_fl *fl1)
{
	float x;

	x = va_arg(list, double);
	ft_conclusionfloat(fl1, x);
	return (0);
}

int		ft_conclongdouble(va_list list, t_fl *fl1)
{
	long double x;

	x = va_arg(list, long double);
	ft_conclusionlongdouble(fl1, x);
	return (0);
}

int		ft_concdouble(char *s, va_list list)
{
	double	x;
	t_fl	*fl1;

	fl1 = (t_fl*)malloc(sizeof(t_fl) * 1);
	ft_flags(s, fl1);
	ft_width(s, fl1);
	ft_accuracy(s, fl1);
	ft_lorllcheck(s, fl1);
	if (fl1->l == 80)
	{
		ft_conclongdouble(list, fl1);
		ft_free_fl1(fl1);
	}
	else if (fl1->l == 32)
	{
		ft_concfloat(list, fl1);
		ft_free_fl1(fl1);
	}
	else
	{
		x = va_arg(list, double);
		ft_conclusiondouble(fl1, x);
		ft_free_fl1(fl1);
	}
	return (0);
}

int		ft_treatment(char *str, va_list list, t_pf *pf)
{
	int len;

	len = ft_strlen(str);
	if (str[len - 1] == 'c')
		ft_concchar(str, list, pf);
	if (str[len - 1] == 'd' || str[len - 1] == 'i' || str[len - 1] == 'D')
		ft_concint(str, list, str[len - 1], pf);
	if (str[len - 1] == 's')
		ft_concstr(str, list, pf);
	if (str[len - 1] == 'o' || str[len - 1] == 'O')
		ft_conco(str, list, str[len - 1], pf);
	if (str[len - 1] == 'x' || str[len - 1] == 'X')
		ft_concx(str, list, str[len - 1], pf);
	if (str[len - 1] == 'u' || str[len - 1] == 'U')
		ft_concu(str, list, str[len - 1], pf);
	if (str[len - 1] == 'f')
		ft_concdouble(str, list);
	if (str[len - 1] == 'p')
		ft_concpointer(str, list, pf);
	if (str[len - 1] == '%')
		ft_concproc(str, pf);
	return (0);
}

int		ft_read_arg(va_list list, t_pf *pf)
{
	int i;
	int count;
	int len;

	len = ft_strlen(pf->str);
	i = 0;
	count = 0;
	while (pf->str[i] != '\0')
	{
		if (pf->str[i] == '%')
		{
			ft_treatment(pf->procent[count], list, pf);
			i = ft_strlen(pf->procent[count]) + i;
			if (pf->procent[count])
				free(pf->procent[count]);
			count++;
		}
		else if (i < len)
		{
			write(1, &pf->str[i], 1);
			pf->value++;
		}
		i++;
	}
	return (0);
}
