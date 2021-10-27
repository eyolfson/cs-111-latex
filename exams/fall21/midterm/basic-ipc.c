#include <sys/wait.h>
#include <unistd.h>

int main() {
  int fd[2];
  pipe(fd);

  pid_t pid = fork();
  if (pid == 0) {
    /* first child */
    dup2(fd[1], 1);
    close(fd[1]);
    execlp("ls", "ls", NULL);
  }

  pid = fork();
  if (pid == 0) {
    /* second child */
    dup2(fd[0], 0);
    close(fd[0]);
    execlp("wc", "wc", NULL);
  }
  else {
    close(fd[0]);
    close(fd[1]);
    int wstatus;
    wait(&wstatus);
    wait(&wstatus);
  }

  return 0;
}
