#include "DateTime.hpp"
#include <iostream>

int main() {
    DateTime dt1(15, 1, 2024, 23, 45, 30);
    DateTime dt2(16, 1, 2024, 0, 30, 15);

    std::cout << "Initial DateTime: " << dt1.format("Today is YYYY-MM-DD, and the time is HH:MM:SS") << "\n";
    dt1.addSeconds(3600);
    std::cout << "After adding 1 hour: " << dt1.format("YYYY-MM-DD HH:MM:SS") << "\n";

    int diff = dt1.differenceInSeconds(dt2);
    std::cout << "Difference in seconds: " << diff << "\n";

    return 0;
}
