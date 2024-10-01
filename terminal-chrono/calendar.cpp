#include "calendar.h"

using namespace std;

int get_actual_month() {
    time_t rawtime = time(0);
    char* date_time = ctime(&rawtime);
    char monthchar[4];

    strncpy(monthchar, date_time + 4, 3);
    monthchar[3] = '\0';

    if (strcmp(monthchar, "Jan") == 0) return 1;
    if (strcmp(monthchar, "Feb") == 0) return 2;
    if (strcmp(monthchar, "Mar") == 0) return 3;
    if (strcmp(monthchar, "Apr") == 0) return 4;
    if (strcmp(monthchar, "May") == 0) return 5;
    if (strcmp(monthchar, "Jun") == 0) return 6;
    if (strcmp(monthchar, "Jul") == 0) return 7;
    if (strcmp(monthchar, "Aug") == 0) return 8;
    if (strcmp(monthchar, "Sep") == 0) return 9;
    if (strcmp(monthchar, "Oct") == 0) return 10;
    if (strcmp(monthchar, "Nov") == 0) return 11;
    if (strcmp(monthchar, "Dec") == 0) return 12;

    return 1;
}

int get_actual_year() {
    time_t rawtime = time(0);
    char* date_time = ctime(&rawtime);

    return atoi(date_time + 20);
}

bool leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int get_firstday(int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int firstday = int(1 + floor(13 * (month + 1) / 5) + year % 100 + floor((year % 100) / 4) + floor(year / 100 / 4) + 5 * (year / 100)) % 7;
    return firstday;
}

void print_cal(int month, int year) {
    int firstday = get_firstday(month, year);
    int zile_max = 31;

    bool leap = leap_year(year);

    if (month == 2) {
        zile_max = leap ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        zile_max = 30;
    }

    cout << ' ' << month << '/' << year << '\n';
    cout << " Sa Su Mo Tu We Th Fr\n";

    int day = 1;
    bool print_started = false;

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (!print_started && j == firstday) {
                print_started = true;
            }
            if (print_started && day <= zile_max) {
                cout << (day < 10 ? " 0" : " ") << day;
                day++;
            }
            else {
                cout << "   ";
            }
        }
        cout << '\n';
        if (day > zile_max) break;
    }
}

int calendar(int argc, char* argv[]) {
    if (argc == 1) {
        print_cal(get_actual_month(), get_actual_year());
    }
    else if (argc == 2) {
        cout << "Enter year, too!";
    }
    else {
        int month = atoi(argv[1]);
        int year = atoi(argv[2]);

        if (month < 1 || month > 12) {
            cout << "Enter month between 1 and 12!";
            return 0;
        }
        if (year < 1 || year > 5000) {
            cout << "Enter year between 1 and 5000!";
            return 0;
        }
        print_cal(month, year);
    }
    return 0;
}