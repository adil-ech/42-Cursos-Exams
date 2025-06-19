/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 04:01:31 by adechaji          #+#    #+#             */
/*   Updated: 2025/06/19 04:30:16 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void err(char *str)
{
    while (*str)
        write(2, str++, 1);
}

int cd(char **av, int i)
{
    if (i != 2)
        return err("error: cd: bad arguments\n"), 1;
    if (chdir(av[1]) < 0)
        return err("error: cd: cannot change directory to "), err(*av), err("\n"), 1;
    return 0;
}

void set_pipe(int has_pipe, int *fd, int end)
{
    if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        err("error: fatal\n"), exit(1);
}

int exec(char **av, int i, char **envp)
{
    int has_pipe, fd[2], pid, status;

    has_pipe = av[i] && !strcmp(av[i], "|");
    if (!has_pipe && !strcmp(*av, "cd"))
        return cd(av, i);
    if (has_pipe && pipe(fd) == -1)
        err("error: fatal\n"), exit(1);
    if ((pid = fork()) == -1)
        err("error: fatal\n"), exit(1);
    if (!pid)
    {
        av[i] = 0;
        set_pipe(has_pipe, fd, 1);
        execve(*av, av, envp);
        err("error: cannot execute "), err(*av), err("\n"), exit(1);
    }
    waitpid(pid, &status, 0);
    set_pipe(has_pipe, fd, 0);
    return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int ac, char **av, char **envp)
{
    (void)ac;
    int i = 0, status = 0;

    while (av[i])
    {
        av += i + 1;
        i = 0;
        while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
            i++;
        if (i)
            status = exec(av, i, envp);
    }
    return status;
}