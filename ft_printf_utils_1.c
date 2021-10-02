/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwhwang <jiwhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:55:37 by jiwhwang          #+#    #+#             */
/*   Updated: 2021/06/21 14:55:42 by jiwhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_size(long long n)
{
	int	i;

	i = (n <= 0) ? 1 : 0;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

void	ft_fill(char *str, int i, long long n, int size)
{
	int	negative;

	negative = 0;
	if (n < 0)
	{
		negative = 1;
		n *= -1;
		str[0] = '-';
	}
	str[size] = 0;
	i = size - 1;
	while (i >= negative)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
}

void	ft_fill_unsigned(char *str, int i, long long n, int size)
{
	int	negative;

	negative = 0;
	str[size] = 0;
	i = size - 1;
	while (i >= negative)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
}

char	*ft_itoa(long long n2)
{
	int			i;
	int			size;
	char		*str;
	long long	n;

	n = n2;
	i = 0;
	size = count_size(n);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_fill(str, i, n, size);
	return (str);
}

char	*ft_itoa_unsigned(unsigned int n2)
{
	int			i;
	int			size;
	char		*str;
	long long	n;

	n = n2;
	i = 0;
	size = count_size(n);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_fill(str, i, n, size);
	return (str);
}
