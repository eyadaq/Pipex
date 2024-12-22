
#include "../includes/pipex.h"

static char *find_path(char *cmd, char **envp)
{
    char *path;
    char *dir;
    char *bin;
    int i;

    i = 0;
    while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
        i++;
    if (!envp[i])
        return (cmd);
    path = envp[i] + 5;
    while (path && *path)
    {
        dir = ft_substr(path, 0, ft_strchr(path, ':') - path);
        bin = ft_strjoin(ft_strjoin(dir, "/"), cmd);
        free(dir);
        if (!access(bin, F_OK))
            return (bin);
        free(bin);
        path = ft_strchr(path, ':');
        if (path)
            path++;
    }
    return (cmd);
}

static void execute_cmd(char *cmd, char **envp)
{
    char **args;
    char *path;

    args = ft_split(cmd, ' ');
    if (!args)
        exit(1);
    path = find_path(args[0], envp);
    if (execve(path, args, envp) == -1)
    {
        ft_putstr_fd("Command not found: ", 2);
        ft_putstr_fd(args[0], 2);
        ft_putchar_fd('\n', 2);
        exit(127);
    }
}

static void child_process(int *pipe_fd, char **argv, char **envp)
{
    int infile;

    infile = open(argv[1], O_RDONLY);
    if (infile == -1)
    {
        perror("Error opening input file");
        exit(1);
    }
    dup2(infile, STDIN_FILENO);
    dup2(pipe_fd[1], STDOUT_FILENO);
    close(pipe_fd[0]);
    close(infile);
    execute_cmd(argv[2], envp);
}

static void parent_process(int *pipe_fd, char **argv, char **envp)
{
    int outfile;

    outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outfile == -1)
    {
        perror("Error opening output file");
        exit(1);
    }
    dup2(pipe_fd[0], STDIN_FILENO);
    dup2(outfile, STDOUT_FILENO);
    close(pipe_fd[1]);
    close(outfile);
    execute_cmd(argv[3], envp);
}

int main(int argc, char **argv, char **envp)
{
    int pipe_fd[2];
    int pid1;

    if (argc != 5)
    {
        ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
        return (1);
    }
    if (pipe(pipe_fd) == -1)
    {
        perror("Pipe failed");
        return (1);
    }
    pid1 = fork();
    if (pid1 == -1)
    {
        perror("Fork failed");
        return (1);
    }
    if (pid1 == 0)
        child_process(pipe_fd, argv, envp);
    parent_process(pipe_fd, argv, envp);
    return (0);
}