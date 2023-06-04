/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:11:49 by sfernand          #+#    #+#             */
/*   Updated: 2022/11/16 17:36:12 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	dst = malloc(sizeof (*s) * (len + 1));
	if (!s)
		return (ft_strdup(""));
	if (!dst)
		return (0);
	if (start >= ft_strlen(s))
		return (dst);
	while (n < start)
		n++;
	while (i < len && s[n])
	{
		dst[i] = s[n];
		n++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
