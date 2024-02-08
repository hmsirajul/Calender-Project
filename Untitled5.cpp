#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to calculate the first day of the year
int getFirstDayOfTheYear(int year)

{
    int day = (1 + 5 * ((year - 1) % 4) + 4 * ((year - 1) % 100) + 6 * ((year - 1) % 400)) % 7;
    return day;
}

int main()

{
    vector<string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int year;
    cout << "Enter any year: ";
    cin >> year;

    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    if (isLeapYear)

    {
        daysInMonth[1] = 29;
    }

    int choice;
    cout << "\n1. Display calendar\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)

    {
        int firstDay = getFirstDayOfTheYear(year);

        for (int i = 0; i < 12; i++)
        {
            cout << "\n----- " << months[i] << " -----\n";
            cout << "Sun Mon Tue Wed Thu Fri Sat\n";

            // Print leading spaces
            for (int spaceCounter = 0; spaceCounter < firstDay; spaceCounter++)

            {
                cout << "    ";
            }

            for (int day = 1; day <= daysInMonth[i]; day++)

            {
                cout << day << " ";
                if (++firstDay > 6)
                {
                    cout << endl;
                    firstDay = 0;
                }
            }
            cout << endl;
        }
    }
    else if (choice == 0)
    {
        cout << "Calendar Stopped" << endl;
    }
    else
    {
        cout << "Invalid choice. Please enter 1 to display the calendar or 0 to exit." << endl;
    }

    return 0;
}

