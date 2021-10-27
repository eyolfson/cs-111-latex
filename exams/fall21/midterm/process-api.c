#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid1 = fork();
  pid_t pid2 = fork();

  if (pid1 > 0) {
    int wstatus;
    wait(&wstatus);
  }

  if (pid2 > 0) {
    int wstatus;
    wait(&wstatus);
  }

  return 0;
}
