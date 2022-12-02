#include "LcsSeekerPartTwo.hpp"

//header comment goes here

LcsSeekerPartTwo::LcsSeekerPartTwo()
{
    //opens file and reads in strings, stores them in dynamically created array.
    this->reader.open(FILE_NAME);
    if(reader.is_open())
    {
        this->reader >> this->numStrings;
        this->list = new string[this->numStrings];

        for(int i = 0; i < this->numStrings; ++i)
        {
            getline(this->reader, this->list[i]);
        }

        this->reader.close();
    }
    else
    {
        throw "error opening file";
    }

    //creates the sim table.
    this->simTable = new char*[this->numStrings];
    for(int i = 0; i < this->numStrings; ++i)
    {
        this->simTable[i] = new char[this->numStrings];
    }

    //puts '-' in table portions that will not be viewed
    for(int i = 0; i < this->numStrings; ++i)
    {
        for(int j = 0; j < this->numStrings; ++j)
        {
            if( j <= i)
            {
                this->simTable[i][j] = '-';
            }
        }
    }

}

void LcsSeekerPartTwo::Run()
{
    for(int i = 0; i < this->numStrings; ++i)
    {
        for(int j = 1; j < this->numStrings; ++j)
        {
            this->simTable[i][j] = compareStrings(this->list[i], this->list[j]);
        }
    }

    printSimTable();
}

void LcsSeekerPartTwo::printSimTable()
{
    for(int i = 1; i <= this->numStrings; ++i)
    {
        cout << "0" << i << " "; 
    }
        cout << endl;
    for(int i = 0; i < this->numStrings; ++i)
    {
        cout << "0" << (i + 1) << " ";
        for(int j = 0; j < this->numStrings; ++j)
        {
            cout << this->simTable[i][j] << " ";
        }
        cout << endl;
    }
}

LcsSeekerPartTwo::~LcsSeekerPartTwo()
{
    for(int i = 0; i < this->numStrings; ++i)
    {
        delete this->simTable[i];
    }

    delete this->simTable;
    delete this->list;
}

char LcsSeekerPartTwo::compareStrings(string xString, string yString)
{
    LcsTool tempTool(xString, yString);
    tempTool.Lcs();
    double stringPercent;
    if(yString.length() > xString.length())
    {
        //check for high similarity-- difference within 10% of longer string and lcs 90% of shorter string
        if((xString.length() / (yString.length() * 1.0)) > (yString.length() * 0.90) && (tempTool.GetLcs() > (0.90 * xString.length())))
        {
            return 'H';
        }
        //check for medium similarity-- difference within 20% of longer string and lcs 80% of shorter string
        else if((xString.length() / (yString.length() * 1.0)) > (yString.length() * 0.20) && (tempTool.GetLcs() > (0.80 * xString.length())))
        {
            return 'M';
        }
        //check for low similarity-- difference within 40% of longer string and lcs 50% of shorter string
        else if((xString.length() / (yString.length() * 1.0)) > (yString.length() * 0.40) && (tempTool.GetLcs() > (0.80 * xString.length())))
        {
            return 'D';
        }
    }
    else
    {
        //check for high similarity-- difference within 10% of longer string and lcs 90% of shorter string
        if((yString.length() / (xString.length() * 1.0)) > (xString.length() * 0.90) && (tempTool.GetLcs() > (0.90 * yString.length())))
        {
            return 'H';
        }
        //check for medium similarity-- difference within 20% of longer string and lcs 80% of shorter string
        else if((yString.length() / (xString.length() * 1.0)) > (xString.length() * 0.20) && (tempTool.GetLcs() > (0.80 * yString.length())))
        {
            return 'M';
        }
        //check for low similarity-- difference within 40% of longer string and lcs 50% of shorter string
        else if((yString.length() / (xString.length() * 1.0)) > (xString.length() * 0.40) && (tempTool.GetLcs() > (0.80 * yString.length())))
        {
            return 'D';
        }
    }

}