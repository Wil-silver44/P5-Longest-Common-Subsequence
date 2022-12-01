#include "LcsSeekerPartOne.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << "creating LcsSeekerPartOne object." << endl;
    
    LcsSeekerPartOne testSeeker;

    cout << "object created." << endl;

    cout << "running simulation..." << endl;

    testSeeker.Run();

    cout << "OPERATIONS COMPLETE, DEALLOCATING..." << endl;
}