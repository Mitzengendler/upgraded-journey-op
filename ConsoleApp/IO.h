#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

string* read_io(int* pn, string name);
string* one_d_io(int* pn);
string** two_d_io(int* pn);
string** two_d_scoreTable_init(int* pn);
void print_io(int* pn, string* matrix);
void pretty_str(int* pn, string* arr, string** prettyTable);
void table(int* pn, string* commandName, string** scoreTable, string** rawArray);
void print_commandName(int* pn, string* commandName);
void print_scoreTable(int* pn, string** scoreTable);