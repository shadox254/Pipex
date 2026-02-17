/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:29:33 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/05 10:33:31 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int fd, int n, char *base)
{
	unsigned int	nb;
	unsigned int	len;
	int				result;

	result = 0;
	len = ft_strlen(base);
	if (n < 0)
	{
		result += ft_putchar(fd, '-');
		nb = -n;
	}
	else
		nb = n;
	if (nb >= len)
		result += ft_putnbr(fd, nb / len, base);
	result += ft_putchar(fd, base[nb % len]);
	return (result);
}
