#include <bits/stdc++.h>

using namespace std;

bool compareFunction (string a, string b) {return a<b;}


int main(){
    vector<string> dicionar;
    vector<string>::iterator it;
    string sop="";
    string aux, sup;
    while(cin >> aux){
      
        for(char term: aux){

            if(isalpha(term)){
                sop+=tolower(term);
            }else{
                if(sop.size()!=0){
                    if(find(dicionar.begin(), dicionar.end(), sop)== dicionar.end()){dicionar.push_back(sop);}
                    sop="";
                }
                
            }
        }
        if(sop.size()!=0){
            if(find(dicionar.begin(), dicionar.end(), sop)== dicionar.end()){dicionar.push_back(sop);}
            sop="";
        }
    }
    
    sort(dicionar.begin(),dicionar.end(),compareFunction);
    for(string seila: dicionar){
        cout << seila << endl;
    }
 
    return 0;
}