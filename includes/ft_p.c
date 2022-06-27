/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:06:11 by rphoebe           #+#    #+#             */
/*   Updated: 2021/02/05 08:08:35 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_dec_hex_p(size_t n, t_list *ptr)
{
	int				array[1024];
	long long int	q;
	int				i;
	long long int	a;

	(void)ptr;
	q = -1;
	i = 0;
	a = -1;
	ft_array_clear(array);
	while (q != 0)
	{
		q = n / 16;
		a = n - (16 * q);
		array[i] = a;
		n = q;
		i++;
	}
	return (ft_array_to_str(array, i, ptr));
}

void	ft_p(va_list *ap, t_list *ptr)
{
	size_t	n;
	char	*str;

	ft_star_check(ap, ptr);
	n = va_arg(*ap, size_t);
	str = ft_dec_hex_p(n, ptr);
	if (ptr->minus)
		ft_x_minus(str, ptr, ft_strlen(str));
	if (!ptr->minus)
	{
		if (!ptr->precision && ptr->zero)
			ft_x_zero(str, ptr, ft_strlen(str));
		else
			ft_x_plus(str, ptr, ft_strlen(str));
	}
}
