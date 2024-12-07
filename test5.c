
#include <stdio.h>
#include </usr/include/lib.h>
#include </usr/include/minix/callnr.h>
#include <stdlib.h>

int main(int args, char * argv[])
{ 
  /* first process with group 1 will be created, then 2's each with higher age so 
   * each created process will be put at the start of the queue as it is the oldest*/
  message m;
  pid_t pid;
  int result;
  int i = 0;
  int j = 0;
  int k = 0;
  printf("Starting test 5...\n");
  for (k = 0; k<5; k++)
  {
    for (i = 1; i < 4; i++)
    {
    pid = fork();
    if (pid == 0)
    {
      m.m1_i1 = getpid();
      m.m1_i2 = i;
      m.m1_i3 = k;
      result = _syscall(MM, SETPRI, &m);
      for(j=0;j<100000000; j++);
      return 0;
    }
  }
  }
  printf("Finished test 5...\n");
  return 0;
}
