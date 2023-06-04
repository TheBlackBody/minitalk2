/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:25:42 by sfernand          #+#    #+#             */
/*   Updated: 2022/12/09 17:05:02 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_size
{
	int	len;
}				t_size;

int		ft_printf(const char *str, ...);
int		ft_putunbr_fd(unsigned int n, int fd);
int		ft_hexa(unsigned int num, const char str);
int		ft_void_hexa(unsigned long hexa);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(const char *s, int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *a);

#endif
