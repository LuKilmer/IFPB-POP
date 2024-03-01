import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Scanner;

public class Main1040 {
    public static void main(String[] args) throws IOException {
        Scanner leitor = new Scanner(System.in);
        DecimalFormat formato = new DecimalFormat("0.00");

        // Lê as notas e calcula a média
        double notas = converterParaDouble(leitor.nextLine().split(" "));

        System.out.println("Media: " + formato.format(notas));

        if (notas >= 7.0) {
            System.out.println("Aluno aprovado.");
        } else if (notas >= 5.0) {
            System.out.println("Aluno em exame.");
            double nota_final = Double.parseDouble(leitor.nextLine());
            System.out.println("Nota do exame: " + nota_final);
            nota_final = (notas + nota_final) / 2;
            
            if (nota_final >= 5.0) {
                System.out.println("Aluno aprovado.");
            } else {
                System.out.println("Aluno reprovado.");
            }

            // Imprime a média final formatada
            System.out.println("Media final: " + formato.format(nota_final));
        } else {
            System.out.println("Aluno reprovado.");
        }

        leitor.close();
    }

    // Método para converter array de String para array de double
    public static double converterParaDouble(String[] arrayDeStrings) {
        double[] resultado = new double[arrayDeStrings.length];
        double total = 0;

        for (int i = 0; i < arrayDeStrings.length; i++) {
            resultado[i] = Double.parseDouble(arrayDeStrings[i]);
        }

        total += resultado[0] * 2;
        total += resultado[1] * 3;
        total += resultado[2] * 4;
        total += resultado[3] * 1;

        return total / 10.0;
    }
}
