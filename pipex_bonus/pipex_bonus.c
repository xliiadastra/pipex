/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:39:47 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/14 19:47:38 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	bad_argc(int argc)
{
	if (argc < 5)
		ft_error(BAG);
}

void	get_process(int argc, char *argv[], char **envp, int outfile)
{
	int	count;
	int	i;

	count = 0;
	if (!ft_strncmp(argv[1], "here_doc", 8))
		i = 2;
	else
		i = 1;
	while ((++i <= argc - 2) && ++count)
	{
		if (i == argc - 2)
			fork_frame(argv[i], envp, outfile, END);
		else
			fork_frame(argv[i], envp, outfile, CONTINUE);
	}
	while (--count >= 0)
		waitpid(-1, 0, 0);
}

int	main(int argc, char *argv[], char **envp)
{
	int	infile;
	int	outfile;

	bad_argc(argc);
	if (!ft_strncmp(argv[1], "here_doc", 8))
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
	get_process(argc, argv, envp, outfile);
	if (!access("infile_temp", F_OK))
		unlink("infile_temp");
	return (0);
}
