#ifndef DATACLEANER.H
#define DATACLEANER.H
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class DataCleaner
{

public:

    //creates the dataCleaning object with a file member
    DataCleaner();

    //returns file member
    vector <vector<string>> getFile() const;

    //modifies file member to remove null values and duplicate data entries
    void cleanData();
private:
    vector <vector<string>> _file;

};



#endif