#include <iostream>
#include <ctime>

int countDaysBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2) {
    std::tm timeinfo1 = {0, 0, 0, day1, month1 - 1, year1 - 1900};
    std::tm timeinfo2 = {0, 0, 0, day2, month2 - 1, year2 - 1900};

    std::time_t time1 = std::mktime(&timeinfo1);
    std::time_t time2 = std::mktime(&timeinfo2);

    double seconds = std::difftime(time2, time1);
    double days = seconds / (60 * 60 * 24);

    return static_cast<int>(days);
}

int main() {
    int day1 = 1, month1 = 1, year1 = 2021;
    int day2 = 4, month2 = 2, year2 = 2021;

    int daysBetween = countDaysBetweenDates(day1, month1, year1, day2, month2, year2);

    std::cout << "Number of days between the two dates: " << daysBetween << std::endl;

    return 0;
}
