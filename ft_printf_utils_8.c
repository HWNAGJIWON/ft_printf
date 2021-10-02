/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_8.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwhwang@student.42.fr <jiwhwang>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:59:50 by jiwhwang          #+#    #+#             */
/*   Updated: 2021/06/21 17:43:04 by jiwhwang@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_st	percent_d2(char *res, t_flags flags, long long va, t_st st)
{
	if (flags.dot == 1 && va == 0)
		st = d_000(res, flags, st);
	else if (flags.minus == 1)
	{
		if (flags.star1 > 0)
			st.ret = ft_put_char('-', st.ret);
		st.ret = print_str(res, st.ret);
		st.ret =
			print_empty(flags.width - flags.star1 - ft_strlen(res), st.ret);
	}
	else if (flags.width > ft_strlen(res))
		st = percent_d3(res, flags, st);
	else
	{
		if (flags.star1 > 0)
			st.ret = ft_put_char('-', st.ret);
		st.ret = print_str(res, st.ret);
	}
	free(res);
	return (st);
}

t_st	percent_d3(char *res, t_flags flags, t_st st)
{
	if (flags.zero == 1 && (flags.d_prcs == 1 || flags.prcs < 0))
	{
		if (flags.star1 > 0)
			st.ret = ft_put_char('-', st.ret);
		st.ret =
			print_zero(flags.width - flags.star1 - ft_strlen(res), st.ret);
		st.ret = print_str(res, st.ret);
	}
	else
	{
		st.ret =
			print_empty(flags.width - flags.star1 - ft_strlen(res), st.ret);
		if (flags.star1 > 0)
			st.ret = ft_put_char('-', st.ret);
		st.ret = print_str(res, st.ret);
	}
	return (st);
}

t_st	d_000(char *res, t_flags flags, t_st st)
{
	if (flags.zero == 1 && flags.prcs < 0 && flags.width > 0)
	{
		st.ret = print_zero(flags.width - ft_strlen(res), st.ret);
		st.ret = print_str(res, st.ret);
	}
	else if (flags.width > 0 && flags.prcs == 0)
	{
		st.ret = print_empty(flags.width, st.ret);
	}
	else if (flags.prcs == 0)
		;
	else if (flags.prcs != 0 && flags.minus == 0)
	{
		st.ret = print_empty(flags.width - ft_strlen(res), st.ret);
		st.ret = print_str(res, st.ret);
	}
	else if (flags.prcs != 0 && flags.minus == 1)
	{
		st.ret = print_str(res, st.ret);
		st.ret = print_empty(flags.width - ft_strlen(res), st.ret);
	}
	return (st);
}

t_st	percent_u(va_list ap, t_flags flags, t_st st)
{
	char			*temp;
	char			*res;
	unsigned int	va;

	va = (unsigned int)va_arg(ap, unsigned int);
	flags.star1 = 0;
	if (flags.prcs > -1)
		temp = make_zero_array(flags.prcs - (number_digit(va)));
	else
		temp = ft_strdup("");
	if (!temp)
		return (st);
	if (!(res = ft_strjoin(temp, ft_itoa_unsigned(va))))
		return (st);
	free(temp);
	return (percent_u2(res, flags, va, st));
}

t_st	percent_u2(char *res, t_flags flags, unsigned int va, t_st st)
{
	if (flags.dot == 1 && flags.prcs == 0 && va == 0)
		st.ret = print_empty(flags.width, st.ret);
	else if (flags.minus == 1)
	{
		st.ret = print_str(res, st.ret);
		st.ret = print_empty(flags.width - ft_strlen(res), st.ret);
	}
	else if (flags.width > ft_strlen(res) || (flags.dot == 1 && va == 0))
		st = percent_u3(res, flags, st);
	else
		st.ret = print_str(res, st.ret);
	free(res);
	return (st);
}
