#include <iostream>
using namespace std;

const int MAX_LENGHTH_POINT = 60;

class SimilarityChecker
{
public:
    int CheckStrLength(string a, string b)
    {
        int size1 = a.size();
        int size2 = b.size();
        int small = (size1 > size2) ? size2 : size1;
        int large = (size1 > size2) ? size1 : size2;
        int gap = large - small;
        
        if (size1 == size2)
        {
            return MAX_LENGHTH_POINT;
        }

        if (small * 2 <= large)
        {
            return 0;
        }

        double subPoint = (1 - ((double)gap / (double)small)) * MAX_LENGHTH_POINT;

        return (int)subPoint;
    }
};