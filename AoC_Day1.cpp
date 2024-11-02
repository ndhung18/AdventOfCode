#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int toInt(string s)
{
    int ans = 0;
    for (int i = 0; i < s.size(); ++i)
        ans = ans * 10 + s[i] - '0';
    return ans;
}

int main()
{
    ifstream calories("D:\\Code\\VScode\\Advent of Code 2022\\AoC_Day1.txt");

    if (calories.is_open())
    {
        vector<string> arr;
        string val;
        while (getline(calories, val))
        {
            if (calories)
                arr.push_back(val);
            else
                break;
        }
        vector<int> _arr;
        int sum = 0;
        int max = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] != "\0")
            {
                int temp = toInt(arr[i]);
                sum += temp;
            }
            else
            {
                _arr.push_back(sum);
                // max = (sum > max ? sum : max);
                sum = 0;
            }
        }
        sort(_arr.begin(), _arr.end());
        for (int i = 0; i < _arr.size(); i++)
        {
            cout << _arr[i] << " ";
        }
    }
}