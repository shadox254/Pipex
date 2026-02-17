/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:38:57 by rruiz             #+#    #+#             */
/*   Updated: 2025/10/22 10:58:06 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	int			j;
	char		*stk;

	i = 0;
	j = 0;
	stk = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!stk)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		stk[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		stk[i + j] = s2[j];
		j++;
	}
	stk[i + j] = '\0';
	return (stk);
}
