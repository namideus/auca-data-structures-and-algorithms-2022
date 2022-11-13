#pragma once

class BigInt
{
    friend std::ostream &operator<<(std::ostream &, const BigInt &);
    friend std::istream &operator>>(std::istream &, const BigInt &);
    friend BigInt operator+(const BigInt &, const BigInt &);

    std::vector<int> mDigits;
    bool mIsNegative;

public:
    BigInt() : mIsNegative(false)
    {
        mDigits.push_back(0);
    }
    BigInt(const std::string &s)
    {
        mIsNegative = (s[0] == '-');

        for (int i = (mIsNegative ? 1 : 0); i < (int)s.size(); i++)
        {
            auto d = s[i];

            if (!isdigit(d))
                throw std::runtime_error("invalid representation of BigInt value");

            mDigits.push_back(d - '0');
        }
    }
    BigInt(int val) : BigInt(std::to_string(val)) {}
};

inline std::ostream &operator<<(std::ostream &out, const BigInt &x)
{
    if (x.mIsNegative)
    {
        out << "-";
    }
    for (auto d : x.mDigits)
    {
        out << d;
    }
    return out;
}

inline std::istream &operator>>(std::istream &in, BigInt &x)
{
    std::string d;
    in >> d;
    x = BigInt(d);
    return in;
}

inline BigInt operator+(const BigInt &b1, const BigInt &b2)
{
    std::string sum = "";
    std::vector<int> a = b1.mDigits;
    std::vector<int> b = b2.mDigits;

    int size_a = (int)a.size();
    int size_b = (int)b.size();

    std::vector<int> z(std::abs(size_a - size_b), 0);

    if (size_a > size_b)
        b.insert(b.begin(), z.begin(), z.end());
    else if (size_b > size_a)
        a.insert(a.begin(), z.begin(), z.end());

    for (int i = std::max(size_a, size_b) - 1; i >= 1; i--)
    {
        b[i] += a[i];
        b[i - 1] += b[i] / 10;
        b[i] %= 10;
    }

    b[0] += a[0];
    if (b[0] / 10 != 0)
    {
        int tmp = b[0];
        b[0] = tmp % 10;
        b.insert(b.begin(), tmp / 10);
    }

    for (auto d : b)
        sum += std::to_string(d);

    return BigInt(sum);
}
