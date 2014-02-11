#include <stdio.h>
#include "boatsailOps.h"

int main()
{
    BoatList bl = { {1, "aa", 1},
                    {2, "bb", 3},
                    {3, "cc", 2},
                    {4, "dd", 2}
                  };
    SailorList sl = { {1, "aa1", 1, 1},
                    {2, "b2b", 3, 2},
                    {4, "c3c", 12, 3},
                    {3, "d4d", 8, 4}
                  };

    PrintDetails(sl, 4, bl, 4);

    printf("\n Sorting ... ");
    sortSailors(sl, 4, bl, 4);
    printf("\n");
    PrintDetails(sl, 4, bl, 4);
    printf("\n");

}
