#pragma once

class BigInt
{
    friend std::ostream &operator<<(std::ostream&, const BigInt &x);
    std::vector<int> mDigits;
    bool mIsNegative;

    public:
        BigInt(): mIsNegative(false)
        {
            mDigits.push_back(0);
        }
        BigInt(const std::string &s)
        {
            mIsNegative = (s[0]=='-');

            for(int i = (mIsNegative ? 1 : 0); i < (int)s.size(); i++)
            {
                auto d = s[i];

                if(!isdigit(d))
                    throw std::runtime_error("Non-digit character found!");

                mDigits.push_back(d-'0');
            }
        }
};

inline std::ostream &operator<<(std::ostream& out, const BigInt &x)
{
    if(x.mIsNegative) {
        out << "-";
    }
    for(auto d : x.mDigits)
    {
        out << d;
    }
    return out;
}
