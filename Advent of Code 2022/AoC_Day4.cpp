#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

bool Check(int a, int b, int c, int d)
{
    if ((b < c) || (d < a))
    {
        return true;
    }
    return false;
}

bool Split(string s)
{
    string a;
    string b(s.size(), ' ');
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ',')
        {
            a = s.substr(0, i);
            b = s.substr(i + 1, s.size() - i);
        }
    }
    int x, y, z, t;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '-')
        {
            x = stoi(a.substr(0, i));
            y = stoi(a.substr(i + 1, a.size() - i));
        }
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == '-')
        {
            z = stoi(b.substr(0, i));
            t = stoi(b.substr(i + 1, b.size() - i));
        }
    }
    return Check(x, y, z, t);
}

int main()
{
    ifstream file("AoC_Day4.txt");

    vector<string> arr;
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            if (file)
                arr.push_back(line);
            else
                break;
        }
    }
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (Split(arr[i]))
        {
            cnt++;
        }
    }
    cout << arr.size() - cnt;
    return 0;
}
