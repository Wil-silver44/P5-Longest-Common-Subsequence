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
	    this->reader >> this->list[i];
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
                this->simTable[i][j] = '-';
        }
    }

}

void LcsSeekerPartTwo::Run()
{
    cout << "---------- PART 2 BEGIN ----------" << endl;
    for(int i = 0; i < this->numStrings; ++i)
    {
        for(int j = (i + 1); j < this->numStrings; ++j)
        {
            this->simTable[i][j] = compareStrings(this->list[i], this->list[j]);
        }
    }

    printSimTable();

    cout << "---------- PART 2 COMPLETE ----------" << endl;
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

    delete[] this->list;
}

char LcsSeekerPartTwo::compareStrings(string xString, string yString)
{
	LcsTool tempTool(xString, yString);
	tempTool.Lcs();
	double lcs = (double)tempTool.GetLcs();
	string smallS = min(xString, yString);
	string bigS = max(xString, yString);
	double percentDiff = (smallS.length() / (double)bigS.length());
	
        //check for high similarity-- difference within 10% of longer string and lcs 90% of shorter string
        if( (percentDiff > 0.90) && ( lcs > 0.90 ) )
        {
            return 'H';
        }
        //check for medium similarity-- difference within 20% of longer string and lcs 80% of shorter string
        else if( (percentDiff > 0.80 ) && (lcs > 0.80) ) 
        {
            return 'M';
        }
        //check for low similarity-- difference within 40% of longer string and lcs 50% of shorter string
        else if( (percentDiff > 0.40) && ( lcs > 0.50) ) 
        {
            return 'L';
        }
	else
	{
		return 'D';
	}
	return '?';
}
