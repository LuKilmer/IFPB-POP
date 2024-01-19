#include <bits/stdc++.h>
#include <vector>
using namespace std;

void print_vector(vector<int> vec){
    for(auto &n: vec){
        printf("%d ",n);
        
    }
    printf("\n");
}


int main() 
{
	vector<int> v; 
	v.push_back(1); 
	v.push_back(3);
	v.push_back(5); 
	v.push_back(7); 

    print_vector(v);

    v.insert(v.begin() + 2,23);

    print_vector(v);

    v.clear();

    for(int i=1; i<8;i++){v.push_back(i*i);}

    print_vector(v);

    v.erase(v.begin()+3);

    printf("Removido:\n");
    print_vector(v);

    v.erase(v.begin()+1,v.begin()+3);

    printf("Removido 3 itens do vetor:\n");
    print_vector(v);

    v.clear();

    printf("Novos elementos randomizados:\n");

    for(int i=0; i< 20; i++){v.push_back((rand()%100+10));}

    print_vector(v);

    printf("Organizando...\n");

    sort(v.begin(),v.end());

    print_vector(v);

    print_vector(v);

    v.resize(10);
    
    printf("Mudando o tamanho\n");
    
    print_vector(v);

    v.resize(15, 0);

    print_vector(v);

	return 0;
}