#include <stdio.h>
#include </usr/include/lib.h>
#include </usr/include/minix/callnr.h>
#include <stdlib.h>

int main(int args, char * argv[])
{ 
  /* first process with group 1 will be created, then 3's each with different execution time */ 
  message m;
  pid_t pid;
  int result;
  int i = 0;
  int j = 0;
  printf("Starting test 4...\n");
  m.m1_i1 = getpid();
  m.m1_i2 = 1;
  m.m1_i3 = 0;
  result = _syscall(MM, SETPRI, &m);
  for (i = 0; i < 5; i++)
  {
    pid = fork();
    if (pid == 0)
    {
      for (j=0; j< 100000000; j++);
      return;
    }
  }
  m.m1_i1 = getpid();
  m.m1_i2 = 3;
  m.m1_i3 = 0;
  _syscall(MM, SETPRI, &m);
  i = 0;
  j = 0;
  for (i = 0; i < 5; i++)
  {
    pid = fork();
    if (pid == 0)
    {

      m.m1_i1 = getpid();
      m.m1_i2 = 3;
      m.m1_i3= i;
      _syscall(MM, SETPRI, &m);
      for (j=0;j<100000000;j++);
      return 0;
    }
  }
  printf("Finished test 4...\n");
  return 0;
}
