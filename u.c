/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:09:52 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/05 19:09:52 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

uintmax_t		ft_uint_ditsribution(va_list list, char c, t_fl *fl, t_pf *pf)
{
	intmax_t num;
	char *str;
	int i;

	i = 0;
	if (c == 'U')
		num = (unsigned long)(va_arg(list, unsigned long int));
	else if (fl->shh == 1)
		num = (unsigned char)(va_arg(list, unsigned int));
	else if (fl->sh == 1)
		num = (unsigned short)(va_arg(list, unsigned int));
	else if (fl->sll == 1)
		num = (unsigned long long)(va_arg(list, unsigned long long int));
	else if (fl->sl == 1)
		num = (unsigned long)(va_arg(list, unsigned long int));
	else
	num = (unsigned int)(va_arg(list, unsigned int));
	num = (uintmax_t)num;
	str = ft_utoa(num);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		pf->value++;
		i++;
	}
	return (0);
}

int 	ft_concu(char *s, va_list list, char c, t_pf *pf)
{
	uintmax_t x;
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
	x = ft_uint_ditsribution(list, c, fl1, pf);
	return (0);
}
