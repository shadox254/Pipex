/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:52:46 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/09 09:20:53 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_percent(int fd, char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(fd, va_arg(args, int));
	if (c == 's')
		count = ft_putstr(fd, va_arg(args, char *));
	if (c == 'p')
		count += ft_putlonglong_hex(fd, va_arg(args, unsigned long long));
	if (c == 'd')
		count = ft_putnbr(fd, va_arg(args, int), "0123456789");
	if (c == 'i')
		count = ft_putnbr(fd, va_arg(args, int), "0123456789");
	if (c == 'u')
		count = ft_putnbr_base(fd, va_arg(args, unsigned int), "0123456789");
	if (c == 'x')
		count = ft_putnbr_base(fd, va_arg(args, unsigned int),
				"0123456789abcdef");
	if (c == 'X')
		count = ft_putnbr_base(fd, va_arg(args, unsigned int),
				"0123456789ABCDEF");
	if (c == '%')
		count = ft_putchar(fd, '%');
	return (count);
}

int	ft_printf_fd(int fd, const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += is_percent(fd, s[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar(fd, s[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
