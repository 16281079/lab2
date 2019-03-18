#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
pid_t p1, p2, p3, p4, p5;
int cnt = 0;
while ((p2 = fork()) == -1);   //防止进程创建失败
/*p2progress*/
if (p2 == 0)			
{
int a[5];
p4 = fork();
if (p4 == 0)
{
while (1)
{
printf("p4's pid is %d,and this is parent's pid %d\n", getpid(), getppid());
}
}
else {
p5 = fork();
if (p5 == 0)
{
while (1)
{
printf("p5's pid is %d,and this is parent's pid %d\n", getpid(), getppid());
}
}
}
while (1)
{
printf("p2's pid is %d,and this is parent's pid %d\n", getpid(), getppid());
}
}
else
{
p3 = fork();
if (p3 == 0)
{
while (1)
{
printf("p3's pid is %d,and this is parent's pid %d\n", getpid(), getppid());
}
}
}
while (1)
{
printf("p1's pid is %d,and this is parent's pid %d\n", getpid(), getppid());
}
}

