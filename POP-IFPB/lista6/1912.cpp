#include <bits/stdc++.h>

using namespace std;

double answer;

double calculateTotalArea(const vector<double> &papelao, double corte)
{
    double total = 0.0;
    for (double aux : papelao)
    {
        if (aux >= corte)
        {
            total += (aux - corte);
        }
    }
    return total;
}


double cortacorta(const vector<double>& papelao, double limit, double menor, double maior) {
   

    if (menor <= maior) {
        double meio = menor + (maior - menor) / 2;
        double totalArea = calculateTotalArea(papelao, meio);

        if (abs(totalArea - limit) < 0.000001){
            return meio; 
        } else if (totalArea < limit) {
            return cortacorta(papelao, limit, menor, meio - 0.000001);
        } else {
            return cortacorta(papelao, limit, meio + 0.000001, maior);
        }
    }

 
    return maior;
}




int main(int argc, char *argv[]){
    int counter = std::stoi(argv[1]);
    std::string path = "../output/1912/output" + std::to_string(counter) + ".txt";
    std::ofstream outputFile(path);
    std::ostream& out = outputFile;

    int test_case, limit, num, total, maior, menor;
    vector<double> papelao;
    cin >> test_case >> limit;
    while (test_case != 0 && limit != 0)
    {
        total = 0;
        maior = 0;
        papelao.clear();
        while (test_case--){
            cin >> num;
            total += num;
            if (maior < num)
                maior = num;
            if (menor > num)
                menor = num;

            papelao.push_back(num);
        }
        if (total == limit)
        {
            out << ":D\n";
        }
        else if (total < limit)
        {
            out << "-.-\n";
        }
        else{
            answer = cortacorta(papelao, limit, 0.0, maior);
            //answer = findCutHeight(papelao,limit );
            //float floatValue = static_cast<float>(answer);
            if(answer<10){
                out << std::fixed << std::setw(5) << std::setprecision(4) << answer << std::endl;
            }else{
                out << std::fixed << std::setw(7) << std::setprecision(4) << answer << std::endl;
            }
            

        }

        cin >> test_case >> limit;
    }

    return 0;
}