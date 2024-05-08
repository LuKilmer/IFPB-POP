#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> get_answer(const vector<int>& nums) {
    int N = nums.size();
    vector<int> sup(N + 1, INT_MAX);
    vector<int> aux;
    sup[0] = -INT_MAX;
    int answer = 0;
    for (int i = 0; i < N; i++) {
        auto it = lower_bound(sup.begin(), sup.end(), nums[i]);
        int menor = it - sup.begin();
        sup[menor] = nums[i];
        if (menor > answer) {
            answer = menor;
        }
        aux.push_back(menor);
    }
    cout << answer << endl<<"-"<<endl;
    vector<int> result(answer);
    N--;
    while (aux[N] != answer){N--;}

    int top = answer - 1;
    result[top] = nums[N];

    for (int j = N - 1; j >= 0; j--) {
        if (aux[j] == aux[N] - 1 && nums[j] < nums[N]) {
                result[--top] = nums[j];
                N = j;
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> nums;
    int item;
    
    while (cin >> item) {
        nums.push_back(item);
    }
    vector<int> result = get_answer(nums);

    for(int i: result){
        cout << i << endl;
    }
    return 0;
}
