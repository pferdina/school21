/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:05:59 by pferdina          #+#    #+#             */
/*   Updated: 2019/09/19 13:17:08 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;

	res = NULL;
	if (s)
	{
		res = (char*)malloc(sizeof(char) * (len + 1));
		if (!res)
			return (NULL);
		s += start;
		res[len] = '\0';
		while (len--)
			res[len] = s[len];
	}
	return (res);
}
