/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:05:21 by rruiz             #+#    #+#             */
/*   Updated: 2025/10/22 10:55:21 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*stk;

	i = 0;
	stk = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (stk == NULL)
		return (NULL);
	while (src[i])
	{
		stk[i] = src[i];
		i++;
	}
	stk[i] = '\0';
	return (stk);
}
