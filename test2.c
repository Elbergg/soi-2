
#include <stdio.h>
#include </usr/include/lib.h>
#include </usr/include/minix/callnr.h>
#include <stdlib.h>

int main(int args, char * argv[])
{ 
  message m;
  pid_t pid;
  pid_t pid2;
  int result;
  int i = 0;
  int j = 0;
  m.m1_i1 = getpid();
  m.m1_i2 = 2;
  m.m1_i3 = 3;
  result = _syscall(MM, SETPRI, &m);
  m.m1_i1 = getpid();
  result = _syscall(MM, GETPRI, &m);
  printf("m.m1_i1 = %d\n", m.m1_i1);
  printf("m.m1_i2 = %d\n", m.m1_i2);
  for (j = 0; j<100000000;j++);
  return 0;
}
