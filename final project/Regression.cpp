#include "Regression.h"
#include "DataCleaner.h"

// creates Regression object with a pointer pDataframe member to datacleaning object file member.
Regression::Regression(vector <vector <string>> &dataFrame){

}

//creates regression model utilizing least squares method
void Regression::generateEquation(){

}

//returns equation
vector<string> Regression::getEquation(){
    return _equation;
}
    
//generates a summary of the model, with Sum of squares model vs sum of squares total, t-test statistics, p-statistics, etc.
void Regression::createSummary(vector<string> _equation){
    
}