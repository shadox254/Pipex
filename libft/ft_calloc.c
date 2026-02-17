/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:59:51 by rruiz             #+#    #+#             */
/*   Updated: 2025/10/22 10:56:47 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t eCount, size_t eSize)
{
	void	*ptr;
	int		tot;

	tot = eCount * eSize;
	if (tot == 0)
		return (malloc(0));
	if (tot / eSize != eCount)
		return (NULL);
	ptr = malloc(tot);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, '\0', tot);
	return (ptr);
}
