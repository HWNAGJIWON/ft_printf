/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_9.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwhwang@student.42.fr <jiwhwang>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:07:19 by jiwhwang          #+#    #+#             */
/*   Updated: 2021/06/21 16:44:24 by jiwhwang@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_st	percent_u3(char *res, t_flags flags, t_st st)
{
	if (flags.zero == 1 && (flags.d_prcs == 1 || flags.prcs < 0))
	{
		st.ret = print_zero(flags.width - ft_strlen(res), st.ret);
		st.ret = print_str(res, st.ret);
	}
	else
	{
		st.ret =
			print_empty(flags.width - flags.star1 - ft_strlen(res), st.ret);
		st.ret = print_str(res, st.ret);
	}
	return (st);
}

t_st	percent_p(va_list ap, t_flags flags, t_st st)
{
	long long	po;

	po = va_arg(ap, long long);
	if (flags.dot == 1 && flags.prcs == 0 && po == 0)
	{
		if (flags.minus == 0)
			st.ret = print_empty(flags.width - 2, st.ret);
		st.ret = ft_put_char('0', st.ret);
		st.ret = ft_put_char('x', st.ret);
		if (flags.minus == 1)
			st.ret = print_empty(flags.width - 2, st.ret);
	}
	else
		st = percent_p_2(flags, st, po);
	return (st);
}

t_st	percent_p_2(t_flags flags, t_st st, long long po)
{
	if (flags.minus == 1)
	{
		st.ret = ft_put_char('0', st.ret);
		st.ret = ft_put_char('x', st.ret);
		st.ret = print_hex(po, st.ret);
		st.ret =
			print_empty(flags.width - 2 - number_digit_p(po), st.ret);
	}
	else
	{
		st.ret =
			print_empty(flags.width - 2 - number_digit_p(po), st.ret);
		st.ret = ft_put_char('0', st.ret);
		st.ret = ft_put_char('x', st.ret);
		st.ret = print_hex(po, st.ret);
	}
	return (st);
}

t_st	percent_x(va_list ap, t_flags flags, t_st st)
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
	return (percent_x2(temp, flags, va, st));
}

t_st	percent_x2(char *temp, t_flags flags, unsigned int va, t_st st)
{
	if (flags.dot == 1 && flags.prcs == 0 && va == 0)
		st.ret = print_empty(flags.width, st.ret);
	else if (flags.minus == 1)
	{
		st.ret = print_str(temp, st.ret);
		st.ret = print_hex(va, st.ret);
		st.ret = print_empty(flags.width -
				ft_strlen(temp) - number_digit_p(va), st.ret);
	}
	else if (flags.width > ft_strlen(temp))
		st = percent_x3(temp, flags, va, st);
	else
	{
		st.ret = print_str(temp, st.ret);
		st.ret = print_hex(va, st.ret);
	}
	free(temp);
	return (st);
}
