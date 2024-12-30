/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:58:27 by ssalorin          #+#    #+#             */
/*   Updated: 2024/10/09 14:56:26 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_from_pipe(int file2, int *end, char **envp, char *cmd)
{
	if (dup2(end[0], STDIN_FILENO) == -1)
	{
		close(end[0]);
		close(end[1]);
		exit(1);
	}
	if (dup2(file2, STDOUT_FILENO) == -1)
	{
		close(file2);
		close(end[0]);
		close(end[1]);
		exit(1);
	}
	close(end[1]);
	close(end[0]);
	close(file2);
	ft_command(envp, cmd);
}

static void	ft_to_pipe(int file1, int *end, char **envp, char *cmd)
{
	if (dup2(file1, STDIN_FILENO) == -1)
	{
		close(file1);
		exit(1);
	}
	if (dup2(end[1], STDOUT_FILENO) == -1)
	{
		close(file1);
		close(end[1]);
		exit(1);
	}
	close(end[0]);
	close(end[1]);
	close(file1);
	ft_command(envp, cmd);
}

static void	ft_pipe(char **argv, char **envp, int file1, int file2)
{
	int		end[2];
	pid_t	pid;

	if (pipe(end) == -1)
		exit(1);
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
		ft_to_pipe(file1, end, envp, argv[2]);
	else
	{
		waitpid(pid, NULL, 0);
		ft_from_pipe(file2, end, envp, argv[3]);
	}
}

static void	ft_check_access(char *checking, int c, int file1)
{
	if (c == 1)
	{
		if (access(checking, F_OK) == -1)
		{
			ft_printf("./pipex: %s: No such file or directory\n", checking);
			exit(0);
		}
		if (access(checking, R_OK) == -1)
		{
			ft_printf("./pipex: %s: Permission denied\n", checking);
			exit(0);
		}
	}
	else
	{
		if (access(checking, W_OK) == -1)
		{
			ft_printf("./pipex: %s: Permission denied\n", checking);
			close(file1);
			exit(1);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	file1;
	int	file2;

	if (argc != 5)
	{
		ft_printf("%s\n", "Usage: ./pipex file1 cmd1 cmd2 file2");
		exit(1);
	}
	ft_check_access(argv[1], 1, 0);
	file1 = open(argv[1], O_RDONLY);
	if (file1 < 0)
		exit(1);
	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_check_access(argv[4], 0, file1);
	if (file2 < 0)
	{
		close(file1);
		exit(1);
	}
	ft_pipe(argv, envp, file1, file2);
	return (0);
}
