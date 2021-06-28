/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:21:27 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/27 18:01:52 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_first_cmd(char **tab, char **env, int *p, int fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd, 0);
		dup2(p[1], 1);
		dup2(p[1], 2);
		if (execve(tab[0], tab, env) < 0)
		{
			perror("");
			exit(1);
		}
		exit(0);
	}
}

static int	open_files_and_check_errors(char *file1, char *file2, int *fd2)
{
	int	fd;

	fd = open(file1, O_WRONLY | O_CREAT | O_TRUNC, 0755);
	check_permissions(file1, "write");
	*fd2 = open(file2, O_RDONLY);
	check_permissions(file2, "read");
	fd_error(fd);
	fd_error(*fd2);
	return (fd);
}

void	execute_second_cmd(t_list *pipe1, char **env, char **argv, int *p)
{
	char	**tab;
	int		fd;
	int		fd2;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		fd = open_files_and_check_errors(argv[4], argv[1], &fd2);
		tab = (char **)pipe1->content;
		tab[0] = search_path_of_cmd(tab[0], env[6]);
		execute_first_cmd(tab, env, p, fd2);
		ft_free(tab);
		tab = (char **)pipe1->next->content;
		tab[0] = search_path_of_cmd(tab[0], env[6]);
		close(p[1]);
		dup2(p[0], 0);
		close(p[0]);
		dup2(fd, 1);
		if (execve(tab[0], tab, NULL) < 0)
		{
			perror("");
			exit(1);
		}
	}
}
