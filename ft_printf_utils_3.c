/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwhwang <jiwhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:56:06 by jiwhwang          #+#    #+#             */
/*   Updated: 2021/06/21 14:57:43 by jiwhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	size_t			min_len;

	if (!s)
		return (0);
	min_len = ft_strlen(s);
	if (min_len < len)
		return (ft_strdup(s));
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while ((size_t)i < len && start + i < (unsigned int)ft_strlen(s))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*answer;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(answer = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (0);
	i = -1;
	j = 0;
	while (s1[++i])
		answer[i] = s1[i];
	while (s2[j])
	{
		answer[i + j] = s2[j];
		j++;
	}
	answer[i + j] = 0;
	return (answer);
}

int			ft_put_char(char c, int ret)
{
	write(1, &c, 1);
	ret++;
	return (ret);
}

t_flags		init_flags(void)
{
	t_flags	flags;

	flags.zero = 0;
	flags.width = 0;
	flags.minus = 0;
	flags.dot = 0;
	flags.type = ' ';
	flags.star1 = 0;
	flags.star2 = 0;
	flags.prcs = 0;
	flags.d_prcs = 0;
	return (flags);
}

long long	ft_abs(long long c)
{
	if (c < 0)
		return (c * -1);
	return (c);
}
