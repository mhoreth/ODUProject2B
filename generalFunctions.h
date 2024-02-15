#ifndef GENERALFUNCTIONS_H_INCLUDED
#define GENERALFUNCTIONS_H_INCLUDED
#include <string>

using namespace std;

void Menu();
string IntToString(int i);
int StringToInt(string s);
void FindMatches(string candidates[][6], int cand_size, string openings[][7], int opening_size);

#endif // GENERALFUNCTIONS_H_INCLUDED
