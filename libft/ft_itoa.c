/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:34:21 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/20 08:43:26 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(long n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		len = 2;
		n *= -1;
	}
	while ((n / 10) > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	len;
	long	nb;
	char	*s;

	nb = (long)n;
	len = ft_intlen(nb);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	i = 1;
	s[0] = '0';
	if (nb < 0)
	{
		s[0] = '-';
		nb *= -1;
	}
	while (nb)
	{
		s[len - i] = nb % 10 + 48;
		nb /= 10;
		i++;
	}
	s[len] = '\0';
	return (s);
}
