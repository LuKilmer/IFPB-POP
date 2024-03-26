#include <bits/stdc++.h>

using namespace std;


int presenca[9];

bool horizontal(int matriz[9][9]) {
    
    for (int i = 0; i < 9; i++) {
        for (int x = 0; x < 9; x++) {
            presenca[x] = 0;
        }

        for (int j = 0; j < 9; j++) {
            
            if (presenca[matriz[i][j] - 1] == 0) {
                presenca[matriz[i][j] - 1] = 1;
            } else {
                return false;
            }
        }
    }
    return true;
}

bool vertical(int matriz[9][9])
{

    for (int i = 0; i < 9; i++) {
        


        for (int x = 0; x < 9; x++) {
            presenca[x] = 0;
        }

        for (int j = 0; j < 9; j++) {
            
            if (presenca[matriz[j][i] - 1] == 0) {
                presenca[matriz[j][i] - 1] = 1;
            } else {
         
                return false;
            }
        }
    }
    return true;
}

bool quadrante(int matriz[9][9]) {
    for(int i = 0; i < 9; i += 3) {
        for(int j = 0; j < 9; j += 3) {
            for (int x = 0; x < 9; x++) {
                presenca[x] = 0;
            }
            for(int w = i; w < i + 3; w++) {
                for(int y = j; y < j + 3; y++) {
                    if (presenca[matriz[w][y] - 1] == 0) {
                        presenca[matriz[w][y] - 1] = 1;
                    } else {
                        
                        return false;
                    }
                }

            }
        }
    }
    return true;
}

bool verifiy(int matriz[9][9])
{
    
    if (!horizontal(matriz))
        return false;
    if (!vertical(matriz))
        return false;
    if (!quadrante(matriz))
        return false;
    
    return true;
}

int main()
{
    int test_case, aux, contador;

    cin >> test_case;

    while (test_case--)
    {
        contador++;
        int matriz[9][9];
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> aux;
                matriz[i][j] = aux;
            }
        }
        cout << "Instancia " << contador << endl;
        if (verifiy(matriz))
        {
            cout << "SIM" << endl;
        }
        else
        {
            cout << "NAO" << endl;
        }
        cout << endl;
    }
    
    return 0;
}