#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "pstat.h"


int main(int argc, char *argv[]) {
    struct pstat *pstat = malloc(sizeof(struct pstat));
    if (pstat == NULL) {
        free(pstat);
    }
    if (getpinfo(pstat) < 0) {
      printf(0, "Error with getpinfo");
      exit();
    }
    // User dashboard
    int i = 0;
    while (i < 64) {
      printf(4, "PID: %d    IN USE: %d    TICKETS: %d    TICKS: %d" ,
             pstat->pid[i], pstat->inuse[i], pstat->tickets[i], pstat->ticks[i]);
      i++;
    }
}
