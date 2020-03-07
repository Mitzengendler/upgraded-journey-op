#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <filesystem>

using namespace std;

string* read_it(string path, int* pnum);
string* one_d_arr(int* pn);
void print(int* pn, string* arr);
string** two_d_eleven(int* pn);
void pretty(int* pn, string* arr, string** prettyTable);
string* teams(int* pn, string** prettyTable);
void output(int* pn, string* tm);
string** score(int* pn, string** prettyTable);
void showscore(int* pn, string** sc);
int* init1d(int* pn);
int** init2d(int* pn);
void calcres(int* pn, string** in, int** out);
void summ(int* pn, int** in, int* out);
void sort(int* pn, string* team, int* score);