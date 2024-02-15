#ifndef CANDIDATES_H_INCLUDED
#define CANDIDATES_H_INCLUDED
#include <string>

using namespace std;

void GetCandidate(string candidate[6]);
void SaveCandidates(string temp[][6], int size);
void LoadCandidates(ifstream& infile, string candidates[][6], int num_candidates);
void AddCandidate(string candidates[][6], int size);
void ShowCandidatesByPosition(string candidates[][6], int size);
void PrintCandidates(string candidates[][6], int size);
void SwapCandidates(string candidates[][6], int indexA, int indexB);
void SortByRating(string candidates[][6], int num_candidates);
void FilterCandidatesByRating(string candidates[][6], int num_candidates);
void PrintCandidate(string temp[][6], int index);

#endif // CANDIDATES_H_INCLUDED
