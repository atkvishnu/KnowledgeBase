/* Time Conversion
Given a time in -hour AM/PM format, convert it to military (24-hour) time.

Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
- 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.
Example

- s = '12:01:00PM'
Return '12:01:00'.

- s = '12:01:00AM'
Return '00:01:00'.
*/

/*
 * 3 edge cases:
 * - hrs == 12 && AM/PM == PM -> return hrs += 0
 * - AM/PM == PM              -> return hrs += 12
 * - hrs == 12 && AM/PM == AM -> return hrs -= 12
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
    string hours = "";
    string am_or_pm = "";
    string center = "";
    string final = "";

    for (int i = 0; i < 2; i++)
    {
        hours += s[i];
    }
    for (int i = 2; i < 8; i++)
    {
        center += s[i];
    }
    for (auto i = 8; i < s.length(); i++)
    {
        am_or_pm += s[i];
    }

    int hours_int = stoi(hours);

    if (hours_int == 12 && am_or_pm == "PM")
    {
        hours_int += 0;
    }
    else if (am_or_pm == "PM")
    {
        hours_int += 12;
    }
    else if (hours_int == 12 && am_or_pm == "AM")
    {
        hours_int -= 12;
    }

    string final_hours = "";
    if (hours_int < 10)
    {
        final_hours = "0" + to_string(hours_int);
    }
    else
    {
        final_hours = to_string(hours_int);
    }

    final += final_hours + center;

    return final;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
