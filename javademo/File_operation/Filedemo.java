import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Scanner;

/**
 * Filedemo
 */
public class Filedemo {
public static void main(String[] args) {
try {
    
    FileInputStream s =new FileInputStream("/home/ajmal/projects/codes/javademo/hello.txt");
    FileOutputStream d=new FileOutputStream("/home/ajmal/projects/codes/javademo/test.txt");
  byte [] b=s.readAllBytes();
   d.write(b);
   d.close();
   s.close();
   } catch (Exception e) {
    //TODO: handle exception
}
}
    
}