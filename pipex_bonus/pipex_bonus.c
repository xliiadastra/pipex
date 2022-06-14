/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:39:47 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/14 18:05:34 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	delete_temp(void)
{
	if (!access("infile_temp", F_OK))
		unlink("infile_temp");
}

void	bad_argc(int argv)
{
	if (argc < 5)
		ft_error(BAG);
}

void	get_process(char *argv[], char **envp, int outfile, int i)
{
	int	count;

	count = 0;
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
	int	i;
	int	count;

	i = 1;
	count = 0;
	bad_argc(argc);
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
	get_process(argv, envp, outfile, i);
	delete_temp(void);
	return (0);
}
