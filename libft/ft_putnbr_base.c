/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:29:33 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/05 10:33:22 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(int fd, unsigned int n, char *base)
{
	size_t	nb;
	size_t	len;
	int		result;

	len = ft_strlen(base);
	if (len < 2)
		return (0);
	result = 0;
	nb = n;
	if (nb >= len)
		result += ft_putnbr(fd, nb / len, base);
	result += ft_putchar(fd, base[nb % len]);
	return (result);
}
