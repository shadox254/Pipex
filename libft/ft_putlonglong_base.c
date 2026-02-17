/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlonglong_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:34:13 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/05 10:33:35 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	put_percentp(int fd, unsigned long long n)
{
	char				*base;
	size_t				len;
	int					count;

	base = "0123456789abcdef";
	len = ft_strlen(base);
	count = 0;
	if (n >= len)
		count += put_percentp(fd, n / len);
	count += ft_putchar(fd, base[n % len]);
	return (count);
}

int	ft_putlonglong_hex(int fd, unsigned long long n)
{
	int	count;

	if (n == 0)
	{
		ft_putstr(fd, "(nil)");
		return (5);
	}
	count = ft_putstr(fd, "0x");
	count += put_percentp(fd, n);
	return (count);
}
