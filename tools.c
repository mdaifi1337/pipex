/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 14:12:32 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/27 17:22:10 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*search_path_of_cmd(char *str, char *env)
{
	char	**path;
	char	*tmp;
	int		i;

	path = ft_split(env, ':');
	path[0] = ft_strchr(path[0], '/');
	i = -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], str);
		if (!access(tmp, F_OK))
			return (tmp);
		free(tmp);
	}
	return (NULL);
}

void	ft_free(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	ft_free_list(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
