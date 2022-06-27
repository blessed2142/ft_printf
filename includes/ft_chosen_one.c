/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chosen_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 07:52:35 by rphoebe           #+#    #+#             */
/*   Updated: 2021/02/05 07:53:25 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_chosen_one(va_list *ap, t_list *ptr)
{
	if (ptr->spec == 'd' || ptr->spec == 'i')
		ft_integers(ap, ptr);
	if (ptr->spec == 'u')
		ft_integers_u(ap, ptr);
	if (ptr->spec == 'c')
		ft_char(ap, ptr);
	if (ptr->spec == 'x' || ptr->spec == 'X')
		ft_x(ap, ptr);
	if (ptr->spec == 's')
		ft_string(ap, ptr);
	if (ptr->spec == 'p')
		ft_p(ap, ptr);
	if (ptr->spec == '%')
		ft_percent(ap, ptr);
}
