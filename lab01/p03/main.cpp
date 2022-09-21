#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string name;
    cin >> name;

    int nGrades = 0;
    double sum = 0;
    int grade;

    while (cin >> grade)
    {
        ++nGrades;
        sum += grade;
    }

    cout << setfill(".") << fixed << setprecision(2);
    cout << left << setw(2) << name << "|" << right << setw(30) << sum / nGrades << "\n";
}