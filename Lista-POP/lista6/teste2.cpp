#include <bits/stdc++.h>

using namespace std;

class BigInt
{
public:
    string num;
    BigInt(string a)
    {
        num = a;
    }
    void set_num(string a)
    {
        num = a;
    }

    string get_str()
    {
        return num;
    }
    int size()
    {
        return num.length();
    }
};

std::string multiplyStrings(const std::string &num1, const std::string &num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    std::string result(len1 + len2, '0');

    for (int i = len1 - 1; i >= 0; --i)
    {
        int carry = 0;
        for (int j = len2 - 1; j >= 0; --j)
        {
            int temp = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
            result[i + j + 1] = temp % 10 + '0';
            carry = temp / 10;
        }
        result[i] += carry;
    }

    // Remove leading zeros
    size_t start = result.find_first_not_of('0');
    return (start != std::string::npos) ? result.substr(start) : "0";
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

    // Remove leading zeros
    size_t start = result.find_first_not_of('0');
    result = (start != std::string::npos) ? result.substr(start) : "0";

    return result;
}

BigInt fastPow(BigInt base, BigInt num)
{
    if (num.get_str() == "0")
    {
        return BigInt("1");
    }
    

    int remainder;
    BigInt halfPower = fastPow(base, divideByTwo(num.get_str(), remainder));

    // Calcula o quadrado
    BigInt res = multiplyStrings(halfPower.get_str(), halfPower.get_str());

    
    if (remainder != 0)
    {
        // Se houver resto, multiplica pelo valor original
        res = multiplyStrings(res.get_str(), base.get_str());
    }
    if(res.get_str().length() > 7){
    res.num = res.num.substr(res.num.length() - 7);
}
    return res;
}

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

int main(){







    /*
    BigInt base("2");
    string result;
    int plasivel;
    for(int i =24; i < 31; i ++){
        BigInt num(to_string(i));
        result = fastPow(base, num).get_str();
     
        plasivel = stoi(result)-1;
        
        cout << convertToTimeFormat(plasivel) << " - "<< result << " - " <<i << endl;
    }
    BigInt num("1099511627775");
    result = fastPow(base, num).get_str();
    cout << result << endl;
    plasivel = stoi(result)-1;
    cout << convertToTimeFormat(plasivel) << " - "<< result << " - " <<32 << endl;
    */
    //num = BigInt("9999999999999999999999999999999999999999");
    //result = fastPow(base, num).get_str();
    //cout << result << endl;
    //plasivel = stoi(result)-1;
    //cout << convertToTimeFormat(plasivel) << " - "<< result << " - " <<33 << endl;

}