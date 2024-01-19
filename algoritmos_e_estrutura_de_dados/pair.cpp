#include <bits/stdc++.h>
using namespace std;

int main() 
{
    vector<pair< pair<int, string>, int> > v; 
  
    v.push_back({{1,"ANA"},10}); 
    v.push_back({{2,"BRUNO"},4}); 
    v.push_back({{3,"CAIO"},7}); 
    for(int i=0; i<(int)v.size(); i++) 
    {
        printf("Numero: %d, Nome: %s, Nota: %d\n", v[i].first.first, v[i].first.second.c_str(), v[i].second);
    }
    pair<int, string> A = {10, "Thiago"};
	pair<int, string> B = {20, "Lawrence"};
	pair<int, string> C = {20, "Davi"};

	if(A > B) {
		printf("A maior que B\n");
	}
	if(C < B){
		printf("C menor que B\n");
	}
    pair<string, int> Aa = {"Thiago", 20};
	pair<string, int> Ba = {"Lawrence", 14};
	pair<string, int> Ca = {"Davi",25};

	if(Aa > Ba) {
		printf("A maior que B\n");
	}
	if(Ca < Ba){
		printf("C menor que B\n");
	}
    return 0;
}