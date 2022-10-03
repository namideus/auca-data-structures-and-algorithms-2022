#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    for (string line; getline(cin, line);)
    {
        string buff;
        for (auto c : line)
        {
            if (isalpha(c))
            {
                buff += tolower(c);
            }
        }

        string copy = buff;
        reverse(copy.begin(), copy.end());

        cout << (copy == buff ? "Palindrome\n" : "Not a Palindrome\n");
    }
}