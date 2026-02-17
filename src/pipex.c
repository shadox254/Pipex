/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:31:34 by rruiz             #+#    #+#             */
/*   Updated: 2026/02/17 13:37:10 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_data(t_data *pipex, char **av, char **envp)
{
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile == -1)
		error(pipex, 1);
	pipex->outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->outfile == -1)
		error(pipex, 2);
	pipex->cmd1_args = ft_split(av[2], ' ');
	pipex->cmd1 = get_path(pipex->cmd1_args[0], envp);
	if (!pipex->cmd1)
		error(pipex, 3);
	pipex->cmd2_args = ft_split(av[3], ' ');
	pipex->cmd2 = get_path(pipex->cmd2_args[0], envp);
	if (!pipex->cmd2)
		error(pipex, 4);
}

int	main(int ac, char **av, char **envp)
{
	t_data	pipex;

	if (ac != 5)
		error(&pipex, 0);
	if (pipe(pipex.pipe_fd) == -1)
		error(&pipex, 5);
	parse_data(&pipex, av, envp);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		process_first_child(pipex, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		process_second_child(pipex, envp);
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_all(&pipex);
	return (0);
}
