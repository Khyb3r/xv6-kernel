#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "pstat.h"
#include "param.h"
#include "stddef.h"

int main(void)
{
  printf(1, "Overwrite memory test\n");
  char *p = (char *)&main;
  printf(1, "munprotect test: \n");
  munprotect((void *)p , 3);
  printf(1, "first 3 bytes of main before: %d, %d, %d\n", p[0], p[250], p[300]);
  p[250] = 0xCC;
  p[300] = 0xCC;
  printf(1,"first 3 bytes of main after: %d, %d, %d\n", p[0], p[250], p[300]);
  printf(1, "mprotect test: \n");
  mprotect((void *)p, 3);
  printf(1, "first 3 bytes of main before: %d, %d, %d\n", p[0], p[250], p[300]);
  p[250] = 10;
  p[300] = 15;
  printf(1,"first 3 bytes of main after: %d, %d, %d\n", p[0], p[250], p[300]);
  p[250] = 0xCC;
  exit();
}

