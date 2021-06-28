/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:24:29 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/27 18:00:49 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

char	*search_path_of_cmd(char *str, char *env);
void	execute_second_cmd(t_list *pipe1, char **env, char **argv, int *p);
void	execute_first_cmd(char **tab, char **env, int *p, int fd);
void	check_permissions(char *file, char *permission);
void	file_does_not_exist(char *str);
void	ft_free_list(t_list *list);
void	ft_free(char **tab);
void	fd_error(int fd);

#endif