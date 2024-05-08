#include <bits/stdc++.h>

using namespace std;

int m = 24* 60 * 60;
string multiplyStrings(const string& num1, const string& num2) {
    long long len1 = num1.length();
    long long len2 = num2.length();
    long long result[len1 + len2] = {0};  

    for (long long i = len1 - 1; i >= 0; i--) {
        for (long long j = len2 - 1; j >= 0; j--) {
            long long mul = (num1[i] - '0') * (num2[j] - '0');
            long long sum = result[i + j + 1] + mul;

            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10;
        }
    }

    string finalResult = "";
    for (long long digit : result) {
        finalResult += to_string(digit);
    }

    finalResult.erase(0, finalResult.find_first_not_of('0'));

    string finalNumber = to_string(stoll(finalResult) % m);

    return finalNumber;
}
std::string divideByTwo(const std::string& num, int& remainder) {
    std::string result;
    remainder = 0;

    for (char digit : num) {
        int currentDigit = digit - '0';
        int currentResult = (currentDigit + remainder * 10) / 2;
        result.push_back('0' + currentResult);
        remainder = (currentDigit + remainder * 10) % 2;
    }


    size_t start = result.find_first_not_of('0');
    result = (start != std::string::npos) ? result.substr(start) : "0";

    return result;
}

string fastPow(string base, string num)
{
    if (num == "0")
    {
        return "1";
    }
    

    int remainder;
    string halfPower = fastPow(base, divideByTwo(num, remainder));

    string res = multiplyStrings(halfPower, halfPower);

    
    if (remainder != 0)
    {
        res = multiplyStrings(res, base);
    }
    
    return res;
}
string convertToTimeFormat(long long seconds)
{
    seconds-=1;
    long long hours = seconds / 3600;
    long long minutes = (seconds % 3600) / 60;
    long long remainingSeconds = seconds % 60;
    
    hours%=23;
    
    std::ostringstream formattedTime;
    formattedTime << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << ":"
                  << std::setw(2) << std::setfill('0') << remainingSeconds;

    return formattedTime.str();
}
int main(){
    string num;
    string base ="2";
    cin >> num;
    string result = fastPow(base, num);
    
    cout << convertToTimeFormat(stoll(result) )<<endl;
    
    return 0;
    //7464960000
    //86400
}