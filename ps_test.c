#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "pstat.h"
#include "param.h"
#include "stddef.h"

int main(int argc, char *argv[]) {
    struct pstat *pstat = malloc(sizeof(struct pstat));
    if (pstat == NULL) {
        exit();
    }
    if (getpinfo(pstat) < 0) {
      printf(0, "Error with getpinfo");
      exit();
    }
    // User dashboard
    int i = 0;
    while (i < NPROC) {
      // if process is in use write to dashboard
      if (pstat->inuse[i]) {
          printf(1, "PID: %d    IN USE: %d    TICKETS: %d    TICKS: %d\n" ,
           pstat->pid[i], pstat->inuse[i], pstat->tickets[i], pstat->ticks[i]);
      }
      i++;
    }
    free(pstat);
    exit();
}
