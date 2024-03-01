#include <bits/stdc++.h>

using namespace std;

string convertToTimeFormat(int seconds)
{
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int remainingSeconds = seconds % 60;
    
    hours%=23;
    
    std::ostringstream formattedTime;
    formattedTime << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << ":"
                  << std::setw(2) << std::setfill('0') << remainingSeconds;

    return formattedTime.str();
}

int fastPow(int base, int num)
{
    if (num == 0)
    {
        return 1;
    }
    int res = fastPow(base, num / 2);
    res *= res;
    if (num % 2 != 0)
    {
        res *= base;
    }
    return res;
}

int main()
{

    for(int i = 24; i < 31; i++){
        int num = fastPow(2,i)-1;
        cout << convertToTimeFormat(num)<<" - "<< num+1<< " - "<< i << endl;
    }
    return 0;
}