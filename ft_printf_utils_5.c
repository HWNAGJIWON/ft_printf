/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwhwang <jiwhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:58:23 by jiwhwang          #+#    #+#             */
/*   Updated: 2021/06/21 14:58:26 by jiwhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_str(char *str, int ret)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ret = ft_put_char(str[i], ret);
		i++;
	}
	return (ret);
}

long long	number_digit(long long a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int			number_digit_p(long long p)
{
	int	i;

	i = 0;
	if (p == 0)
		return (1);
	while (p > 0)
	{
		p /= 16;
		i++;
	}
	return (i);
}

int			print_hex(long long po, int ret)
{
	int		len;
	int		i;
	char	*res;
	char	*hex1;

	hex1 = "0123456789abcdef";
	if (po == 0)
		return (ft_put_char(hex1[0], ret));
	len = number_digit_p(po);
	i = len - 1;
	if (!(res = (char *)malloc(sizeof(char *) * (len))))
		return (ret);
	res[len - 1] = 0;
	ret = print_hex1_2(po, ret, res, i);
	free(res);
	return (ret);
}

int			print_hex1_2(long long po, int ret, char *res, int i)
{
	char	*hex1;
	int		len;

	len = number_digit_p(po);
	hex1 = "0123456789abcdef";
	while (po > 0)
	{
		res[i] = hex1[po % 16];
		po /= 16;
		i--;
	}
	i = -1;
	while (++i < len)
		ret = ft_put_char(res[i], ret);
	return (ret);
}
