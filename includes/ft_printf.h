/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:13:53 by rphoebe           #+#    #+#             */
/*   Updated: 2021/02/05 09:04:21 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct	s_list
{
	int		minus;
	int		zero;
	int		dot;
	int		w_star;
	int		p_star;
	int		width;
	int		precision;
	int		intlen;
	int		ret;
	char	spec;
}				t_list;

int				ft_atoi(const char *str);
int				ft_isalpha(int c);
void			ft_putchar(char c, t_list *ptr);
void			ft_putchar_nbr(char c);
void			ft_putnbr(long int n);
void			ft_putstr(char *s);
char			*ft_strchr(const char *s, int c);
int				ft_strlen(const char *str);
void			ft_putchar_zero(int h, t_list *ptr);
void			ft_putchar_space(int h, t_list *ptr);
int				ft_intlen(long int n);
void			ft_integers(va_list *ap, t_list *ptr);
int				ft_parcer(const char *fmt, t_list *ptr, int i);
void			ft_struzero(t_list *ptr);
void			ft_preparcer(t_list *ptr);
int				ft_skip(const char *fmt, int i);
int				ft_flags(const char *fmt, t_list *ptr, int i);
int				ft_stars(const char *fmt, t_list *ptr, int i);
void			ft_star_check(va_list *ap, t_list *ptr);
void			ft_int_plus(long int n, t_list *ptr, int len);
void			ft_int_minus(long int n, t_list *ptr, int len);
void			ft_int_zero(long int n, t_list *ptr, int len);
void			ft_integers_negative(int n, t_list *ptr, int len);
void			ft_int_plus_n(long int n, t_list *ptr, int len);
void			ft_int_minus_n(long int n, t_list *ptr, int len);
void			ft_int_zero_n(long int n, t_list *ptr, int len);
void			ft_integers_u(va_list *ap, t_list *ptr);
char			*ft_dec_hex(unsigned int n, t_list *ptr);
void			ft_x(va_list *ap, t_list *ptr);
void			ft_char(va_list *ap, t_list *ptr);
void			ft_string(va_list *ap, t_list *ptr);
void			ft_percent(va_list *ap, t_list *ptr);
void			ft_p(va_list *ap, t_list *ptr);
void			ft_chosen_one(va_list *ap, t_list *ptr);
void			ft_array_clear(int array[1024]);
char			*ft_array_to_str(int array[1024], int i, t_list *ptr);
void			ft_x_plus(char *str, t_list *ptr, int len);
void			ft_x_minus(char *str, t_list *ptr, int len);
void			ft_x_zero(char *str, t_list *ptr, int len);

#endif
