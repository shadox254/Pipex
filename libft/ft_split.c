/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:55:27 by rruiz             #+#    #+#             */
/*   Updated: 2025/11/08 12:48:32 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_word_fill(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static int	count_word(const char *str, char c)
{
	int	word_count;
	int	a;

	word_count = 0;
	a = 0;
	while (*str)
	{
		if (*str != c && a == 0)
		{
			a = 1;
			word_count++;
		}
		else if (*str == c)
			a = 0;
		str++;
	}
	return (word_count);
}

static void	*ft_free_all(char **strs, int nb)
{
	int	i;

	i = 0;
	while (nb > i)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static void	ft_var_def(size_t *i, size_t *j, int *start_word)
{
	*i = 0;
	*j = 0;
	*start_word = -1;
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		start_word;
	char	**result;

	ft_var_def(&i, &j, &start_word);
	result = ft_calloc(count_word(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start_word < 0)
			start_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start_word >= 0)
		{
			result[j] = ft_word_fill(s, start_word, i);
			if (!(result[j]))
				return (ft_free_all(result, j));
			start_word = -1;
			j++;
		}
		i++;
	}
	return (result);
}
