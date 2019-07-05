/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:10:49 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/05 19:10:49 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

intmax_t		ft_int_ditsribution(va_list list, char c, t_fl *fl, t_pf *pf)
{
	intmax_t num;
	char *str;
	int i;

	i = 0;
	if (c == 'D')
		num = (long)(va_arg(list, long int));
	else if (fl->shh == 1)
		num = (signed char)(va_arg(list, int));
	else if (fl->sh == 1)
		num = (short)(va_arg(list, int));
	else if (fl->sll == 1)
		num = (long long)(va_arg(list, long long int));
	else if (fl->sl == 1)
		num = (long)(va_arg(list, long int));
	else
	num = (int)(va_arg(list, int));
	num = (intmax_t)num;
	str = ft_ltoa(num);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		pf->value++;
		i++;
	}
	return (0);
}

int 	ft_concint(char *s, va_list list, char c, t_pf *pf)
{
	intmax_t x;
	t_fl *fl1;

	fl1 = (t_fl*)malloc(sizeof(t_fl) * 1);
	fl1->sl = 0;
	fl1->sll = 0;
	fl1->sh = 0;
	fl1->shh = 0;
	ft_flags(s, fl1);
	ft_width(s, fl1);
	ft_accuracy(s, fl1);
	ft_lllhhh(s, fl1);
	x = ft_int_ditsribution(list, c, fl1, pf);
	return (0);
}
