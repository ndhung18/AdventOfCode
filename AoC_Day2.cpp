#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ifstream file("input/day2_input.txt");

    if (file.is_open())
    {
        vector<string> arr;
        string val;
        while (getline(file, val))
        {
            if (file)
                arr.push_back(val);
            else
                break;
        }
        vector<int> _arr;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == "A X")
                sum += 3;
            if (arr[i] == "A Y")
                sum += 4;
            if (arr[i] == "A Z")
                sum += 8;
            if (arr[i] == "B X")
                sum += 1;
            if (arr[i] == "B Y")
                sum += 5;
            if (arr[i] == "B Z")
                sum += 9;
            if (arr[i] == "C X")
                sum += 2;
            if (arr[i] == "C Y")
                sum += 6;
            if (arr[i] == "C Z")
                sum += 7;
        }
        cout << sum;
    }
}