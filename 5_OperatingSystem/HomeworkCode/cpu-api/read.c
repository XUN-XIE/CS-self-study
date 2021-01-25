#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

void wait_or_die() {
    int rc = wait(NULL);
    assert(rc > 0);
}

int fork_or_die() {
    int rc = fork();
    assert(rc >= 0);
    return rc;
}

int main(int argc, char *argv[]) {
    // thread a
    if (fork_or_die() == 0) {
        sleep(10);
        // thread b
        exit(0);
    }
    if (fork_or_die() == 0) {
        sleep(3);
        // thread c
        exit(0);
    }
    if (fork_or_die() == 0) {
        sleep(4);
        // thread d
        exit(0);
    }
    if (fork_or_die() == 0) {
        sleep(2);
        // thread e
        if (fork_or_die() == 0) {
            sleep(1);
            // thread f
            exit(0);
        }
        wait_or_die();
        exit(0);
    }
    wait_or_die();
    wait_or_die();
    wait_or_die();
    wait_or_die();
    return 0;
}

