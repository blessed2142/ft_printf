/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 07:50:38 by rphoebe           #+#    #+#             */
/*   Updated: 2021/02/05 08:26:06 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_plus(char c, t_list *ptr)
{
	ft_putchar_space(ptr->width - 1, ptr);
	ft_putchar(c, ptr);
}

void	ft_char_minus(char c, t_list *ptr)
{
	ft_putchar(c, ptr);
	ft_putchar_space(ptr->width - 1, ptr);
}

void	ft_char(va_list *ap, t_list *ptr)
{
	char c;

	ft_star_check(ap, ptr);
	c = va_arg(*ap, int);
	if (ptr->minus)
		ft_char_minus(c, ptr);
	else
		ft_char_plus(c, ptr);
}
