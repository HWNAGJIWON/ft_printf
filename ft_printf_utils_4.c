/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwhwang <jiwhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:58:01 by jiwhwang          #+#    #+#             */
/*   Updated: 2021/06/21 14:58:03 by jiwhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_in_the_base(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int			print_empty(int n, int ret)
{
	int	i;

	i = 0;
	if (n <= 0)
		return (ret);
	while (i < n)
	{
		ret = ft_put_char(' ', ret);
		i++;
	}
	return (ret);
}

int			print_zero(int n, int ret)
{
	int	i;

	i = 0;
	if (n <= 0)
		return (ret);
	while (i < n)
	{
		ret = ft_put_char('0', ret);
		i++;
	}
	return (ret);
}

char		*make_zero_array(int k)
{
	int		i;
	char	*res;

	i = 0;
	if (k < 0)
		return (ft_strdup(""));
	res = (char *)malloc(sizeof(char *) * (k + 1));
	if (!res)
		return ((char *)0);
	while (i < k)
	{
		res[i] = '0';
		i++;
	}
	res[i] = 0;
	return (res);
}

char		*make_empty_array(int k)
{
	int		i;
	char	*res;

	i = 0;
	if (k < 0)
		return (ft_strdup(""));
	res = (char *)malloc(sizeof(char *) * (k + 1));
	if (!res)
		return ((char *)0);
	while (i < k)
	{
		res[i] = ' ';
		i++;
	}
	res[i] = 0;
	return (res);
}
