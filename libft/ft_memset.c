/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:10:48 by rruiz             #+#    #+#             */
/*   Updated: 2025/10/22 10:51:27 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t size)
{
	size_t	i;
	char	*str;

	str = (char *)pointer;
	i = 0;
	while (i < size)
	{
		str[i] = value;
		i++;
	}
	return (pointer);
}
