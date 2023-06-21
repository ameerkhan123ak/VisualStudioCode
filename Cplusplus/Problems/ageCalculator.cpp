#include <iostream>

// Function to calculate the age based on the current date and the birth date
void calculateAge(int birthYear, int birthMonth, int birthDay, int currentYear, int currentMonth, int currentDay) {
    // Calculate the difference in years
    int ageYears = currentYear - birthYear;

    // Calculate the difference in months
    int ageMonths = currentMonth - birthMonth;
    if (ageMonths < 0) {
        ageYears--;
        ageMonths += 12;
    }

    // Calculate the difference in days
    int ageDays = currentDay - birthDay;
    if (ageDays < 0) {
        ageMonths--;
        if (ageMonths < 0) {
            ageYears--;
            ageMonths += 12;
        }
        ageDays += 30; // Assuming all months have 30 days
    }

    // Print the calculated age
    std::cout << "Your age is: " << ageYears << " years, " << ageMonths << " months, and " << ageDays << " days." << std::endl;
}

int main() {
    int birthYear, birthMonth, birthDay;
    int currentYear, currentMonth, currentDay;

    // Get the birth date from the user
    std::cout << "Enter your birth year: ";
    std::cin >> birthYear;

    std::cout << "Enter your birth month (1-12): ";
    std::cin >> birthMonth;

    std::cout << "Enter your birth day: ";
    std::cin >> birthDay;

    // Get the current date from the user
    std::cout << "Enter the current year: ";
    std::cin >> currentYear;

    std::cout << "Enter the current month (1-12): ";
    std::cin >> currentMonth;

    std::cout << "Enter the current day: ";
    std::cin >> currentDay;

    // Call the calculateAge function
    calculateAge(birthYear, birthMonth, birthDay, currentYear, currentMonth, currentDay);

    return 0;
}
