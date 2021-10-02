/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwhwang <jiwhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:59:32 by jiwhwang          #+#    #+#             */
/*   Updated: 2021/06/21 15:56:19 by jiwhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_st	sort_by_type(va_list ap, char type, t_flags flags, t_st st)
{
	if (type == 'c')
		st = percent_c(ap, flags, st);
	else if (type == 's')
		st = percent_s(ap, flags, st);
	else if (type == 'u')
		st = percent_u(ap, flags, st);
	else if (type == 'p')
		st = percent_p(ap, flags, st);
	else if (type == 'd')
		st = percent_d(ap, flags, st);
	else if (type == 'i')
		st = percent_d(ap, flags, st);
	else if (type == 'x')
		st = percent_x(ap, flags, st);
	else if (type == 'X')
		st = percent_cap_x(ap, flags, st);
	else if (type == '%')
		st = percent_percent(flags, st);
	return (st);
}

t_st	percent_c(va_list ap, t_flags flags, t_st st)
{
	int	answer;

	answer = va_arg(ap, int);
	if (flags.minus == 1)
	{
		st.ret = ft_put_char(answer, st.ret);
		st.ret = print_empty(flags.width - 1, st.ret);
	}
	else
	{
		st.ret = print_empty(flags.width - 1, st.ret);
		st.ret = ft_put_char(answer, st.ret);
	}
	return (st);
}

t_st	percent_s(va_list ap, t_flags flags, t_st st)
{
	char	*temp;
	char	*temp2;

	temp2 = va_arg(ap, char *);
	if (!temp2)
		temp = strdup("(null)");
	else
		temp = strdup(temp2);
	if (flags.prcs > 0)
	{
		temp2 = ft_substr(temp, 0, flags.prcs);
		free(temp);
		temp = strdup(temp2);
		free(temp2);
	}
	st = percent_s_2(flags, st, temp);
	free(temp);
	return (st);
}

t_st	percent_s_2(t_flags flags, t_st st, char *temp)
{
	if (flags.dot == 1 && flags.prcs == 0)
	{
		st.ret = print_empty(flags.width, st.ret);
	}
	else if (flags.minus == 1)
	{
		st.ret = print_str(temp, st.ret);
		st.ret = print_empty(flags.width - ft_strlen(temp), st.ret);
	}
	else
	{
		st.ret = print_empty(flags.width - ft_strlen(temp), st.ret);
		st.ret = print_str(temp, st.ret);
	}
	return (st);
}

t_st	percent_d(va_list ap, t_flags flags, t_st st)
{
	char		*temp;
	char		*res;
	long long	va;

	va = va_arg(ap, int);
	if (va < 0)
		flags.star1 = 1;
	else
		flags.star1 = 0;
	if (flags.prcs != 0 && flags.dot == 1)
		temp = make_zero_array(flags.prcs - (number_digit(ft_abs(va))));
	else
		temp = ft_strdup("");
	if (!temp)
		return (st);
	if (!(res = ft_strjoin(temp, ft_itoa(ft_abs(va)))))
		return (st);
	free(temp);
	return (percent_d2(res, flags, va, st));
}
