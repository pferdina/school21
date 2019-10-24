/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:03:11 by pferdina          #+#    #+#             */
/*   Updated: 2019/09/19 18:36:46 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*res;

	res = NULL;
	if (s && f)
	{
		len = (unsigned int)ft_strlen(s);
		res = (char *)malloc(sizeof(char) * (len + 1));
		if (!res)
			return (NULL);
		res[len--] = '\0';
		while (1)
		{
			res[len] = f(len, s[len]);
			if (len == 0)
				break ;
			len--;
		}
	}
	return (res);
}
