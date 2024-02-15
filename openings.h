#ifndef OPENINGS_H_INCLUDED
#define OPENINGS_H_INCLUDED
#include <string>

using namespace std;

void AddOpening(string openings[][7], int size);
void PrintOpenings(string openings[][7], int size);
void LoadOpenings(ifstream& infile, string openings[][7], int num_openings);
void DeleteOpening(string openings[][7], int size);
void GetOpening(string opening[7]);
void SaveOpenings(string openings[][7], int size);
void ResetIDs(string openings[][7], int size);
void swapItems(string openings[][7], int indexA, int indexB);

#endif // OPENINGS_H_INCLUDED
