/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwhwang <jiwhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:54:41 by jiwhwang          #+#    #+#             */
/*   Updated: 2021/06/21 14:54:44 by jiwhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		*((char *)ptr + i) = value;
		i++;
	}
	return (ptr);
}

void	ft_bzero(void *ptr, size_t num)
{
	ft_memset(ptr, 0, num);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*p;

	if (!(p = malloc(n * size)))
		return ((void *)0);
	ft_bzero(p, n * size);
	return (p);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		len;

	len = 0;
	while (s[len])
		len++;
	ptr = ft_calloc(len + 1, 1);
	if (ptr == 0)
		return (0);
	len = 0;
	while (s[len])
	{
		ptr[len] = s[len];
		len++;
	}
	ptr[len] = 0;
	return (ptr);
}

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
