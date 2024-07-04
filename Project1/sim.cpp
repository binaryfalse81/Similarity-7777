#include <iostream>
using namespace std;

class SimilarityChecker
{
public:
    int CheckStrLength(string a, string b)
    {
        int size1 = a.size();
        int size2 = b.size();
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