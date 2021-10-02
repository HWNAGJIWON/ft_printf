/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwhwang <jiwhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:23:42 by jiwhwang          #+#    #+#             */
/*   Updated: 2021/06/21 15:53:51 by jiwhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct	s_flags
{
	int			zero;
	int			width;
	int			minus;
	int			dot;
	char		type;
	int			star1;
	int			star2;
	int			prcs;
	int			d_prcs;
}				t_flags;

typedef struct	s_st
{
	int			i;
	int			ret;
}				t_st;

t_flags			init_flags();
long long		ft_abs(long long c);
int				ft_in_the_base(char c, char *str);
char			*ft_itoa(long long n2);

int				ft_put_char(char c, int ret);
int				print_empty(int n, int ret);
int				print_zero(int n, int ret);
int				print_str(char *str, int ret);
int				print_hex(long long po, int ret);
int				print_hex1_2(long long po, int ret, char *res, int i);
int				print_hex2(long long po, int ret);
int				print_hex2_2(long long po, int ret, char *res, int i);
char			*ft_strjoin(char const *s1, char const *s2);
char			*make_zero_array(int k);
char			*make_empty_array(int k);
long long		number_digit(long long a);
int				number_digit_p(long long p);
t_st			d_000(char *res, t_flags flags, t_st st);
void			ft_fill_unsigned(char *str, int i, long long n, int size);
char			*ft_itoa_unsigned(unsigned int n2);
t_st			before_percent(char *input, va_list ap, t_st st);
t_st			from_percent_to_type_1(const char *save, va_list ap, t_st st);
t_st			from_percent_to_type_2(va_list ap, t_flags flags, t_st st);
t_st			percent_c(va_list ap, t_flags flags, t_st st);
t_st			percent_s(va_list ap, t_flags flags, t_st st);
t_st			percent_s_2(t_flags flags, t_st st, char *temp);
t_st			percent_d(va_list ap, t_flags flags, t_st st);
t_st			percent_d2(char *res, t_flags flags, long long va, t_st st);
t_st			percent_d3(char *res, t_flags flags, t_st st);
t_st			percent_u(va_list ap, t_flags flagsm, t_st st);
t_st			percent_u2(char *res, t_flags flags, unsigned int va, t_st st);
t_st			percent_u3(char *res, t_flags flags, t_st st);
t_st			percent_p(va_list ap, t_flags flags, t_st st);
t_st			percent_p_2(t_flags flags, t_st st, long long po);
t_st			percent_x(va_list ap, t_flags flags, t_st st);
t_st			percent_x2(char *temp, t_flags flags, unsigned int va, t_st st);
t_st			percent_x3(char *temp, t_flags flags, unsigned int va, t_st st);
t_st			percent_cap_x(va_list ap, t_flags flags, t_st st);
t_st			percent_cap_x2(char *temp,
		t_flags flags, unsigned int va, t_st st);
t_st			percent_cap_x3(char *temp,
		t_flags flags, unsigned int va, t_st st);
t_st			sort_by_type(va_list ap, char type, t_flags flags, t_st st);
t_st			percent_percent(t_flags flags, t_st st);
t_st			percent_percent_2(t_flags flags, t_st st, int i);
t_st			next_type(const char *save, int i, t_st st);
int				ft_printf(const char *input, ...);
void			*ft_memset(void *ptr, int value, size_t num);
int				ft_atoi(const char *str);
void			ft_bzero(void *ptr, size_t num);
void			*ft_calloc(size_t n, size_t size);
char			*ft_strdup(const char *s);
int				ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif
