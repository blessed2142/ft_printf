/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:21:41 by rphoebe           #+#    #+#             */
/*   Updated: 2021/02/05 08:24:24 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_x_plus(char *str, t_list *ptr, int len)
{
	if (ptr->spec == 'p')
	{
		len += 2;
		ptr->ret += 2;
	}
	if (str[0] == '0' && !ptr->precision && ptr->dot)
	{
		ft_putchar_space(ptr->width - len + 1, ptr);
		if (ptr->spec == 'p')
			ft_putstr("0x");
		return ;
	}
	if (!ptr->precision || ptr->precision <= (int)len)
		ft_putchar_space(ptr->width - len, ptr);
	else
		ft_putchar_space(ptr->width - len - (ptr->precision - len), ptr);
	if (ptr->spec == 'p')
		ft_putstr("0x");
	if (ptr->spec == 'x' || ptr->spec == 'X')
		ft_putchar_zero(ptr->precision - len, ptr);
	else
		ft_putchar_zero(ptr->precision - len + 2, ptr);
	ptr->ret = ptr->ret + ft_strlen(str);
	ft_putstr(str);
}

void	ft_x_minus(char *str, t_list *ptr, int len)
{
	if (ptr->spec == 'p')
	{
		len += 2;
		ptr->ret += 2;
	}
	if (str[0] == '0' && !ptr->precision && ptr->dot)
	{
		ft_putchar_space(ptr->width - len + 1, ptr);
		return ;
	}
	ft_putchar_zero(ptr->precision - len, ptr);
	if (ptr->spec == 'p')
		ft_putstr("0x");
	ptr->ret = ptr->ret + ft_strlen(str);
	ft_putstr(str);
	if (!ptr->precision || ptr->precision <= len)
		ft_putchar_space(ptr->width - len, ptr);
	else
		ft_putchar_space(ptr->width - len - (ptr->precision - len), ptr);
}

void	ft_x_zero(char *str, t_list *ptr, int len)
{
	if (ptr->spec == 'p')
	{
		len += 2;
		ptr->ret += 2;
	}
	ft_putchar_zero(ptr->width - len, ptr);
	ptr->ret = ptr->ret + ft_strlen(str);
	ft_putstr(str);
}

void	ft_x(va_list *ap, t_list *ptr)
{
	unsigned	n;
	char		*str;

	ft_star_check(ap, ptr);
	n = va_arg(*ap, unsigned int);
	str = ft_dec_hex(n, ptr);
	if (ptr->minus)
		ft_x_minus(str, ptr, ft_strlen(str));
	if (!ptr->minus)
	{
		if (!ptr->dot && ptr->zero)
			ft_x_zero(str, ptr, ft_strlen(str));
		else
			ft_x_plus(str, ptr, ft_strlen(str));
	}
}
