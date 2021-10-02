/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwhwang <jiwhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:23:13 by jiwhwang          #+#    #+#             */
/*   Updated: 2021/06/21 15:23:15 by jiwhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_st	percent_percent_2(t_flags flags, t_st st, int i)
{
	if (flags.zero == 1 && flags.width > 1)
	{
		while (i < flags.width - 1)
		{
			st.ret = ft_put_char('0', st.ret);
			i++;
		}
		st.ret = ft_put_char('%', st.ret);
	}
	else
	{
		while (i < flags.width - 1)
		{
			st.ret = ft_put_char(' ', st.ret);
			i++;
		}
		st.ret = ft_put_char('%', st.ret);
	}
	return (st);
}

t_st	next_type(const char *save, int i, t_st st)
{
	while (save[i] != '%')
	{
		st.ret = ft_put_char(save[i], st.ret);
		i++;
	}
	return (st);
}

int		ft_printf(const char *input, ...)
{
	va_list	ap;
	t_st	st;
	int		k;

	k = 0;
	st.i = 0;
	st.ret = 0;
	va_start(ap, input);
	while (st.i < ft_strlen(input))
	{
		while (input[st.i] != '%' && ft_strlen(input) > st.i)
		{
			st.ret = ft_put_char(input[st.i], st.ret);
			st.i++;
		}
		st.i++;
		if (ft_strlen(input) <= st.i)
			break ;
		st = from_percent_to_type_1(input, ap, st);
	}
	return (st.ret);
}
