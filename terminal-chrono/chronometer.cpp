#include "chronometer.h"
#include "timer.h"

int chronometer()
{
    int h = 0, m = 0, s = 0;
    while (true) {
        if (s == 60)
            s = 0, m++;
        if (m == 60)
            m = 0, h++;
        cout << "\r                          \r";
        if (h < 10) cout << '0';
        cout << h << ':';
        if (m < 10) cout << '0';
        cout << m << ':';
        if (s < 10) cout << '0';
        cout << s;
        cout << flush;
        s++;
        wait();
    }
    return 0;
}