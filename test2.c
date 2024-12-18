
#include <stdio.h>
#include </usr/include/lib.h>
#include </usr/include/minix/callnr.h>
#include <stdlib.h>

int main(int args, char * argv[])
{ 
  /* first process with group 1 will be created, then 2's each with different ages */
  message m;
  pid_t pid;
  int result;
  int i = 0;
  int j = 0;
  printf("Starting test 2...\n");
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
      return 0;
    }
  }
  m.m1_i1 = getpid();
  m.m1_i2 = 2;
  m.m1_i3 = 100;
  _syscall(MM, SETPRI, &m);
  for (i = 0; i < 5; i++)
  {
    pid = fork();
    if (pid == 0)
    {
      m.m1_i1 = getpid();
      m.m1_i2 = 2;
      m.m1_i3= 6-i;
      _syscall(MM, SETPRI, &m);
      for (j=0;j<100000000;j++);
      return 0;
    }
  }
  printf("Finished test 2...\n");
  return 0;
}
