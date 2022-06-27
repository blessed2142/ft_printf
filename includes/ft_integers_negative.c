/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integers_negative.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 07:58:11 by rphoebe           #+#    #+#             */
/*   Updated: 2021/02/05 08:00:22 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_plus_n(long int n, t_list *ptr, int len)
{
	if (!ptr->precision || ptr->precision <= len - 1)
		ft_putchar_space(ptr->width - len, ptr);
	else
		ft_putchar_space(ptr->width - len - (ptr->precision - len) - 1, ptr);
	ft_putchar('-', ptr);
	ft_putchar_zero(ptr->precision - len + 1, ptr);
	ptr->ret = ptr->ret + ft_intlen(n);
	ft_putnbr(n);
}

void	ft_int_minus_n(long int n, t_list *ptr, int len)
{
	ft_putchar('-', ptr);
	ft_putchar_zero(ptr->precision - len + 1, ptr);
	ptr->ret = ptr->ret + ft_intlen(n);
	ft_putnbr(n);
	if (!ptr->precision || ptr->precision <= len - 1)
		ft_putchar_space(ptr->width - len, ptr);
	else
		ft_putchar_space(ptr->width - len - (ptr->precision - len) - 1, ptr);
}

void	ft_int_zero_n(long int n, t_list *ptr, int len)
{
	if (ptr->precision || ptr->dot)
	{
		if (ptr->precision >= len)
			ft_putchar_space(ptr->width - ptr->precision - 1, ptr);
		else
			ft_putchar_space(ptr->width - len, ptr);
	}
	ft_putchar('-', ptr);
	if (!ptr->dot)
		ft_putchar_zero(ptr->width - len, ptr);
	else
		ft_putchar_zero(ptr->precision - (len - 1), ptr);
	ptr->ret = ptr->ret + ft_intlen(n);
	ft_putnbr(n);
}

void	ft_integers_negative(int n, t_list *ptr, int len)
{
	long int nn;

	nn = n;
	nn = -nn;
	if (ptr->minus)
		ft_int_minus_n(nn, ptr, len);
	if (!ptr->minus)
	{
		if (ptr->zero)
			ft_int_zero_n(nn, ptr, len);
		else
			ft_int_plus_n(nn, ptr, len);
	}
}
