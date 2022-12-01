#include "LcsSeekerPartOne.hpp"

//header comment goes here


LcsSeekerPartOne::LcsSeekerPartOne()
{
    this->reader.open(FILE_NAME);
    if(reader.is_open())
    {
        getline(this->reader, this->firstString);
        getline(this->reader, this->secondString);
    }
    else
    {
        throw "error opening file";
    }
    this->reader.close();

    this->m = this->firstString.length();
    this->n = this->secondString.length();

    //dynamically create matrix using string lengths.
    this->lcsTable = new int*[this->m + 1];
    for(int i = 0; i < (m + 1); ++i)
    {
        this->lcsTable[i] = new int[this->n + 1];
    }
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
    cout << "The Lcs of the strings" << endl;
    cout << this->firstString << endl;
    cout << "and" << endl;
    cout << this->secondString << endl;
}

LcsSeekerPartOne::~LcsSeekerPartOne()
{
    for(int i = 0; i < (m + 1); ++i)
    {
        delete this->lcsTable[i];
    }

    delete this->lcsTable;
}
