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

void LcsSeekerPartOne::Lcs()
{
    
    int i, j;
  
    for (i = 0; i <= this->m; ++i) 
    {
        for (j = 0; j <= this->n; ++j) 
        {
            if (i == 0 || j == 0)
            {
                this->lcsTable[i][j] = 0;
            }
            else if (this->firstString.at(i - 1) == this->secondString.at(j - 1))
            {
                this->lcsTable[i][j] = this->lcsTable[i - 1][j - 1] + 1;
            }
            else
            {
                this->lcsTable[i][j] = max(this->lcsTable[i - 1][j], this->lcsTable[i][j - 1]);
            }
        }
    }

}

void LcsSeekerPartOne::printLcs()
{
    cout << "The Lcs of the strings" << endl;
    cout << this->firstString << endl;
    cout << "and" << endl;
    cout << this->secondString << endl;
}

int LcsSeekerPartOne::GetLcs()
{ return this->lcsTable[this->m][this->n]; }

string LcsSeekerPartOne::GetStringOne()
{ return this->firstString; }

string LcsSeekerPartOne::GetStringTwo()
{ return this->secondString;}

LcsSeekerPartOne::~LcsSeekerPartOne()
{
    for(int i = 0; i < (m + 1); ++i)
    {
        delete this->lcsTable[i];
    }

    delete this->lcsTable;
}
