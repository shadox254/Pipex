/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:31:40 by rruiz             #+#    #+#             */
/*   Updated: 2026/02/17 13:37:45 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_data
{
	int		infile;
	int		outfile;
	int		pipe_fd[2];
	char	*cmd1;
	char	**cmd1_args;
	char	*cmd2;
	char	**cmd2_args;
	pid_t	pid1;
	pid_t	pid2;
}	t_data;

/* UTILS */
void	error(t_data *pipex, int error_nb);
void	process_first_child(t_data pipex, char **envp);
void	process_second_child(t_data pipex, char **envp);
void	free_all(t_data *pipex);

/* CREATE_PATH */
char	*search_path(char **envp);
char	*get_path(char *cmd, char **envp);

#endif
