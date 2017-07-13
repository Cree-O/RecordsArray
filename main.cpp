//
//  RecordsArray.cpp
//  RecordsArray
//
//  Created by Christopher Orlik on 3/29/17.
//  Copyright © 2017 Christopher Orlik. All rights reserved.
//
// This program reads in test scores from a .txt file database into an array
// then calculates student and class averages and prints them out
//

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Computes class average for each test score and outputs the score at the bottom of table
void print_TestAvgs(double grades[][5], int rows){
    double tempAvg = 0.0;
    for (int iterCol = 0; iterCol < 5; iterCol++){
        for(int iterRow = 0; iterRow <= rows; iterRow++){
            tempAvg += grades[iterRow][iterCol];
        }
        tempAvg = tempAvg / (rows);
        if (iterCol < 4){
            cout << fixed << setprecision(1) << setw(8) << tempAvg;
        }
        else
            cout << fixed << setprecision(1) << setw(4) << "|" << setw(6) << tempAvg;
        tempAvg = 0.0;
    }
    cout << endl;
}

// Averages each student's score for all tests and displays each students records
void print_grades(double grades[][5], int rows){
    rows = rows - 1;
    for (int i = 0; i <= rows ; i++){
        if (i == 0){
            cout << setw(8) << "T1" <<setw(8) << "T2" <<setw(8) << "T3" <<setw(8) << "T4" <<setw(4) <<
            "|" << setw(6) << "AVG" << endl;
        }
        for(int col = 0; col < 5; col++){
            if (col < 4){
            cout << fixed << setprecision(0) << setw(8) << grades[i][col];
            }
            else
                cout << setw(4) << "|" << setw(6) << fixed << setprecision(1) << grades[i][col];
        }
        cout << endl;

    }
    cout<< setw(8) << "__________________________________________" << endl;

}

// main function reads in data from .txt file database
// then calculates individual students avg score on tests
// assigns the average to the last column of each row of the array
// then calls the two print functions to output table
int main() {

    int col;
    double grades[50][5];
    int row;
    row = 0;
    double Stusum = 0;

    ifstream fin("sturec.txt");
    while(!fin.eof()){
        for(col = 0; col < 4; col++){
            fin >> grades[row][col];
                Stusum += grades[row][col];
            }
            grades[row][4] = Stusum / 4;
            row++;
        Stusum = 0;
        }

        print_grades(grades, row);
        print_TestAvgs(grades, row);
}













