#include<iostream>
#include "timer.h"
#include "clock.h"
#include "calendar.h"
#include "chronometer.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc == 1)
		cout << "HELP - ver 1.1\n\n-timer\n-chronometer\n-clock\n-calendar\n";
	else {
		if (strcmp(argv[1], "-timer") == 0) timer(argc - 1, argv + 1);
		else if (strcmp(argv[1], "-chronometer") == 0) chronometer();
		else if (strcmp(argv[1], "-clock") == 0) clock(argc - 1, argv + 1);
		else if (strcmp(argv[1], "-calendar") == 0) calendar(argc - 1, argv + 1);
		else cout << "Unknoun argument passed!\n";
	}

	return 0;
}