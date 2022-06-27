/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dex_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 07:53:36 by rphoebe           #+#    #+#             */
/*   Updated: 2021/02/05 07:57:38 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_array_clear(int array[1024])
{
	int i;

	i = 1023;
	while (i)
	{
		array[i] = 0;
		i--;
	}
}

char	*ft_array_to_str(int array[1024], int i, t_list *ptr)
{
	char	s_array[i];
	int		j;
	char	*str;

	j = 0;
	s_array[i--] = '\0';
	str = &s_array[0];
	while (i >= 0)
	{
		if (array[i] > 9 && array[i] < 16)
		{
			if (ptr->spec == 'x' || ptr->spec == 'p')
				s_array[j++] = array[i--] + 87;
			if (ptr->spec == 'X')
				s_array[j++] = array[i--] + 55;
		}
		else
		{
			s_array[j++] = array[i--] + 48;
		}
	}
	return (str);
}

char	*ft_dec_hex(unsigned int n, t_list *ptr)
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
