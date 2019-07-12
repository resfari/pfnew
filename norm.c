/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 21:33:43 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/12 21:33:43 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

void			ft_octo_norm(char *str, t_pf *pf, int len)
{
	int i;

	i = 0;
	while (len != 0 && str[i] != '\0')
	{
		write(1, &str[i], 1);
		pf->value++;
		i++;
	}
}

void	ft_free_fl1(t_fl *fl)
{
	if (fl->final)
		free(fl->final);
	free(fl);
}
