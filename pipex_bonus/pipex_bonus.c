#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	int	infile;
	int	outfile;
	int	i;

	i = 1;
	if (argc < 5)
		ft_error(ERR);
	if (!ft_strncmp(av[1], "here_doc", 8) && ++i)
	{
		outfile = open_file(argv[argc - 1], APPEND);
		infile = open_file("pipex_temp", WRITE);
		here_doc(infile, argv[2], argc);
	}
	else
		infile = open_file(argv[1], READ);
	while (argv[++i] <= argc - 2)
		fork_frame(argv[i], envp);
	dup_frame(infile, STDIN_FILENO);
	while (--i > 1)
		waitpie(-1, 0, 0);
	dup_fram(outfile, STDOUT_FILENO);
}
