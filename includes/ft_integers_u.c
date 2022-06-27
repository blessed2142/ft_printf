/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integers_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:00:30 by rphoebe           #+#    #+#             */
/*   Updated: 2021/02/05 08:01:29 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_integers_u(va_list *ap, t_list *ptr)
{
	unsigned int n;

	ft_star_check(ap, ptr);
	n = va_arg(*ap, unsigned int);
	if ((n < 0 && ptr->precision) || (n < 0 && ptr->width && ptr->zero))
	{
		ft_integers_negative(n, ptr, ft_intlen(n));
		return ;
	}
	if (ptr->minus)
		ft_int_minus(n, ptr, ft_intlen(n));
	if (!ptr->minus)
	{
		if (!ptr->precision && ptr->zero)
			ft_int_zero(n, ptr, ft_intlen(n));
		else
			ft_int_plus(n, ptr, ft_intlen(n));
	}
}
