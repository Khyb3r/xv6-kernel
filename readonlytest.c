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
  printf(1, "first 3 bytes of main before: %d, %d, %d\n", p[0], p[1], p[2]);
  p[0] = 0xCC;
  p[1] = 0xCC;
  printf(1,"first 3 bytes of main before: %d, %d, %d\n", p[0], p[1], p[2]);
  exit();
}

