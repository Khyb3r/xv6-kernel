#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "pstat.h"
#include "param.h"
#include "stddef.h"

int main(void)
{
    int *p = (int *)0x0;
    printf(1, "p points to %d\n", *p);
    exit();
}
