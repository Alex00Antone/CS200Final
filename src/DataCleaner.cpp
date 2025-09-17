#include "DataCleaner.h"
#include "fstream"
#include <stdexcept>
#include <iostream>
using namespace std;


//creates the dataCleaning object with a file member
DataCleaner::DataCleaner(string file){
    _fileName = file;
}

//returns file member
vector <vector<string>> DataCleaner::getFile() const{
    return _file;
}




//modifies file member to remove null values and duplicate data entries
void DataCleaner::cleanData(){
    for (unsigned int i = 0; i<_file.size(); i++){
        for (unsigned int j = 0; j<_file.at(i).size(); j++){
            if (_file.at(i).at(j) == ""){
                _file.at(i).clear();
                break;
            }
        }
    }

}

//creates data frame
void DataCleaner::createDataFrame(){
    vector<string> row;
    ifstream file;
    string word;
    file.open(_fileName);
    char c;
    getline(file, word);
    int index = 0;
    for (unsigned int i= 0 ; i<word.size(); i++){
        if (word.at(i) ==','){
            _columnNames.push_back(word.substr(index, i-index));
            i++;
            index = i;
            
        } 
    }
    _columnNames.push_back(word.substr(index, word.size()-index));
    word = "";
    while (file.get(c)){
    
        if(!(c==','||c=='\n')){
            word.push_back(c);

        }
        else{
            
            row.push_back(word);
            if(c=='\n'){
                _file.push_back(row);
                row.clear();
            }
            word = "";
        
        }
    }
    _file.push_back(row);
}


//sets valid columns
void DataCleaner::setValidColumns(){
    bool valid = true;
    for (unsigned int j =0; j<_file.at(0).size(); j++){
        valid = true;
        for(unsigned int i = 0; i<_file.size();i++){
            try {
                stod(_file.at(i).at(j));
            } catch (const invalid_argument& error) {
                valid = false;
                break;
            } catch (const exception& error) {
                cerr << "An unexpected error occurred: " << error.what() << std::endl;
                valid = false;
                break;
            }
            
        }
    if (valid){
        _validColumns.push_back(j);
    }
    }  
}


//finds valid columns
vector<int> DataCleaner::getValidColumns(){
    return _validColumns;
}

//returns column names
vector<string> DataCleaner::getColumnNames(){
    return _columnNames;
}