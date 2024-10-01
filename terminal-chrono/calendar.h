#pragma once
#include "conf.h"

using namespace std;

int get_actual_month();
int get_actual_year();
bool leap_year(int year);
int get_firstday(int month, int year);
void print_cal(int month, int year);
int calendar(int argc, char* argv[]);