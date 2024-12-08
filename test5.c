
#include <stdio.h>
#include </usr/include/lib.h>
#include </usr/include/minix/callnr.h>
#include <stdlib.h>

int main(int args, char * argv[])
{ 
  /* proccesses with groups 1,2 and 3 will be created one after another in a loop  */
  message m;
  pid_t pid;
  int result;
  int i = 0;
  int j = 0;
  int k = 0;
  printf("Starting test 5...\n");
  for (k = 0; k < 5; k++)
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
        sleep(1);
        for(j=0;j<100000000; j++);
        exit(0);
      }
    }
  }
  printf("Finished test 5...\n");
  return 0;
}
