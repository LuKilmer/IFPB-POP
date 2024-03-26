#include <bits/stdc++.h>

using namespace std;


int get_total(vector<int> &arr){
    int answer = 0;
    int index=0, max_s = arr.size()-1;
    while(max_s-index>index){
        //cout << arr[max_s - index] << " " << arr[index] << endl;
        answer+=(arr[max_s - index]-arr[index]);
        index++;
    }
    return answer;

}

int main(){
    int test_case, arr_size, aux;
    cin >> test_case;
    while(test_case--){
        cin >> arr_size;
        vector<int> arr(arr_size);
        while(arr_size--){
            cin >> aux;
            arr[arr_size]= aux;
        }
        sort(arr.begin(),arr.end());
        cout << get_total(arr) << endl;
        //show(arr);
        
    }
    return 0;
}