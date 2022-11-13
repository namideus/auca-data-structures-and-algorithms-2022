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
    int l;

    if (size_a > size_b)
    {
        l = size_a + 1;
        for (int i = 0; i < l - size_b; ++i)
            b.push_back(0);

        a.push_back(0);
    }
    else
    {
        l = size_b + 1;
        for (int i = 0; i < l - size_a; ++i)
            a.push_back(0);

        b.push_back(0);
    }

    for (int i = 0; i < l; i++)
    {
        b[i] += a[i];
        b[i + 1] += b[i] / 10;
        b[i] %= 10;
    }

    if (b.back() == 0)
        b.pop_back();

    //   for (int i = (int)b.size() - 1; i >= 0; i--)
    // sum += b[i];

    for (auto d : b)
        sum += d;

    return BigInt(sum); // BigInt(std::string(b.begin(), b.end()));
}
