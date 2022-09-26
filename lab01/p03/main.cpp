#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string str, name;

    while (getline(cin, str))
    {
        int nGrades = 0;
        double sum = 0;
        int grade;

        istringstream ss(str);

        ss >> name;

        while (ss >> grade)
        {
            nGrades++;
            sum += grade;
        }

        cout << setfill('.') << fixed << setprecision(2);
        cout << left << setw(28) << name << "|" << right;

        if (nGrades > 0)
            cout << setw(32) << sum / nGrades << "\n";
        else
            cout << setw(33) << "no data\n";
    }
}