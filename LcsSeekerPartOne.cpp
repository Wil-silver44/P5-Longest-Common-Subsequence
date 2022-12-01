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
    
    int i; 
    int j;
  
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
    int index = GetLcs();

    // Create a character array to store the lcs string
    char lcs[index + 1];

    // Set the terminating character at the end, which we know is at the index value thanks to the Lcs function
    lcs[index] = '\0'; 
 
    // Start from the right-most-bottom-most corner and store characters one by one in lcs[], building the string back to front
    int i = this->m;
    int j = this->n;

    while ((i > 0) && (j > 0)) 
    {
        //If current character in the strings are same, then it is part of LCS
        if (this->firstString.at(i - 1) == this->secondString.at(j - 1)) 
        {
            lcs[index - 1] = this->firstString.at(i - 1); // adds current character in result
            i--;
            j--;
            index--; // decrements values
        }
 
        // If not, then find the larger of two and
        // go in the direction of larger value
        else if (this->lcsTable[i - 1][j] > this->lcsTable[i][j - 1])
            i--;
        else
            j--;
    }

    cout << "lcs of strings" << endl << endl;
    cout << GetStringOne() << "\n\nand\n\n" << GetStringTwo()
    << "\n\nis " << lcs << endl;
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
