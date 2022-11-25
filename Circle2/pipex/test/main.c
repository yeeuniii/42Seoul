/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:51:20 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/22 20:45:07 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	BUFSIZE = 25;

int main(void)
{
    int fd1[2];
    int fd2[2];
    char buffer[BUFSIZE];
    pid_t pid;

    if(pipe(fd1) == -1 || pipe(fd2) == -1)
    {
        printf("pipe error");
        exit(1);
    }

//	write(fd1[1], "write fd1\n", BUFSIZE);
//	read(fd1[0], buffer, BUFSIZE);
//	printf("%s\n", buffer);

    pid = fork();

    if (pid == -1)
    {
        printf("fork() error");
        exit(1);
    }
    if (pid == 0)
    {
	//	close(fd1[0]);
        write(fd1[1], "(자식에서 입력)\n", BUFSIZE);
        read(fd2[0], buffer, BUFSIZE);
        printf("\n자식출력: %s\n", buffer);

    }
    else
    {
	//	close(fd1[1]);
       write(fd2[1], "(부모에서 입력)", BUFSIZE);
        read(fd1[0], buffer, BUFSIZE);
        printf("\n부모출력: %s\n", buffer);
    }
    return (0);
}
