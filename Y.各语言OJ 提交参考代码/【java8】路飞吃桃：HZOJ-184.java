import java.util.Scanner;
public class Main{
    
    int Peach(int n){
        if(n==1){
            return 1;
        }
        return 2*(Peach(n-1)+1);
        
    }
    public static void main(String[] args){
        Main main = new Main();
        Scanner sc=new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(main.Peach(n)+"");
    }
}