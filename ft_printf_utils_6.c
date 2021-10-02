/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwhwang <jiwhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:58:52 by jiwhwang          #+#    #+#             */
/*   Updated: 2021/06/21 14:58:55 by jiwhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_hex2(long long po, int ret)
{
	int		len;
	int		i;
	char	*res;
	char	*hex2;

	hex2 = "0123456789ABCDEF";
	if (po == 0)
		return (ft_put_char(hex2[0], ret));
	len = number_digit_p(po);
	i = len - 1;
	if (!(res = (char *)malloc(sizeof(char *) * (len))))
		return (ret);
	res[len - 1] = 0;
	ret = print_hex2_2(po, ret, res, i);
	free(res);
	return (ret);
}

int		print_hex2_2(long long po, int ret, char *res, int i)
{
	char	*hex2;
	int		len;

	len = number_digit_p(po);
	hex2 = "0123456789ABCDEF";
	while (po > 0)
	{
		res[i] = hex2[po % 16];
		po /= 16;
		i--;
	}
	i = 0;
	while (i < len)
		ret = ft_put_char(res[i++], ret);
	return (ret);
}

t_st	from_percent_to_type_1(const char *save, va_list ap, t_st st)
{
	t_flags	flags;

	flags = init_flags();
	while (!(ft_in_the_base(save[st.i], "cspdiuxX%%")))
	{
		if (save[st.i] == '-')
			flags.minus = 1;
		else if (flags.dot == 0 && save[st.i] == '0' && flags.minus != 1 &&
					flags.width <= 0)
			flags.zero = 1;
		else if (flags.dot == 0 && '0' <= save[st.i] && save[st.i] <= '9')
			flags.width = flags.width * 10 + (save[st.i] - 48);
		else if (flags.dot == 1 && '0' <= save[st.i] && save[st.i] <= '9')
			flags.prcs = flags.prcs * 10 + (save[st.i] - 48);
		else if (flags.dot == 0 && save[st.i] == '*')
			flags.star1 = va_arg(ap, int);
		else if (flags.dot == 1 && save[st.i] == '*')
			flags.star2 = va_arg(ap, int);
		else if (save[st.i] == '.')
			flags.dot = 1;
		st.i++;
	}
	flags.type = save[st.i++];
	return (from_percent_to_type_2(ap, flags, st));
}

t_st	from_percent_to_type_2(va_list ap, t_flags flags, t_st st)
{
	if (flags.prcs == 0 && flags.dot == 0)
		flags.d_prcs = 1;
	if (flags.star1 < 0)
		flags.minus = 1;
	if (flags.star1 != 0)
	{
		flags.width = ft_abs(flags.star1);
		if (flags.minus == 1 && flags.zero == 1)
			flags.zero = 0;
	}
	if (flags.star2 != 0)
		flags.prcs = flags.star2;
	return (sort_by_type(ap, flags.type, flags, st));
}
