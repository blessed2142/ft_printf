/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:08:45 by rphoebe           #+#    #+#             */
/*   Updated: 2021/02/05 09:07:55 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_preparcer(t_list *ptr)
{
	ptr->minus = 0;
	ptr->dot = 0;
	ptr->w_star = 0;
	ptr->p_star = 0;
	ptr->precision = 0;
	ptr->width = 0;
	ptr->zero = 0;
	ptr->intlen = 0;
}

int		ft_skip(const char *fmt, int i)
{
	while (fmt[i] >= '0' && fmt[i] <= '9')
		i++;
	return (i);
}

int		ft_flags(const char *fmt, t_list *ptr, int i)
{
	while (fmt[i] == '-' || fmt[i] == '0')
	{
		while (fmt[i] == '-')
		{
			ptr->minus = 1;
			ptr->zero = 0;
			i++;
		}
		while (fmt[i] == '0')
		{
			if (ptr->minus != 1)
				ptr->zero = 1;
			i++;
		}
	}
	return (i);
}

int		ft_stars(const char *fmt, t_list *ptr, int i)
{
	int j;

	j = i;
	while (fmt[j] != '\0' && !((ft_isalpha(fmt[j]) || fmt[j] == '%')))
	{
		if (fmt[j] == '*' && ptr->w_star == 0 && ptr->dot == 0)
			ptr->w_star = 1;
		if (fmt[j] == '.' && ptr->dot == 0)
			ptr->dot = 1;
		if (fmt[j] == '*' && ptr->dot == 1)
			ptr->p_star = 1;
		j++;
	}
	if (!ptr->w_star && !ptr->p_star)
		return (i);
	if (ptr->w_star && !ptr->p_star && ptr->dot)
	{
		while (fmt[j] != '.')
			j--;
	}
	return (j);
}

int		ft_parcer(const char *fmt, t_list *ptr, int i)
{
	ft_preparcer(ptr);
	i = ft_flags(fmt, ptr, i);
	i = ft_stars(fmt, ptr, i);
	while (fmt[i] != '\0' && !((ft_isalpha(fmt[i]) || fmt[i] == '%')))
	{
		if (!(ft_strchr("-0.123456789csdiupxX", fmt[i])))
			return (-1);
		if ((fmt[i] >= '0' && fmt[i] <= '9') && ptr->w_star == 0)
		{
			ptr->width = ft_atoi(fmt + i);
			i = ft_skip(fmt, i);
		}
		if (fmt[i] == '.')
		{
			ptr->dot = 1;
			i++;
		}
		if (fmt[i] >= '0' && fmt[i] <= '9' && ptr->p_star == 0)
		{
			ptr->precision = ft_atoi(fmt + i);
			i = ft_skip(fmt, i);
		}
	}
	ptr->spec = fmt[i++];
	return (i);
}
