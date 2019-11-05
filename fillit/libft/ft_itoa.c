/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:00:33 by pferdina          #+#    #+#             */
/*   Updated: 2019/09/20 14:35:44 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	getlen(int n)
{
	int	len;

	len = 1;
	while (n /= 10)
	{
		len++;
	}
	return (len);
}

static void	generate_string(char **res, unsigned int n, int len)
{
	res[0][len--] = '\0';
	if (n == 0)
		res[0][len] = '0';
	while (n)
	{
		res[0][len--] = n % 10 + '0';
		n /= 10;
	}
}

char		*ft_itoa(int n)
{
	int				len;
	unsigned int	nbr;
	char			*res;

	len = getlen(n);
	if (n < 0)
	{
		nbr = -n;
		res = (char*)malloc(sizeof(char) * (++len + 1));
		if (!res)
			return (NULL);
		*res = '-';
	}
	else
	{
		nbr = n;
		res = (char*)malloc(sizeof(char) * (len + 1));
		if (!res)
			return (NULL);
	}
	generate_string(&res, nbr, len);
	return (res);
}
