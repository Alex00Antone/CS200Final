#ifndef DATACLEANER_H

#define DATACLEANER_H 

#include <cmath>
#include <string>
#include <vector>
using namespace std;

class DataCleaner
{

public:

    //creates the dataCleaning object with a file member
    DataCleaner(string dataFrame);

    //returns file member
    vector <vector<string>> getFile() const;

    //modifies file member to remove null values and duplicate data entries
    void cleanData();

    //makes file member
    void createDataFrame();


    //finds valid columns
    void setValidColumns();

    //gets columns
    vector<int> getValidColumns();

    //gets columns
    vector<string> getColumnNames();
    
    
private:
    vector <vector<string>> _file;
    string _fileName;
    vector <int> _validColumns;
    vector<string> _columnNames;


};





#endif