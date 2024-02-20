#include <iostream>

int daysPassed(int day1, int month1, int year1, int day2, int month2, int year2) {
    const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;

    while (day1 != day2 || month1 != month2 || year1 != year2) {
        days++;
        day1++;

        if (day1 > daysInMonth[month1 - 1]) {
            day1 = 1;
            month1++;
        }

        if (month1 > 12) {
            month1 = 1;
            year1++;
        }
    }

    return days;
}

int main() {
    int day1 = 1, month1 = 1, year1 = 2021;
    int day2 = 5, month2 = 1, year2 = 2021;

    std::cout << "Number of days passed: " << daysPassed(day1, month1, year1, day2, month2, year2) << std::endl;

    return 0;
}
