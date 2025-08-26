#include <stddef.h>

#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "pstat.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// allows user to manually set tickets in the lottery scheduler
// returns 0 if successful, -1 if otherwise
int
sys_settickets(void) {
  int tickets_number;
  struct proc *curr_p = myproc();
  if (argint(0, &tickets_number) < 0 || tickets_number < 1) {
    return -1;
  }
  curr_p->tickets = tickets_number;
  return 0;
}

// returns some information about all running processes
// returns 0 if successful, -1 if otherwise
int
sys_getpinfo(void) {
  struct pstat *pstat;
  if ((argptr(0, (char **)&pstat, sizeof(*pstat)) < 0) || pstat == NULL) {
    return -1;
  }
  return ps(pstat);
}


// change region of code to read only
int
sys_mprotect(void) {
  void *addr;
  int length;
  // fetch arguments from user stack
  if (argptr(0, (char **)&addr, sizeof(void*)) < 0 || addr == NULL) {
    return -1;
  }
  if (argint(1, &length) < 0) {
    return -1;
  }

  return mprotect(addr, length);
}

// change region of code to read only
int
sys_munprotect(void) {
  void *addr;
  int length;
  // fetch arguments from user stack
  if (argptr(0, (char **)&addr, sizeof(void*)) < 0 || addr == NULL) {
    return -1;
  }
  if (argint(1, &length) < 0) {
    return -1;
  }
  return mprotect(addr, length);
}