/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octoconc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:06:26 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/05 19:06:26 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octoconc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:06:26 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/05 19:06:26 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "./libft/libft.h"

void			ft_pf_write_norm(t_pf *pf, t_fl *fl, int norm)
{
	if (norm == 1)
	{
		write(1, "0", 1);
		pf->value++;
		fl->width--;
	}
	if (norm == 2)
	{
		write(1, " ", 1);
		pf->value++;
	}
	if (norm == 3)
	{
		write(1, "0", 1);
		pf->value++;
	}
	if (norm == 4)
	{
		fl->nol == 1 && (fl->accuracy == -1 || fl->accuracy == 0) ?
		write(1, "0", 1) : write(1, " ", 1);
		pf->value++;
	}
}

void	ft_octo_display_left(char *str, t_fl *fl, t_pf *pf)
{
	int len;
	int num;

	len = ft_strlen(str);
	num = len;
	if (len == 1 && str[0] == '0' && fl->accuracy > 0)
	{
		if (fl->width == 0)
		{
			while (fl->accuracy > 0)
			{
				write(1, "0", 1);
				fl->accuracy--;
				pf->value++;
			}
		}
		while (fl->width)
		{
			pf->value += write(1, " ", 1);
			fl->width--;
		}
		return ;
	}
	if (fl->flaglattice == 1 && (str[0] != '0' && len != 1))
	{
		pf->value += write(1, "0", 1);
		len++;
	}
	while (len++ < fl->accuracy)
		pf->value += write(1, "0", 1);
	pf->value += num;
	write(1, str, num);
	while (fl->width-- >= len)
		pf->value += write(1, " ", 1);
}

void	ft_octonol(t_fl *fl, int len, t_pf *pf)
{
	if (fl->accuracy != -1)
	{
		while (fl->width-- > len)
		{
			if (fl->nol == 1 && fl->accuracy < 1)
				pf->value += write(1, "0", 1);
			else
				pf->value += write(1, " ", 1);
		}
	}
	else
	{
		if (fl->flagplus == 1)
			fl->width--;
		while (fl->width-- > len)
		{
			if (fl->nol == 1 && fl->accuracy < 1)
				pf->value += write(1, "0", 1);
			else
				pf->value += write(1, " ", 1);
		}
	}
}

void	ft_octo_display_right(char *str, t_fl *fl, t_pf *pf)
{
	int len;
	int num;

	len = ft_strlen(str);
	num = len;
	if ((len == 1 && str[0] == '0') && fl->accuracy >= 0)
	{
		if (fl->flaglattice == 1)
		{
			pf->value += write(1, "0", 1);
			fl->accuracy--;
		}
		if (fl->width == 0)
		{
			while (fl->accuracy > 0)
			{
				write(1, "0", 1);
				fl->accuracy--;
				pf->value++;
			}
		}
		while (fl->width)
		{
			pf->value += write(1, " ", 1);
			fl->width--;
		}
		return ;
	}
	if (fl->flaglattice == 1 && (len != 1 && str[0] != '0'))
		len++;
	ft_octonol(fl, len, pf);
	while (len++ < fl->accuracy)
		pf->value += write(1, "0", 1);
	if (fl->flaglattice == 1 && (len != 1 && str[0] != '0'))
		pf->value += write(1, "0", 1);
	pf->value += num;
	write(1, str, num);
}

uintmax_t		ft_octo_ditsribution(va_list list, char c, t_fl *fl, t_pf *pf)
{
	intmax_t	num;
	char		*str;
	int			i;

	i = 0;
	if (c == 'O')
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
	str = ft_itoa_base(num, 8);
	if (fl->flagminus == 1)
		ft_octo_display_left(str, fl, pf);
	else
		ft_octo_display_right(str, fl, pf);
	if (num != 0)
		free(str);
	return (0);
}

int				ft_conco(char *s, va_list list, char c, t_pf *pf)
{
	uintmax_t	x;
	t_fl		*fl1;

	fl1 = (t_fl*)malloc(sizeof(t_fl) * 1);
	fl1->sl = 0;
	fl1->sll = 0;
	fl1->sh = 0;
	fl1->shh = 0;
	ft_flags(s, fl1);
	ft_width(s, fl1);
	ft_accuracy_str(s, fl1);
	ft_lllhhh(s, fl1);
	x = ft_octo_ditsribution(list, c, fl1, pf);
	free(fl1);
	return (0);
}
