#include <bits/stdc++.h>

using namespace std;

int main()
{
    int atual, meta, metric, answer;
    int total = 0;

    int aux = 0;
    cin >> atual >> meta;
 
    for (int i = 0; i < 30; i++)
    {
        cin >> metric;

        total += metric;
    }
    total = static_cast<int>(ceil(static_cast<double>(total) / 30));
    while (atual < meta)
    {
        //this_thread::sleep_for(chrono::seconds(1));
        if (total * 30 + atual < meta){
            answer += 30;
            atual += total * 30;
            
        }else{
            for(int i =0; i < 29;i++){
                if(atual>=meta){
                    break;
                }else{
                    atual+=total;
                    answer++;
                }
            }
        }
    }

    cout << answer << endl;
    return 0;
}