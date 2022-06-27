/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:12:10 by rphoebe           #+#    #+#             */
/*   Updated: 2021/02/05 08:26:19 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_percent_plus(t_list *ptr)
{
	if (ptr->zero)
		ft_putchar_zero(ptr->width - 1, ptr);
	else
		ft_putchar_space(ptr->width - 1, ptr);
	ft_putchar('%', ptr);
}

void	ft_percent_minus(t_list *ptr)
{
	ft_putchar('%', ptr);
	if (ptr->zero)
		ft_putchar_zero(ptr->width - 1, ptr);
	else
		ft_putchar_space(ptr->width - 1, ptr);
}

void	ft_percent(va_list *ap, t_list *ptr)
{
	ft_star_check(ap, ptr);
	if (!ptr->width)
	{
		ft_putchar('%', ptr);
		return ;
	}
	if (!ptr->minus)
		ft_percent_plus(ptr);
	else
		ft_percent_minus(ptr);
}
