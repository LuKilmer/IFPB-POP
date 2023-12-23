#include <bits/stdc++.h>

using namespace std;


void showVector(vector<int> var){
    for(int i = 0; i < var.size(); i++){
        cout << var[i] << " ";
    }
    cout << endl;
}
    //0
    //3
    //4

int main(){
    int num_A, num_B, aux, answer, last_A = 0,last_B = 0;
    vector<int> card_A,card_B;
    vector<int>::iterator it, it2;
    
    while(cin>> num_A >> num_B){
        answer=0;
        last_A=0;
        last_B=0;
        card_A.clear();
        card_B.clear();
        if(num_A ==0 && num_B ==0)break;
        for(int i =0; i < num_A; i++){
            cin >> aux;
            card_A.push_back(aux);
        }
        for(int i =0; i < num_B; i++){
            cin >> aux;
            card_B.push_back(aux);
        }
        if(card_B.size() > card_A.size()) {
            vector<int> temp = card_A;
            card_A = card_B;
            card_B = temp;
        }
        //showVector(card_A);
        //showVector(card_B);
        for(int i = last_A; i < card_A.size(); i++){
            it = find(card_B.begin(), card_B.end(), card_A[i]);
        
            if( it == card_B.end()){
                for (int j = last_B; j < card_B.size(); j++) {
                    it2 = find(card_A.begin(), card_A.end(), card_B[j]);
                    if (it2 == card_A.end()and card_B[j]!=card_A[i]) {  // Verifica se os elementos são diferentes
                        last_B = j+1;
                        last_A = i+1;
                        //cout << *it2 << " " << *it << endl;
                        //iter_swap(it, it2);  // Troca os elementos
                        int teste = card_A[i];
                        card_A[i] = card_B[j];
                        card_B[j] = teste;
                        //showVector(card_A);
                        //showVector(card_B);
                        answer++;
                        break;
                    }
                }
            }
        }
        cout<< answer << endl;
    }
    
    


    

    return 0;
}