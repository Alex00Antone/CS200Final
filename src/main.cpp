
#include <iostream>
#include <fstream>
#include <string>


using namespace std;


#include "DataCleaner.h"
#include "Regression.h"



int main(){
    string fileName; 
    cout<<" what's the filepath for the .csv file you want to use?: "<<endl;
    cin>>fileName;
    

    DataCleaner dataCleaner = DataCleaner(fileName);

    dataCleaner.createDataFrame();

    dataCleaner.cleanData();
    dataCleaner.setValidColumns();
    vector<int> columns = dataCleaner.getValidColumns();
    vector<string> columnNames = dataCleaner.getColumnNames();

    vector <vector<string>> dataFrame = dataCleaner.getFile();

 
    int predictor;
    int explanatory;
    Regression regressionObj = Regression(dataFrame);

    cout<<"Valid Varibles: ";
    for (unsigned int i =0; i<columns.size(); i++){
        cout<<columns.at(i)<<" "<< columnNames.at(columns.at(i))<<" ";
    }
    cout<<endl;
    

    if(columns.size() <2){
        cout<<"Not enough valid numeric variables.";
        return 0;
    }
    
    while(true) {
        cout<<"What Predictor numeric variable do you want to use? (Column number): "<<endl;
        cin>> predictor;
        if(!cin.fail()) break;

        cin.clear();
        char badChar = ' ';
        do { badChar = cin.get(); } while(badChar != '\n');
    }
    if(!(predictor < columns.back())) {
        cout << "Unknown value, defaulting to first column" << endl;
        predictor = columns.at(0);
    }


    while(true) {
        cout<<"What Explanatory numeric variable do you want to use? (Column number): "<<endl;
        cin>> explanatory;
        if(!cin.fail()) break;

        cin.clear();
        char badChar = ' ';
        do { badChar = cin.get(); } while(badChar != '\n');
    }
    if(!(explanatory < columns.back())) {
        cout << "Unknown amount of integers, defaulting 2nd column" << endl;
        explanatory = columns.at(1);
        
    }
    
    regressionObj.setPredictorExplanatoryvars(predictor, explanatory);
    regressionObj.generateEquation();
    regressionObj.createSummary();
    vector<string> equation = regressionObj.getEquation();

    if (stod(equation.at(1)) < 0){
        cout<<"Equation: y_hat = "<<equation.at(0)<<" "<<equation.at(1)<<"x"<<endl;

    }
    else{
        cout<<"Equation: y_hat = "<<equation.at(0)<<" + "<<equation.at(1)<<"x"<<endl;

    }
    

    
    
    return 0;
}