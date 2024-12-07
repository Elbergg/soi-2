#include <stdio.h>
#include </usr/include/lib.h>
#include </usr/include/minix/callnr.h>
#include <stdlib.h>

int main(int args, char * argv[])
{
  /* the most general test, firtly processes of group 1 will be created, then 2, then 3, so they should be executed in order 1->2->3, and each according with their scheduling arguments*/
  message m;
  int result;
  int i = 0;
  int j = 0;
  int n = 0;
  pid_t pid;
  m.m1_i1 = getpid();
  m.m1_i2 = 1;
  m.m1_i3 = 0;
  result = _syscall(MM, SETPRI, &m);
  for (n = 0; n < 5; n++)
  {
    m.m1_i1 = getpid();
    m.m1_i2 = 1;
    m.m1_i3 = 0;
    _syscall(MM, SETPRI, &m);
    pid = fork();
    if (pid == 0)
    {
      _syscall(MM, SETPRI, &m);
      for (j = 0; j<100000000; j++);
      return 0;
    }
  }
  m.m1_i1 = getpid();
  m.m1_i2 = 2;
  m.m1_i3 = 3;
  _syscall(MM, SETPRI, &m);
  for (i = 0; i < 5; i++)
  {
    pid = fork();
    if (pid == 0)
    {
      m.m1_i1 = getpid();
      m.m1_i2 = 2;
      m.m1_i3 = i;
      _syscall(MM, SETPRI, &m);
      for (j = 0; j < 100000000; j++);
      return 0;
    }
  }
  m.m1_i1 = getpid();
  m.m1_i2 = 3;
  m.m1_i3 = 0;
  _syscall(MM, SETPRI, &m);
  for(i = 0; i < 5; i++)
  {
    pid = fork();
    if (pid == 0)
    {
      m.m1_i1 = getpid();
      m.m1_i2 = 3;
      m.m1_i3 = 7-i;
      _syscall(MM, SETPRI, &m);
      for(j = 0; j<100000000; j++);
      return 0;
    }
  }
  return 0;
}

