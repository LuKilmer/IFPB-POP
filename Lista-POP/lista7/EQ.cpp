#include <bits/stdc++.h>

using namespace std;

bool checkpart(vector<char> &cores,int start, int jumper){
    int contador = 0;

    bool flag = false;
    return flag;

}

void pintador(vector<char>& cores, int start, int jump) {
    while (start < cores.size() && jump > 0) {
        cores[start] = 'W';
        start++;
        jump--; 
    }
}
void show(vector<char> cores){
    for(char com: cores){
        cout << com << " ";
    }
    cout << endl;
}
int get_answer(vector<char> cores, int jump){
    int answer = 0;
    int array_size = cores.size();
    int contador =0;
    //show(cores);
    while(contador < array_size){
        if(cores[contador]=='B'){
            pintador(cores,contador, jump);
            //show(cores);
            contador+=jump;
            answer++;
        }else{
            contador++;
        }
        
    }

    return answer;
}


int main(){
    int test_case, jump, papers; string linha;
    cin >> test_case;
    while(test_case--){
        cin >> papers >> jump;
        cin >> linha;
        vector<char> cores;
        for (char c : linha) {
            cores.push_back(c);
        }
        cout << get_answer(cores, jump) << endl;
    }



    return 0;
}