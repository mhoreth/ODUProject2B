#include "openings.h"       //includes openings header file
#include "generalFunctions.h" //includes generalFunctions header file
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>

//This function rewrites the opening IDs.
//the first one gets 0, then 1, and so on.
void ResetIDs(string openings[][7], int size)
{
  for(int i=0; i<size; i++)
        openings[i][0]= IntToString(i); //everything is a string, need to convert it to do arithmetic operations
}

void LoadOpenings(ifstream& infile, string openings[][7], int num_openings)
{   //reads a file and stores its contents in a 2D array
   for(int i=0; i<num_openings; i++)
        for(int j=0; j<7; j++)
        {
            infile>>openings[i][j];
        }
}

void PrintOpenings(string openings[][7], int size)
{
    cout<<setw(15)<<"ID"
        <<setw(15)<<"POSITION"
        <<setw(15)<<"DEPARTMENT"
        <<setw(15)<<"LEVEL"
        <<setw(15)<<"LOCATION"
        <<setw(15)<<"RELOCATION"
        <<setw(15)<<"EXPERIENCE"<<endl<<endl;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<7; j++)
            cout<<setw(15)<<std::left<<openings[i][j];
        cout<<endl;
    }
    cout<<endl<<endl;
}
//allows the user to add an entry to the openings array
//This function must invoke another function to get the opening
//then store it at the last place and store in the file, overwritting the old contents
void AddOpening(string openings[][7], int size)
{
    string newOpening[7];
    GetOpening(newOpening);
    string dummy[size+1][7];
    for(int i=0; i<size; i++){//copy openings to new structure
        for(int j=0; j<7; j++)
            dummy[i][j]=openings[i][j];
    }
    newOpening[0]= to_string(size);
    for(int i=0; i<7; i++)  //put new opening at end of structure
    {
        dummy[size][i]=newOpening[i];
    }
    size++;
    SaveOpenings(dummy, size); //save to file
}

void DeleteOpening(string openings[][7], int size)
{
     getId:
    cout<<"Enter ID of opening to delete(-1 to go back):";
    int del_id;
    cin>>del_id;
    if(cin.fail()==true || del_id < -1 || del_id > (size-1))
    {
        system("CLS");
        cout<<"Invalid Input"<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
        goto getId;
    }
    if(del_id !=-1) //as long as ID inputted is not -1
    {
        int newSize = size-1;   //decrease the size
        for(int i=del_id; i<newSize; i++)
            swapItems(openings, i, i+1); //and swap all elements above our deletion ID

        ResetIDs(openings, newSize);
        SaveOpenings(openings, newSize);//giving size-1 disregards the last element in the process, which has been swapped on the previous step
    }
    else
        system("CLS");

}

//Used for openings
void swapItems(string openings[][7], int indexA, int indexB)
{
    string dummy;
    for (int i=0; i<7; i++){
        dummy = openings[indexA][i];
        openings[indexA][i] = openings[indexB][i];
        openings[indexB][i] = dummy;
    }
}

void GetOpening(string opening[7])
{
    string temp;    //we keep re-assining values to this temp variable
    cout<<endl<<endl;
    cout<<setw(25)<<"Enter Position Title:";
    cin>>temp;
    opening[1]=temp;    //store temp value to its place in the array
    cout<<setw(21)<<"Enter Department:";
    cin>>temp;
    opening[2]=temp;
    cout<<setw(21)<<"Enter Level(1-3):";
    cin>>temp;
    opening[3]=temp;
    cout<<setw(39)<<"Enter Location(state abbreviation):";
    cin>>temp;
    opening[4]=temp;
    cout<<setw(38)<<"Enter Relocation Benefits(yes/no):";
    cin>>temp;
    opening[5]=temp;
    cout<<setw(45)<<"Enter Experience requirement(# of years):";
    cin>>temp;
    opening[6]=temp;
}

void SaveOpenings(string openings[][7], int size)
{
    ofstream outfile;
    outfile.open("openings.txt", ios::out); //opens the file for writing purposes
    outfile<<size<<endl;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<7; j++)
            outfile<<setw(15)<<left<<openings[i][j];
        outfile<<endl;
    }
    outfile.close();
}
