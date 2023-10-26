#include "myIncludes.h"

void calcule(int OP[])
{
    switch (OP[0])
    {
    case 1:
        OP[3] = OP[1] + OP[2];
        break;
    case 2:
        OP[3] = OP[1] - OP[2];
        break;
    case 3:
        OP[3] = OP[1] * OP[2];
        break;
    case 4:
        if (OP[2] != 0)
            OP[3] = OP[1] / (int)OP[2];
        break;
    case 5:
        OP[3] = OP[1] / OP[2];
        OP[4] = OP[1] % OP[2];
        break;
    }
}