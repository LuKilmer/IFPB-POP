import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Scanner;

public class Main1021 {
    
    public static void main(String[] args) throws IOException {
        DecimalFormat formato = new DecimalFormat("0.00");
        int[] notas = new int[12];
        notas[0]=10000;
        notas[1]=5000;
        notas[2]=2000;
        notas[3]=1000;
        notas[4]=500;
        notas[5]=200;
        notas[6]=100;
        notas[7]=50;
        notas[8]=25;
        notas[9]=10;
        notas[10]=5;
        notas[11]=1;
        Scanner leitor = new Scanner(System.in);
        int numero = 0;
        float preco_input = Float.parseFloat(leitor.nextLine());
        int preco = (int) (preco_input*100);
        System.out.println("NOTAS:");
        System.out.println(preco);
        for(int i=0; i<6;i++){
            numero=preco/notas[i];
            preco= preco%notas[i];
            System.out.println(numero+ " nota(s) de R$ "+ (formato.format(notas[i]/100)).replace(",","."));
        }
        System.out.println("MOEDAS:");
        for(int i = 6; i<12; i++){
            numero=preco/notas[i];
            preco= preco%notas[i];
            System.out.println(numero+ " moeda(s) de R$ "+ (formato.format((float)notas[i]/100)).replace(",","."));
        }
        leitor.close();
    }
}
