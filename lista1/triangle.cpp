#include <bits/stdc++.h>

using namespace std;

int main(){
    float A,B,C;
    scanf("%f %f %f", &A,&B,&C);
    float aux;
    if(B>A and B>C){
        aux = A;
        A = B;
        B = aux;
    } 
    else if(C>A and C > B){
        aux = A;
        A = C;
        C= aux;
    } 
    if(A >= B+C)printf("NAO FORMA TRIANGULO\n");
    else{
        float BC = pow(B,2) + pow(C,2);
        if(pow(A,2) == BC)printf("TRIANGULO RETANGULO\n");
        else if(pow(A,2) > BC)printf("TRIANGULO OBTUSANGULO\n");
        else if(pow(A,2) < BC)printf("TRIANGULO ACUTANGULO\n");
        if(A == B and B == C)printf("TRIANGULO EQUILATERO\n");
        if(A == C and B != A)printf("TRIANGULO ISOSCELES\n");
        else if(C == B and B != A)printf("TRIANGULO ISOSCELES\n");
        else if(A == B and B != C)printf("TRIANGULO ISOSCELES\n");
    }
    return 0;
}