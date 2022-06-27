/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:01:39 by rphoebe           #+#    #+#             */
/*   Updated: 2021/02/05 08:05:07 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_star_check(va_list *ap, t_list *ptr)
{
	if (ptr->w_star == 1)
		ptr->width = va_arg(*ap, int);
	if (ptr->width < 0)
	{
		ptr->width *= -1;
		ptr->minus = 1;
		ptr->zero = 0;
	}
	if (ptr->p_star)
		ptr->precision = va_arg(*ap, int);
	if (ptr->zero && ptr->precision < 0)
	{
		ptr->dot = 0;
		ptr->precision = 0;
	}
}

void	ft_int_plus(long int n, t_list *ptr, int len)
{
	if (n == 0 && !ptr->precision && ptr->dot)
	{
		ft_putchar_space(ptr->width - len + 1, ptr);
		return ;
	}
	if (!ptr->precision || ptr->precision <= len)
		ft_putchar_space(ptr->width - len, ptr);
	else
		ft_putchar_space(ptr->width - len - (ptr->precision - len), ptr);
	ft_putchar_zero(ptr->precision - len, ptr);
	ptr->ret = ptr->ret + ft_intlen(n);
	if (n == 0 && !ptr->precision && ptr->dot)
		return ;
	ft_putnbr(n);
}

void	ft_int_minus(long int n, t_list *ptr, int len)
{
	if (n == 0 && !ptr->precision && ptr->dot)
	{
		ft_putchar_space(ptr->width - len + 1, ptr);
		return ;
	}
	ft_putchar_zero(ptr->precision - len, ptr);
	ptr->ret = ptr->ret + ft_intlen(n);
	ft_putnbr(n);
	if (!ptr->precision || ptr->precision <= len)
		ft_putchar_space(ptr->width - len, ptr);
	else
		ft_putchar_space(ptr->width - len - (ptr->precision - len), ptr);
}

void	ft_int_zero(long int n, t_list *ptr, int len)
{
	if (n == 0 && !ptr->precision && ptr->dot)
	{
		ft_putchar_space(ptr->width - ft_intlen(n) + 1, ptr);
		return ;
	}
	if (ptr->precision || ptr->dot)
	{
		if (ptr->precision >= len)
			ft_putchar_space(ptr->width - ptr->precision, ptr);
		else
			ft_putchar_space(ptr->width - len, ptr);
	}
	if (!ptr->dot)
		ft_putchar_zero(ptr->width - len, ptr);
	else
		ft_putchar_zero(ptr->precision - len, ptr);
	ptr->ret = ptr->ret + ft_intlen(n);
	ft_putnbr(n);
}

void	ft_integers(va_list *ap, t_list *ptr)
{
	int n;

	ft_star_check(ap, ptr);
	n = va_arg(*ap, int);
	if ((n < 0 && ptr->precision) || (n < 0 && ptr->width && ptr->zero))
	{
		ft_integers_negative(n, ptr, ft_intlen(n));
		return ;
	}
	if (ptr->minus)
		ft_int_minus(n, ptr, ft_intlen(n));
	if (!ptr->minus)
	{
		if (ptr->zero)
			ft_int_zero(n, ptr, ft_intlen(n));
		else
			ft_int_plus(n, ptr, ft_intlen(n));
	}
}
