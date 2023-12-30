#include <bits/stdc++.h>

using namespace std;

int main(){
    int atual = 0, meta = 0, aux, total = 0, media = 0, answer = 0;
    queue<int> mes;
    
    cin >> atual >> meta;
    
    for(int i = 0; i < 30; i++){
        cin >> aux;
        mes.push(aux);
        total += aux;
    }

    if (total > 0) {
        media = static_cast<int>(ceil(static_cast<double>(total) / 30));
    }

    while(atual < meta && media > 0){
        atual += media;
        total -= mes.front();
        mes.pop();
        mes.push(media);
        total += media;

        media = static_cast<int>(ceil(static_cast<double>(total) / 30));
        answer++;
    }

    cout << answer << endl;
    return 0;
}
