/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:44:30 by rphoebe           #+#    #+#             */
/*   Updated: 2021/02/05 08:17:03 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_list *ptr)
{
	write(1, &c, 1);
	ptr->ret++;
}

void	ft_putchar_nbr(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_space(int h, t_list *ptr)
{
	char c;

	c = ' ';
	if (h > 0)
	{
		while (h)
		{
			write(1, &c, 1);
			h--;
			ptr->ret++;
		}
	}
}

void	ft_putchar_zero(int h, t_list *ptr)
{
	char c;

	c = '0';
	if (h > 0)
	{
		while (h)
		{
			write(1, &c, 1);
			h--;
			ptr->ret++;
		}
	}
}
