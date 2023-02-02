import java.util.Scanner;

/**
 * demo
 */
public class demo {

    public static void main(String[] args) {
        String a;
        Scanner d=new Scanner(System.in);
        System.out.println("enter the integer array");
        a=d.next();
        a=a.toLowerCase();
        int count;
        String h=new String();
        char m;
        for (int i = 0; i < a.length(); i++) {
            m=a.charAt(i);
            count=0;
            for (int j = 0; j < a.length(); j++) {
                if (a.charAt(j)==m) {
                    count=count+1;
                }
            }
         

            String f=String.valueOf(m);
            if (!h.contains(f)) {
                System.out.println("the occurence of " + m + " is :" + count);
                h=h.concat(f);     
            }
           
        }
    }
}