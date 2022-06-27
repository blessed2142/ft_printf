/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:17:31 by rphoebe           #+#    #+#             */
/*   Updated: 2021/02/05 08:27:09 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_string_n(char *s, t_list *ptr)
{
	int i;

	i = 0;
	if (!s)
		s = ("(null)");
	if (ptr->precision || ptr->dot)
	{
		while (ptr->precision > i && s[i] != '\0')
			ft_putchar(s[i++], ptr);
		return (0);
	}
	else
		ft_putstr(s);
	return (ft_strlen(s));
}

void	ft_string_plus(char *s, t_list *ptr)
{
	if (!ptr->zero)
	{
		if (ptr->precision || ptr->dot)
		{
			if (ptr->precision > ft_strlen(s))
				ft_putchar_space(ptr->width - ft_strlen(s), ptr);
			else
				ft_putchar_space(ptr->width - ptr->precision, ptr);
		}
		else
			ft_putchar_space(ptr->width - ft_strlen(s), ptr);
	}
	else
	{
		if (ptr->precision || ptr->dot)
		{
			if (ptr->precision > ft_strlen(s))
				ft_putchar_zero(ptr->width - ft_strlen(s), ptr);
			else
				ft_putchar_zero(ptr->width - ptr->precision, ptr);
		}
		else
			ft_putchar_zero(ptr->width - ft_strlen(s), ptr);
	}
	ptr->ret += ft_string_n(s, ptr);
}

void	ft_string_minus(char *s, t_list *ptr)
{
	ptr->ret += ft_string_n(s, ptr);
	if (ptr->precision || ptr->dot)
	{
		if (ptr->precision > ft_strlen(s))
			ft_putchar_space(ptr->width - ft_strlen(s), ptr);
		else
			ft_putchar_space(ptr->width - ptr->precision, ptr);
	}
	else
		ft_putchar_space(ptr->width - ft_strlen(s), ptr);
}

void	ft_star_check_s(va_list *ap, t_list *ptr)
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
	if (ptr->precision < 0)
	{
		ptr->precision = 0;
		ptr->dot = 0;
	}
}

void	ft_string(va_list *ap, t_list *ptr)
{
	char *s;

	ft_star_check_s(ap, ptr);
	s = va_arg(*ap, char *);
	if (ptr->minus)
		ft_string_minus(s, ptr);
	else
		ft_string_plus(s, ptr);
}
