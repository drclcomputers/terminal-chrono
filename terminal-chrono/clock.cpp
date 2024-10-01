#include "clock.h"

char* print_time() {
    time_t rawtime = time(0);
    char* date_time = ctime(&rawtime);
    return date_time;
}

int clock(int argc, char* argv[]) {
    if (argc == 1)
        cout << print_time() << endl;
    else if (argc == 2) {
        if (strcmp(argv[1], "-time") == 0) {
            char* p = strtok(print_time() + 10, " ");
            cout << p << endl;
        }
        else if (strcmp(argv[1], "-date") == 0) {
            char* p = strtok(print_time(), " ");
            cout << p << ", ";
            p = strtok(NULL, " ");
            cout << p << " ";
            p = strtok(NULL, " ");
            cout << p << " ";
            p = strtok(NULL, " ");
            p = strtok(NULL, " ");
            cout << p;
        }
        else {
            cout << "Unknoun argument passed!\n-time -> prints only the clock\n-date -> prints only the date\nno argument -> prints both\n";
        }
    }
    return 0;
}