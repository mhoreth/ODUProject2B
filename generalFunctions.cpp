#include "candidates.h"     //Includes candidates header file
#include "openings.h"       //includes openings header file
#include "generalFunctions.h" //includes generalFunctions header file
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>

//Find all candidates that match any opening and print them
void FindMatches(string candidates[][6], int cand_size, string openings[][7], int opening_size)
{
    for (int i=0; i<cand_size; i++)
        for (int j=0; j<opening_size; j++){
            if (candidates[i][2]==openings[j][1]){
                PrintCandidate(candidates, i);
            }
        }
}

//this converts strings to integers
int StringToInt(string s)
{
    stringstream temp(s);
    int integer = 0;
    temp >> integer;
    return integer;
}

//this converts integers to strings
string IntToString(int i)
{
    ostringstream str1;
    str1<<i;
    string temp = str1.str();
    return temp;
}

//Receives input from the user and performs appropriate command
//all operations require constant reading and writing of files
void Menu()
{
    int input;

    ifstream inOpenings;    //this variable will allow input operations for the openings file
    int num_openings;
    ifstream inCandidates;  //this variable will allow input operations for the candidates file
    int num_candidates;

    redo:
    //we need to load every time
    inOpenings.open("openings.txt", ios::in);   //open files
    inOpenings>>num_openings;                   //read # of entries in file
    inCandidates.open("candidates.txt", ios::in);
    inCandidates>>num_candidates;

    string openings[num_openings][7];       //create array to store info currently in file
    string candidates[num_candidates][6];
    LoadOpenings(inOpenings, openings, num_openings);   //this loads the contents to the array, so that we can use it in subsequent operations
    LoadCandidates(inCandidates, candidates, num_candidates);
    inOpenings.close(); //close the files
    inCandidates.close();

    GetSelection:          //This is a label, a destination for a goto statement. Allows us to reenter the menu without writing a while loop

    cout<<"1.   "<<setw(40)<<std::left<<"Add Opening"<<endl;
    cout<<"2.   "<<setw(40)<<std::left<<"Delete Opening"<<endl;
    cout<<"3.   "<<setw(40)<<std::left<<"Show Openings"<<endl;
    cout<<"4.   "<<setw(40)<<std::left<<"Match Candidates to all Openings"<<endl<<endl;

    cout<<"5.   "<<setw(40)<<std::left<<"Add Candidate"<<endl;
    cout<<"6.   "<<setw(40)<<std::left<<"Show Candidates"<<endl;
    cout<<"7.   "<<setw(40)<<std::left<<"Show Candidates by position"<<endl;
    cout<<"8.   "<<setw(40)<<std::left<<"Filter Candidates By Rating"<<endl<<endl;

    cout<<"9.   "<<setw(40)<<std::left<<"Clear Screen"<<endl;
    cout<<"Enter Selection:";
    cin>>input;

    if(cin.fail() == true || input>9)
    {
        system("CLS");
        cout<<endl<<endl;
        cout<<"Invalid Input. Please Re-enter Selection"<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
        goto GetSelection;
    }
    else if(input == 1)
        AddOpening(openings, num_openings);

    else if(input == 2)
        DeleteOpening(openings, num_openings);

    else if(input == 3)
        PrintOpenings(openings, num_openings);
    else if(input == 4)
        FindMatches(candidates, num_candidates, openings, num_openings);

    else if(input == 5)
        AddCandidate(candidates, num_candidates);

    else if(input == 6)
        PrintCandidates(candidates,  num_candidates);
    else if(input == 7)
        ShowCandidatesByPosition(candidates, num_candidates);
    else if(input == 8)
        FilterCandidatesByRating(candidates, num_candidates);
    else if(input == 9)
    {
        system("CLS");
    }
    else
        goto end;
    goto redo;
    end:
    cout<<endl<<endl;
    cout<<"Termination"<<endl;
}
