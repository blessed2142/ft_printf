/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:00:00 by rphoebe           #+#    #+#             */
/*   Updated: 2020/11/17 14:37:42 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long int n)
{
	long int	nn;
	int			i;
	char		c;

	nn = n;
	i = 0;
	if (nn < 0)
	{
		ft_putchar_nbr('-');
		nn = -nn;
	}
	if (nn > 9)
	{
		ft_putnbr(nn / 10);
		ft_putnbr(nn % 10);
	}
	if (nn < 10)
	{
		c = nn + '0';
		ft_putchar_nbr(c);
	}
}
