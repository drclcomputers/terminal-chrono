#include "timer.h"

void wait() {
#ifdef _WIN32
    Sleep(1000);
#else
    sleep(1);
#endif
}

void beep() {
#ifdef _WIN32
    Beep(1500, 1500);
#else
    cout << "\a\n";
#endif
}

int timer(int argc, char* argv[])
{
    int h = 0, m = 0, s = 0;
    if (argc == 1) {
        cout << "Enter a time! (exp: \"-timer 5 6\" -> timer for 6 minutes and 5 seconds)\n";
        return 0;
    }
    else if (argc == 2) {
        s = atoi(argv[1]);
        while (s > 59)
            s -= 60, m++;
        while (m > 59)
            m -= 60, h++;
    }
    else if (argc == 3) {
        s = atoi(argv[1]), m = atoi(argv[2]);
        while (s > 59)
            s -= 60, m++;
        while (m > 59)
            m -= 60, h++;
    }
    else {
        s = atoi(argv[1]), m = atoi(argv[2]), h = atoi(argv[3]);
        while (s > 59)
            s -= 60, m++;
        while (m > 59)
            m -= 60, h++;
    }

    while (h != 0 || m != 0 || s != 0) {
        if (s == 0 && m > 0)
            s = 60, m--;
        if (m == 0 && h > 0 && s == 0)
            s = 60, m = 59, h--;
        s--;
        cout << "\r                          \r";
        if (h < 10) cout << '0';
        cout << h << ':';
        if (m < 10) cout << '0';
        cout << m << ':';
        if (s < 10) cout << '0';
        cout << s;
        cout << flush;
        wait();
    }
    beep();
    return 0;
}