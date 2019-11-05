/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:57:21 by pferdina          #+#    #+#             */
/*   Updated: 2019/09/18 18:03:03 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*res;

	res = NULL;
	if (s)
	{
		len = ft_strlen(s);
		res = (char*)malloc(sizeof(char) * (len + 1));
		if (!res)
			return (NULL);
		res[len--] = '\0';
		while (len >= 0)
		{
			res[len] = f(s[len]);
			len--;
		}
	}
	return (res);
}
