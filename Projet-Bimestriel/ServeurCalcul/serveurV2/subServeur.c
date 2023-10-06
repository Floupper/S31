#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int arg1 = atoi(argv[1]);
    int arg2 = atoi(argv[2]);
    int result = arg1 - arg2;
    int flag = atoi(argv[3]);

    printf("--> Résultat | %d | %d | %d | %d | %d | %d |\n", 2, arg1, arg2, result, 0, flag);

    return 0;
}
