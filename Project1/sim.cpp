#include <iostream>
using namespace std;

class CharChecker {
public:
    int getCharPoint(string input1, string input2) {
        initByCollectIndexing(input1, input2);

        if (getDiffCount() == 0) return MAX_SAMECHAR_POINT;
        if (getSameCount() == 0) return MIN_SAMECHAR_POINT;

        return getPartialCharPoint();
    }

    void initByCollectIndexing(std::string& input1, std::string& input2) {
        setDAT(input1, dat1);
        setDAT(input2, dat2);
    }

    int getDiffCount() {
        int result = 0;
        for (int i = 0; i < 200; i++) {
            if (dat1[i] + dat2[i] == 1) result++;
        }
        return result;
    }

    int getSameCount() {
        int result = 0;
        for (int i = 0; i < 200; i++) {
            if (dat1[i] == 1 && dat2[i] == 1) result++;
        }
        return result;
    }

    int getTotalCount() {
        int result = 0;
        for (int i = 0; i < 200; i++) {
            if (dat1[i] == 1 || dat2[i] == 1) result++;
        }
        return result;
    }

    int getPartialCharPoint()
    {
        return MAX_SAMECHAR_POINT * getSameCount() / getTotalCount();
    }

private:
    void setDAT(std::string& str, int dat[]) {
        for (int i = 0; i < str.length(); i++) {
            dat[str[i]] = 1;
        }
    }

    const int MAX_SAMECHAR_POINT = 40;
    const int MIN_SAMECHAR_POINT = 0;

    int dat1[200] = { 0 };
    int dat2[200] = { 0 };
};

class SimilarityChecker
{
public:
    int CheckStrLength(string input1, string input2)
    {
        int size1 = input1.size();
        int size2 = input2.size();
        int small = GetSmallLength(size1, size2);
        int large = GetLargeLength(size1, size2);
        int gap = GetLengthGap(large, small);
        
        if (IsSameLength(size1, size2))
        {
            return MAX_LENGTH_POINT;
        }

        if (IsDouble(large, small))
        {
            return ZERO_LENGTH_POINT;
        }

        return GetSubPoint(gap, small);
    }

private:
    const int MAX_LENGTH_POINT = 60;
    const int ZERO_LENGTH_POINT = 0;

    int GetSmallLength(int size1, int size2)
    {
        return (size1 > size2) ? size2 : size1;;
    }

    int GetLargeLength(int size1, int size2)
    {
        return (size1 > size2) ? size1 : size2;;
    }

    bool IsSameLength(int size1, int size2)
    {
        return (size1 == size2);
    }

    int GetLengthGap(int large, int small)
    {
        return large - small;
    }

    bool IsDouble(int large, int small)
    {
        return (small * 2 <= large);
    }

    int GetSubPoint(int gap, int small)
    {
        double subPoint = (1 - ((double)gap / (double)small)) * MAX_LENGTH_POINT;
        return (int)subPoint;
    }
};