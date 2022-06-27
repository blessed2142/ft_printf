/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struzero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:21:28 by rphoebe           #+#    #+#             */
/*   Updated: 2021/02/05 08:21:29 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_struzero(t_list *ptr)
{
	ptr->minus = 0;
	ptr->dot = 0;
	ptr->w_star = 0;
	ptr->p_star = 0;
	ptr->precision = 0;
	ptr->width = 0;
	ptr->zero = 0;
	ptr->intlen = 0;
	ptr->ret = 0;
}
