#ifndef REGRESSION.H
#define REGRESSION.H

#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Regression
{

public:
    // creates Regression object with a pointer pDataframe member to datacleaning object file member.
    Regression(vector <vector <string>> &dataFrame);
    
    
    //creates regression model utilizing least squares method
    void generateEquation();

    //returns equation
    vector<string> getEquation();
    
    //generates a summary of the model, with Sum of squares model vs sum of squares total, t-test statistics, p-statistics, etc.
    void createSummary(vector<string> _equation); 
    
    


private:
vector<string> _equation;
    double _mean;
    vector <vector <string>> *_pDataFrame;
    vector <string> _summary;



};


#endif