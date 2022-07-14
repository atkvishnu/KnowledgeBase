// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

class Solution
{
public:
    double average(vector<int> &salary)
    {
        sort(salary.begin(), salary.end());
        double avg = 0;
        for (auto i = salary.begin() + 1; i < salary.end() - 1; i++)
        {
            avg += *i;
        }
        return avg / (salary.size() - 2);
    }
};