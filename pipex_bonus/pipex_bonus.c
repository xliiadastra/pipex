#include "pipex_bonus.h"

int	main(int argc, char *argv[], char **envp)
{
	int	infile;
	int	outfile;
	int	i;

	i = 1;
	if (argc < 5)
		ft_error(ERR);
	//if (!ft_strncmp(argv[1], "here_doc", 8) && ++i)
	//{
	//	outfile = open_fream(argv[argc - 1], APPEND);
	//	infile = open_fream("pipex_temp", WRITE);
	//	here_doc(infile, argv[2], argc);
	//}
	//else
	infile = open_frame(argv[1], READ);
	dup_frame(infile, STDIN_FILENO);
	
	outfile = open_frame(argv[argc - 1], WRITE);
	//dup_frame(outfile, STDOUT_FILENO);
	while (++i <= argc - 2)
		fork_frame(argv[i], envp, argc, i, outfile);
	while (--i > 1)
		waitpid(-1, 0, 0);
	
	return (0);
}
