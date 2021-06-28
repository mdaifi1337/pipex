/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:03:32 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/27 18:00:42 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fd_error(int fd)
{
	if (fd == -1)
	{
		perror("");
		exit(1);
	}
}

void	file_does_not_exist(char *file)
{
	if (access(file, F_OK))
	{
		perror("");
		exit(1);
	}
}

void	check_permissions(char *file, char *permission)
{
	if (!ft_strncmp(permission, "read", 5))
	{
		if (access(file, R_OK))
		{
			perror("");
			exit(1);
		}
	}
	else if (!ft_strncmp(permission, "write", 6))
	{
		if (access(file, W_OK))
		{
			perror("");
			exit(1);
		}
	}
}
