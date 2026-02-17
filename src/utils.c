/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:31:26 by rruiz             #+#    #+#             */
/*   Updated: 2026/02/17 13:33:57 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_fd(t_data *pipex);

void	error(t_data *pipex, int error_nb)
{
	if (error_nb == 0)
		ft_printf_fd(2, "Usage: < file1 cmd1 | cmd2 > file2");
	else if (error_nb == 1)
		ft_printf_fd(2, "Error with file1");
	else if (error_nb == 2)
		ft_printf_fd(2, "Error with file2");
	else if (error_nb == 3)
		ft_printf_fd(2, "Error with cmd1");
	else if (error_nb == 4)
		ft_printf_fd(2, "Error with cmd2");
	else if (error_nb == 5)
		ft_printf_fd(2, "Error with pipe_fd");
	else if (error_nb == 6)
		(void) error_nb;
	else if (error_nb == 7)
		(void) error_nb;
	free_all(pipex);
	close_fd(pipex);
	exit(0);
}

static void	close_fd(t_data *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
}

void	process_first_child(t_data pipex, char **envp)
{
	dup2(pipex.infile, 0);
	dup2(pipex.pipe_fd[1], 1);
	close(pipex.pipe_fd[0]);
	execve(pipex.cmd1, pipex.cmd1_args, envp);
}

void	process_second_child(t_data pipex, char **envp)
{
	dup2(pipex.pipe_fd[0], 0);
	dup2(pipex.outfile, 1);
	close(pipex.pipe_fd[1]);
	execve(pipex.cmd2, pipex.cmd2_args, envp);
}

void	free_all(t_data *pipex)
{
	free(pipex->cmd1);
	ft_free_tab(pipex->cmd1_args);
	free(pipex->cmd2);
	ft_free_tab(pipex->cmd2_args);
}
