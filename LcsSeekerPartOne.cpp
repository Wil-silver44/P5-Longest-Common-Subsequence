#include "LcsSeekerPartOne.hpp"

//header comment goes here

LcsSeekerPartOne::LcsSeekerPartOne()
{

}

int LcsSeekerPartOne::Lcs(string xString, string yString, int m, int n)
{
    int c[m + 1][n + 1];
    int i, j;
  
    for (i = 0; i <= m; i++) 
    {
        for (j = 0; j <= n; j++) 
        {
            if (i == 0 || j == 0)
            {
                c[i][j] = 0;
            }
            else if (xString.at(i - 1) == yString.at(j - 1))
            {
                c[i][j] = c[i - 1][j - 1] + 1;
            }
            else
            {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }

    return c[m][n];
}
void LcsSeekerPartOne::printLcs()
{

}
