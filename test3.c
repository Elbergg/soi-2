

#include <stdio.h>
#include </usr/include/lib.h>
#include </usr/include/minix/callnr.h>
#include <stdlib.h>

int main(int args, char * argv[])
{ 
  /* firstly proccess of group two will be created, then proccesses from group 1, which should be executed before the previously put group 2 process  */ 
  message m;
  pid_t pid;
  int result;
  int i = 0;
  int j = 0;
  printf("Starting test number 3...\n");
  m.m1_i1 = getpid();
  m.m1_i2 = 2;
  m.m1_i3 = 10;
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
  m.m1_i2 = 1;
  m.m1_i3 = 0;
  result = _syscall(MM, SETPRI, &m);
  for (i = 0; i< 5; i++)
  {

    pid = fork();
    if (pid == 0)
    {
      for (j=0; j< 100000000; j++);
      return 0;
    }
  }
  printf("Test 3 finished...\n");
  return 0;
}
