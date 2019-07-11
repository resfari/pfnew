/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:00:03 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/06/19 17:00:03 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

int		ft_check_str(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			count++;
		i++;
	}
	return (count);
}

char	*ft_check_for_flags(char *str, t_pf *pf)
{
	const char *flags;
	int j;
	int k;
	char *newstr;

	pf->i++;
	j = pf->i;
	k = 0;
	flags = "dDuUioxXcspf%";
	while (str[pf->i] != '\0')
	{
		if (ft_strchr(flags, (int)str[pf->i]))
		{
			if (!(newstr = (char*)malloc(sizeof(char) * (pf->i - j + 1))))
				return (NULL);
			newstr[pf->i - j + 1] = '\0';
			while (j <= pf->i)
			{
				newstr[k] = str[j];
				j++;
				k++;
			}
			return (newstr);
		}
		pf->i++;
	}
	return (NULL);
}

int		ft_read_format(const char *format, t_pf *pf)
{
	int len;
	int x;

	x = 0;
	pf->str = ft_strnew(ft_strlen(format));
	pf->str = ft_strcpy(pf->str, format);
	len = ft_strlen(pf->str);
	if ((pf->count = ft_check_str(pf->str)) == -1)
		return (0);
	if (!(pf->procent = (char**)malloc(sizeof(char*) * (pf->count + 1))))
		return (0);
	pf->procent[pf->count] = NULL;
	while (pf->str[pf->i] != '\0')
	{
		if (pf->str[pf->i] == '%')
		{
			if ((pf->procent[pf->j] = ft_check_for_flags(pf->str, pf)) == NULL)
				return (0);
			pf->j++;
		}
		pf->i++;
	}
	return (1);
}

void		ft_fill_pf(t_pf *pf)
{
	pf->i = 0;
	pf->j = 0;
	pf->value = 0;
}

int		ft_printf(const char *restrict format, ...)
{
	t_pf	*pf;
	va_list list;
	int x;

	va_start(list, format);
	pf = (t_pf*)malloc(sizeof(t_pf) * 1);
	ft_fill_pf(pf);
	x = ft_read_format(format, pf);
	if (x == 1)
		ft_read_arg(list, pf);
	va_end(list);
	return (pf->value);
}

int main()
{
	long double l;
	double d;
	float f;
	char c;
	char *s;
	int z;
	long int longint;
	short int si;
	unsigned char uch;
	unsigned int ul;

	uch = 'a';
	ul = -151;
	longint = -2147483649;
	s = "123456";
	c = 'a';
	f = 9223372036854775807999.0;
	d = 123456789.0;
	l = 22222.999999999999999;
	z = -42;
	si = -32765;
	signed char a;
	a = 'b';
//	lli = -9223372036854775808;
//	printf("\n%d\n", ft_printf("%.0p%.p", &s, &s));
	printf("%2.0p", &z);
//	printf("\n%d\n", printf("%.0p, %.p", 0, &s));
//	printf("\n%d\n", printf("%u", ul));
	return (0);
}