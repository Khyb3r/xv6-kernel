#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


void threadTest(void *arg1, void *arg2) {
  printf(1, "Thread starting\n");
  printf(1, "Thread about to exit\n");
  exit();
}

int main() {
  printf(1, "Main starting\n");
  int thread = thread_create(threadTest, (void *)50, (void *)40);
  printf(1, "Created thread %d\n", thread);
  int joined = thread_join();
  printf(1, "Joined thread %d\n", joined);
  printf(1, "Main exiting\n");
  exit();
}
