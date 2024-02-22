#include <bits/stdc++.h> 
using namespace std; 

int max(int a, int b) { return (a > b) ? a : b; } 

int knapSack(vector<pair<int,int>>&lista, int capacity, int n)
{ 

    if (n == 0 || capacity == 0) 
        return 0; 
  

    if (lista[n - 1].first > capacity) 
        return knapSack(lista, capacity, n - 1); 
  
    else
return max(lista[n - 1].second + knapSack(lista, capacity - lista[n - 1].first, n - 1), knapSack(lista, capacity, n - 1));
} 
  

int main() 
{ 
    int n, capacity;
    cin >> n >> capacity;
    vector<pair<int,int>>lista;
    pair<int,int>aux;
    for(int i=0; i < n; i++){
        cin>> aux.first>> aux.second;
        if(aux.first<=capacity)lista.push_back(aux);
    }
    cout << lista.size()<<endl;
    cout << knapSack(lista, capacity, n)<<endl; 
    return 0; 
} 
  
