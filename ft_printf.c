/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 07:50:01 by rphoebe           #+#    #+#             */
/*   Updated: 2021/02/05 07:50:11 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list ap;
	int		i;
	t_list	st;

	i = 0;
	ft_struzero(&st);
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			i = ft_parcer(fmt, &st, i);
			ft_chosen_one(&ap, &st);
		}
		else if (fmt[i] != '\0')
			ft_putchar(fmt[i++], &st);
	}
	va_end(ap);
	return (st.ret);
}
