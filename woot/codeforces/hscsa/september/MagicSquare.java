import java.util.Scanner;

public class MagicSquare {
    public static int[][] base = new int[][]{
        { 0, 5, 4 },
        { 7, 3, -1 },
        { 2, 1, 6 }
    };

    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        long k = s.nextLong();

        StringBuilder str = new StringBuilder();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                str.append(k + base[i][j]);
                if(j != 2) str.append(" ");
            }
            str.append("\n");
        }

        System.out.println(str);
    }
}