#include <bits/stdc++.h>

using namespace std;
#define MAXSIZE 1000010

int twins[MAXSIZE];

void sieveOfEratosthenes(int limit, vector<int> &primes) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}
int getResult(int minimum, int maximum){
    return twins[maximum] - twins[minimum-1];
}

void fullTwis( vector<int> &primes) {
    int index=1;
    int next_twin=0;
    int total = 0;
    bool flag = false;

    for(int i = 3; i <= MAXSIZE; i++){
        if(i==primes[index]){
            if(primes[index+1]-primes[index]==2 || primes[index]-primes[index-1]==2){
                total++;
            }
            index++;
        }
        twins[i]=total;
    }
}

int main() {
    ofstream outputFile("output.txt");
    ostream& out = outputFile;
    auto start = chrono::high_resolution_clock::now();
    vector<int> primes;
    int test_case;
    sieveOfEratosthenes(MAXSIZE,primes);
    fullTwis(primes);
    int minimum, maximum;
    cin >> test_case;
    while (test_case--){
        cin >> minimum >> maximum;

        if (minimum > maximum)
        {
            minimum ^= maximum;
            maximum ^= minimum;
            minimum ^= maximum;
        }
        //out <<maximum<<" "<<minimum<<" "<<twins[maximum]<<" "<<twins[minimum]<<" "<<  twins[maximum] - twins[minimum-1]<<endl;
        out << twins[maximum] - twins[minimum-1]<<endl;
    }
    
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Tempo de execucao: " << fixed << setprecision(3) << (double)duration.count() / 1000000 << " segundos." << endl;

    return 0;
}

//1
//4
//1