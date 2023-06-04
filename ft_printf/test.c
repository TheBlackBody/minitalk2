/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:17:20 by sfernand          #+#    #+#             */
/*   Updated: 2022/12/09 17:06:20 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

void	n(void)
{
	write(1, "\n", 2);
}

int	main(void)
{
	char *test;
	test = "test";
	ft_printf(" %d",ft_printf("%c",'1'));
	n();
	ft_printf(" %d", ft_printf(" NULL %s NULL ", NULL));
	n();
	ft_printf(" %d", ft_printf("%p", test));
	n();
	ft_printf(" %d", ft_printf("%i%s%d", 151, "test", 153));
	n();
	ft_printf(" %d", ft_printf(" %d ", -2147483648));
	n();
	ft_printf(" %d", ft_printf("%u", 111));
	n();
	ft_printf(" %d", ft_printf("%x", 74657374));
	n();
	ft_printf(" %d", ft_printf("%X", 74657374));
	n();
	ft_printf(" %d", ft_printf("%%%%%%%%%%%%%%%%%% test"));
	n();
	printf(" %d", printf(" %ld ", -2147483648));
	return (0);
}
