/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:53:49 by rruiz             #+#    #+#             */
/*   Updated: 2025/10/22 10:55:04 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *fullstr, const char *substr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (substr[0] == '\0')
		return ((char *)fullstr);
	while (fullstr[i] && i < len)
	{
		while (fullstr[i + j] && i + j < len && fullstr[i + j] == substr[j])
		{
			j++;
			if (substr[j] == 0)
				return ((char *) fullstr + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
