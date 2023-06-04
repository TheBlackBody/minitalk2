/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:22:09 by sfernand          #+#    #+#             */
/*   Updated: 2023/01/04 17:03:26 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main() 
{
	    int	fd = open("map.ber", O_RDONLY);
		char	*line;

		line = get_next_line(fd);
		printf("%s", line);
		line = get_next_line(fd);
		printf("%s", line);
		while (line != NULL)
		{
			line = get_next_line(fd);
			printf("%s", line);
		}
		return (0);
}

