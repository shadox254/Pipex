/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:31:16 by rruiz             #+#    #+#             */
/*   Updated: 2026/02/17 13:32:54 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*search_path(char **envp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] != '=' && envp[i][j])
			j++;
		str = ft_substr(envp[i], 0, j);
		if (ft_strncmp(str, "PATH", j) == 0)
		{
			free(str);
			return (envp[i] + j + 1);
		}
		free (str);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	**path;
	char	*part_path;
	char	*command;

	i = 0;
	command = ft_strjoin("/", cmd);
	path = ft_split(search_path(envp), ':');
	while (path[i])
	{
		part_path = ft_strjoin(path[i], command);
		if (access(part_path, X_OK | F_OK) == 0)
		{
			ft_free_tab(path);
			free(command);
			return (part_path);
		}
		free(part_path);
		i++;
	}
	ft_free_tab(path);
	free(command);
	return (NULL);
}
