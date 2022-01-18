/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apulido- <apulido-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:28:43 by alex              #+#    #+#             */
/*   Updated: 2022/01/18 16:35:48 by apulido-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static int	is_space(char cr);
size_t	ft_strlen(const char *s);

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned int	num;

	num = 0;
	sign = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if (num > 2147483647 && sign == 1)
			return (-1);
		if (num > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (num * sign);
}

static int	is_space(char cr)
{
	return (cr == ' ' || cr == '\t' || cr == '\n'
		|| cr == '\v' || cr == '\f' || cr == '\r');
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*a;
	unsigned int	cont;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	a = malloc(len + 1);
	if (!a)
		return (NULL);
	cont = 0;
	while (s[start + cont] && cont < len)
	{
		a[cont] = s[start + cont];
		cont++;
	}
	a[cont] = '\0';
	return (a);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
