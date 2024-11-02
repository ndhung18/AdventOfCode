#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int value1(string s)
{
    int val;
    string a, b;
    a = s.substr(0, s.size() / 2);
    b = s.substr(s.size() / 2, s.size() / 2);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            if (a[i] == b[j])
            {
                if (a[i] >= 'a' && a[i] <= 'z')
                {
                    val = int(a[i]) - 96;
                }
                else
                {
                    val = int(a[i]) - 38;
                }
            }
        }
    }
    return val;
}

int value2(string a, string b, string c)
{
    vector<char> item2;
    int _val;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j])
            {
                item2.push_back(a[i]);
            }
        }
    }
    sort(item2.begin(), item2.end());
    item2.erase(unique(item2.begin(), item2.end()), item2.end());
    // for (int i = 0; i < item2.size(); i++)
    // {
    //     cout << item2[i] << " ";
    // }

    for (int i = 0; i < item2.size(); i++)
    {
        for (int j = 0; j < c.size(); j++)
        {
            if (item2[i] == c[j])
            {
                if (c[j] >= 'a' && c[j] <= 'z')
                {
                    _val = int(c[j]) - 96;
                }
                else
                {
                    _val = int(c[j]) - 38;
                }
            }
        }
    }
    return _val;
}

int main()
{
    ifstream file("AoC_Day3.txt");

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
    int sum = 0;
    for (int i = 0; i < arr.size(); i += 3)
    {
        sum += value2(arr[i], arr[i + 1], arr[i + 2]);
    }
    // sum += value2(arr[0], arr[1], arr[2]);
    cout << sum;
}
