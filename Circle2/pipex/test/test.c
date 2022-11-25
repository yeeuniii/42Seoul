#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
 
void	include_wait(pid_t pid)
{
	int	wait_res;
	int	status;
	
	if (pid == 0)
	{
	   	 printf("\n****자식프로세스****\n");
   		 sleep(2);
	    printf("자식프로세스 종료\n");
	}
	else
	{
   		wait_res = waitpid(pid, &status, 0);
		printf("\n****부모프로세스****\n");
	    sleep(1);
   		printf("부모프로세스 종료\n");
		 printf("wait인자값: %d\nwait반환값: %d\n", status, wait_res);
	    printf("자식pid: %d\n", pid);
	}
}

void	include_not_wait(pid_t pid)
{
	if (pid == 0)
	{
	   	 printf("\n****자식프로세스****\n");
   		 sleep(2);
	    printf("자식프로세스 종료\n");
	}
	else
	{
		printf("\n****부모프로세스****\n");
	    sleep(1);
   		printf("부모프로세스 종료\n");
	}

}

int main() {
     
    pid_t pid;
    pid_t pid1;
	int	fd[2];
    int x;
    x = 0;
	pid = fork();
    
	if(pid > 0) {  // 부모 코드
        x = 0;
		printf("부모 PID : %ld,  x : %d , pid : %d fd[0]: %d\n",(long)getpid(), x, pid, fd[0]);
    }
    else if(pid == 0){  // 자식 코드
        x = 1;
		printf("자식 PID : %ld,  x : %d, fd[0] : %d\n",(long)getpid(), x, fd[0]);
    }
    else {  // fork 실패
        printf("fork Fail! \n");
        return -1;
    }

	int	wait;

	wait =1; 
	if (wait)
		include_wait(pid);
	else
		include_not_wait(pid);
	printf("END\n");
}
