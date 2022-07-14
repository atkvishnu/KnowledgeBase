// https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/

class Solution
{
public:
    int manhattan(int x1, int y1, int x2, int y2)
    {
        return abs(x1 - x2) + abs(y1 - y2);
    }
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        int max = INT_MAX;
        int index = -1;
        for (int i = 0; i < points.size(); i++)
        {
            if (points[i][0] == x || points[i][1] == y)
            {
                int res = manhattan(x, y, points[i][0], points[i][1]);
                if (res < max)
                {
                    max = res;
                    index = i;
                }
            }
        }
        return index;
    }
};