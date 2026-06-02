#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Returns day of week for Jan 1 of the given year
// 0 = Sunday, 1 = Monday, ..., 6 = Saturday
int getFirstDayOfTheYear(int year)
{
    int d = 1;  // January 1
    int m = 13; // January treated as month 13 of previous year
    int y = year - 1;

    int k = y % 100;
    int j = y / 100;

    int h = (d + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    // Convert Zeller's output:
    // 0=Saturday, 1=Sunday, ..., 6=Friday
    return (h + 6) % 7;
}

int main()
{
    vector<string> months =
    {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    vector<int> daysInMonth =
    {
        31, 28, 31, 30,
        31, 30, 31, 31,
        30, 31, 30, 31
    };

    int year;
    cout << "Enter any year: ";
    cin >> year;

    // Leap year check
    bool isLeapYear =
        (year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0);

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
            cout << "\n\n------------ "
                 << months[i] << " " << year
                 << " ------------\n";

            cout << "Sun Mon Tue Wed Thu Fri Sat\n";

            // Leading spaces
            for (int j = 0; j < firstDay; j++)
            {
                cout << "    ";
            }

            // Print dates
            for (int day = 1; day <= daysInMonth[i]; day++)
            {
                cout << setw(3) << day << " ";

                firstDay++;

                if (firstDay == 7)
                {
                    cout << endl;
                    firstDay = 0;
                }
            }

            if (firstDay != 0)
            {
                cout << endl;
            }
        }
    }
    else if (choice == 0)
    {
        cout << "Calendar Stopped" << endl;
    }
    else
    {
        cout << "Invalid choice. Please enter 1 to display the calendar or 0 to exit."
             << endl;
    }

    return 0;
}
