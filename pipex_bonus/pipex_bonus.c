#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	int	infile;
	int	outfile;
	int	i;

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
}
