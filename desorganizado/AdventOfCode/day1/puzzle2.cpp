#include <bits/stdc++.h>

using namespace std;

int main(){
    string entrada, answ;
    size_t local;
    int total=0;
    bool flag = false;
    vector<char>numbers = {'0','1','2','3','4','5','6','7','8','9'};
    vector<string>number_letter = {"one","two","three","four","five","six","seven","eight","nine"};
    while(cin>>entrada){
        answ="";
        for(int i=0; i <= entrada.length();i++){
            for(int j=0; j< number_letter.size();j++){
                local= entrada.substr(0,i).find(number_letter[j]);
                if(local!=std::string::npos){
                    answ+=to_string(j+1);
                    break;
                }
            }
            if(answ.length()==1)break;
            if (count(numbers.begin(), numbers.end(), entrada[i])) {
                answ+=entrada[i];
                break;
            }
        }

        for(int i=entrada.length(); i >= 0;i--){
            for(int j=0; j< number_letter.size();j++){
                local= entrada.substr(i,entrada.length()).find(number_letter[j]);
                if(local!=std::string::npos){
                    answ+=to_string(j+1);
                    break;
                }
            }
            if(answ.length()==2)break;
            if (count(numbers.begin(), numbers.end(), entrada[i])) {
                answ+=entrada[i];
                break;
            }
        }
        total+=stoi(answ);
        cout << answ << endl;
    }
    cout << total << endl;
    return 0;
}