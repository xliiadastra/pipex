/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:39:47 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/14 00:15:59 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char **envp)
{
	int	infile;
	int	outfile;
	int	i;

	i = 1;
	if (argc < 5)
		ft_error(BAG);
	if (!ft_strncmp(argv[1], "here_doc", 8) && ++i)
	{
		outfile = open_frame(argv[argc - 1], APPEND);
		infile = open_frame("infile_temp", WRITE);
		here_doc(infile, argv[2], argc);
	}
	else
		infile = open_frame(argv[1], READ);
	dup_frame(infile, STDIN_FILENO);
	if (ft_strncmp(argv[1], "here_doc", 8))
		outfile = open_frame(argv[argc - 1], WRITE);
	while (++i <= argc - 2)
		fork_frame(argv[i], envp, argc, i, outfile);
	while (--i > 1)
		waitpid(-1, 0, 0);
//	if (!access("infile_temp", F_OK))
//		unlink("infile_temp");
	return (0);
}
