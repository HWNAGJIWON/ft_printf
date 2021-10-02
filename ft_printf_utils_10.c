/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_10.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwhwang <jiwhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:19:32 by jiwhwang          #+#    #+#             */
/*   Updated: 2021/06/21 15:59:24 by jiwhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_st	percent_x3(char *temp, t_flags flags, unsigned int va, t_st st)
{
	if (flags.zero == 1 && (flags.prcs < 0 || flags.d_prcs == 1))
	{
		st.ret = print_zero(flags.width - ft_strlen(temp) - number_digit_p(va),
							st.ret);
		st.ret = print_str(temp, st.ret);
		st.ret = print_hex(va, st.ret);
	}
	else
	{
		st.ret = print_empty(flags.width - ft_strlen(temp) - number_digit_p(va),
								st.ret);
		st.ret = print_str(temp, st.ret);
		st.ret = print_hex(va, st.ret);
	}
	return (st);
}

t_st	percent_cap_x(va_list ap, t_flags flags, t_st st)
{
	char			*temp;
	unsigned int	va;

	va = va_arg(ap, unsigned int);
	if (flags.prcs != -1)
		temp = make_zero_array(flags.prcs - (number_digit_p(va)));
	else
		temp = ft_strdup("");
	if (!temp)
		return (st);
	return (percent_cap_x2(temp, flags, va, st));
}

t_st	percent_cap_x2(char *temp, t_flags flags, unsigned int va, t_st st)
{
	if (flags.dot == 1 && flags.prcs == 0 && va == 0)
		st.ret = print_empty(flags.width, st.ret);
	else if (flags.minus == 1)
	{
		st.ret = print_str(temp, st.ret);
		st.ret = print_hex2(va, st.ret);
		st.ret = print_empty(flags.width - ft_strlen(temp) - number_digit_p(va),
								st.ret);
	}
	else if (flags.width > ft_strlen(temp))
		st = percent_cap_x3(temp, flags, va, st);
	else
	{
		st.ret = print_str(temp, st.ret);
		st.ret = print_hex2(va, st.ret);
	}
	free(temp);
	return (st);
}

t_st	percent_cap_x3(char *temp, t_flags flags, unsigned int va, t_st st)
{
	if (flags.zero == 1 && (flags.d_prcs == 1 || flags.prcs < 0))
	{
		st.ret = print_zero(flags.width - ft_strlen(temp) - number_digit_p(va),
							st.ret);
		st.ret = print_str(temp, st.ret);
		st.ret = print_hex2(va, st.ret);
	}
	else
	{
		st.ret = print_empty(flags.width - ft_strlen(temp) - number_digit_p(va),
								st.ret);
		st.ret = print_str(temp, st.ret);
		st.ret = print_hex2(va, st.ret);
	}
	return (st);
}

t_st	percent_percent(t_flags flags, t_st st)
{
	int	i;

	i = 0;
	if (flags.minus == 1)
	{
		st.ret = ft_put_char('%', st.ret);
		while (i < flags.width - 1)
		{
			st.ret = ft_put_char(' ', st.ret);
			i++;
		}
	}
	else
		st = percent_percent_2(flags, st, i);
	return (st);
}
