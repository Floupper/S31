#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <pthread.h>

typedef int Instruction[6];
#define MaxI 10

typedef struct arg {
    Instruction OP;
    int fd[2];
} arg;

typedef struct threads {
    pthread_t *ids;
    int nb_thread;
} threads;

void fill_arg_with_op(arg *args, Instruction OP) {
    for (int i = 0; i < 6; i++) {
        args->OP[i] = OP[i];
    }
}

void *execute_instruction(void *args) {
    arg *thread_args = (arg *)args;
    Instruction OP;
    int fd[2];
    for (int i = 0; i < 6; i++) {
        OP[i] = thread_args->OP[i];
    }
    fd[0] = thread_args->fd[0];
    fd[1] = thread_args->fd[1];

     switch (OP[0])
        {
        case 1:
            OP[3] = OP[1] + OP[2];
            write(fd[1],&OP[3], sizeof(int));
            break;
        case 2:
            OP[3] = OP[1] - OP[2];
            write(fd[1],&OP[3], sizeof(int));
            break;
        case 3:
            OP[3] = OP[1] * OP[2];
            write(fd[1],&OP[3], sizeof(int));
            break;
        case 4:
            if (OP[2] != 0)
            OP[3] = OP[1] / OP[2];
            write(fd[1],&OP[3], sizeof(int));
            break;
        case 5:
            OP[3] = OP[1] / OP[2];
            write(fd[1],&OP[3], sizeof(int));
            OP[4] = OP[1] % OP[2];
            write(fd[1],&OP[4], sizeof(int));
            break;
        }

    return NULL;
}

int main() {
    threads all_threads;
    all_threads.ids = NULL;
    all_threads.nb_thread = 0;

    int i = 0;
    Instruction TPI[MaxI + 1];
    TPI[0][0] = 1; TPI[0][1] = 12; TPI[0][2] = 7; TPI[0][3] = 0; TPI[0][4] = 0; TPI[0][5] = 0;
    TPI[1][0] = 2; TPI[1][1] = 36; TPI[1][2] = 8; TPI[1][3] = 0; TPI[1][4] = 0; TPI[1][5] = 0;
    TPI[2][0] = 5; TPI[2][1] = 19; TPI[2][2] = 6; TPI[2][3] = 0; TPI[2][4] = 0; TPI[2][5] = 0;
    TPI[3][0] = -1;

    int fd[2];
    pipe(fd);

    while (TPI[i][0] != -1 && i < MaxI) {
        arg args;
        args.fd[0] = fd[0];
        args.fd[1] = fd[1];
        fill_arg_with_op(&args, TPI[i]);

        all_threads.nb_thread += 1;
        all_threads.ids = realloc(all_threads.ids, all_threads.nb_thread * sizeof(pthread_t));
          printf("A executer : | %d | %d | %d | %d | %d | %d |  ", TPI[i][0], TPI[i][1], TPI[i][2], TPI[i][3], TPI[i][4], TPI[i][5]);
        if (pthread_create(&all_threads.ids[all_threads.nb_thread - 1], NULL, execute_instruction, &args) != 0) {
            perror("Thread creation failed");
            return 1;
        }


        if (TPI[i][5] == 1){
            pthread_join(all_threads.ids[all_threads.nb_thread],NULL);
        }

        read(fd[0],&TPI[i][3],sizeof(int));

        if(TPI[i][0] == 5){
            read(fd[0],&TPI[i][4],sizeof(int));
        }
        usleep(100000);
        printf("--> Résultat | %d | %d | %d | %d | %d | %d |\n", TPI[i][0], TPI[i][1], TPI[i][2], TPI[i][3], TPI[i][4], TPI[i][5]);
        
        
        
        i++;
    }

    for (int j = 0; j < all_threads.nb_thread; j++) {
        pthread_join(all_threads.ids[j], NULL);
    }

    return 0;
}