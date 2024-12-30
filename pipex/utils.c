/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:59:16 by ssalorin          #+#    #+#             */
/*   Updated: 2024/10/09 12:31:34 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_find_path2(char **paths, char *full_path, char *cmd)
{
	int		i;
	char	*temp_path;
	char	*new_full_path;

	i = 0;
	temp_path = NULL;
	new_full_path = NULL;
	while (paths[i])
	{
		temp_path = ft_strjoin(paths[i], "/");
		if (!temp_path)
		{
			free(full_path);
			return (NULL);
		}
		new_full_path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (access(new_full_path, X_OK) == 0)
			return (new_full_path);
		free(new_full_path);
		i++;
	}
	return (NULL);
}

static char	*ft_find_path(char **envp, char **cmds)
{
	int		i;
	char	*path_var;
	char	**paths;
	char	*full_path;

	i = 0;
	full_path = NULL;
	if (cmds[0][0] == '/')
	{
		if (access(cmds[0], F_OK) == 0 && access(cmds[0], X_OK) == 0)
			execve(cmds[0], cmds, envp);
	}
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
	{
		ft_print_err(cmds[0], 2);
		ft_free_array(cmds);
		exit(127);
	}
	path_var = envp[i] + 5;
	paths = ft_split(path_var, ':');
	full_path = ft_find_path2(paths, full_path, cmds[0]);
	ft_free_array(paths);
	return (full_path);
}

static void	ft_check_dir(char *cmd)
{
	int		len;
	char	*err_msg;
	char	*err_out;
	char	*err_temp;

	err_msg = "./pipex: ";
	len = ft_strlen(cmd) - 1;
	if (cmd[0] == '.' && cmd[len] == '/')
	{
		err_out = ft_strjoin(err_msg, cmd);
		err_temp = ft_strjoin(err_out, ": Is a directory\n");
		free(err_out);
		ft_putstr_fd(err_temp, STDERR_FILENO);
		free(err_temp);
		exit(126);
	}
}

static void	ft_if_not_path(char **cmds)
{
	int	x;

	x = 0;
	ft_check_dir(cmds[0]);
	ft_print_err(cmds[0], 0);
	if (cmds[0][0] == '.')
		x = 1;
	ft_free_array(cmds);
	if (x == 1)
		exit(126);
	exit(127);
}

void	ft_command(char **envp, char *cmd)
{
	char	**cmds;
	char	*path;

	if (cmd[0] == '\0' || cmd[0] == ' ')
	{
		ft_print_err(cmd, 0);
		exit(127);
	}
	cmds = ft_split(cmd, ' ');
	if (!cmds)
		exit(EXIT_FAILURE);
	path = ft_find_path(envp, cmds);
	if (!path)
		ft_if_not_path(cmds);
	execve(path, cmds, envp);
	free(path);
	ft_free_array(cmds);
	exit(EXIT_FAILURE);
}
