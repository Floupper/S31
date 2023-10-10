#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>

int glob = 3;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static void *tache(void *argA)
{
    // Attendre le signal SIGUSR1
    int sig;
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    sigwait(&set, &sig);

    glob++;
    printf("argA : (%s) glob : %d\n", (char *)argA, glob);
    // Affichage des informations sur le thread
    printf("argA : (%s) pthread_pid : %d pid : %d \n", (char *)argA, (int)pthread_self(), getpid());
    return NULL;
}

int main(int argc, char *argv[])
{
    // Bloquer le signal SIGUSR1 pour le processus principal
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    pthread_sigmask(SIG_BLOCK, &set, NULL);

    pthread_t ta = 0, tb = 0;

    // Attendre le signal SIGUSR1 avant d'envoyer les signaux aux threads
    sigwait(&set, NULL);

    pthread_create(&ta, NULL, tache, (void *)"A");
    pthread_create(&tb, NULL, tache, (void *)"B");

    // Envoyer le signal SIGUSR1 aux threads
    pthread_kill(ta, SIGUSR1);
    pthread_kill(tb, SIGUSR1);

    pthread_join(ta, NULL);
    pthread_join(tb, NULL);

    glob++;
    printf("Pere (%d) glob: %d \n", getpid(), glob);
}