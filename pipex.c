/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:24:08 by mdaifi            #+#    #+#             */
/*   Updated: 2021/06/27 18:17:39 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char *env[])
{
	char	**tmp;
	char	**tmp2;
	t_list	*pipe1;
	int		p[2];

	if (argc == 5)
	{
		tmp = ft_split(argv[2], ' ');
		pipe1 = ft_lstnew(tmp);
		tmp2 = ft_split(argv[3], ' ');
		ft_lstadd_back(&pipe1, ft_lstnew(tmp2));
		file_does_not_exist(argv[1]);
		fd_error(pipe(p));
		execute_second_cmd(pipe1, env, argv, p);
	}
	else
		write(1, "Invalid number of arguments !\n", 31);
	ft_free(tmp);
	ft_free(tmp2);
	ft_free_list(pipe1);
	return (0);
}
