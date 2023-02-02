/**a 
 * what is happening write now
 */
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Stack;

import org.junit.platform.commons.util.ToStringBuilder;

class helloworld{
    public static void main(String[] args) {
        System.out.println("enter the name: ");
        String a=System.console().readLine();
       int y=5;
        PrintWriter write;
        try {
            write = new PrintWriter("/home/ajmal/projects/codes/javademo/test.txt");
            write.write("i am a robot 55");
            write.flush();
                      write.close();
                      File obj=new File("/home/ajmal/projects/codes/javademo/hello.txt");
                      obj.createNewFile();
                      FileWriter w=new FileWriter("/home/ajmal/projects/codes/javademo/hello.txt");
                      w.write("hello how are you");
                      w.flush();
                      w.close();
                      File m= new File("/home/ajmal/projects/codes/javademo/hello.txt");
                      obj.renameTo(m);
                      String s=" ";
                      Scanner w1=new Scanner(obj);
                    while (w1.hasNext()) {
                         s = s+w1.nextLine();

                    }
                     System.out.println(s);
                     System.out.println(obj.canRead());
                     System.out.println(obj.exists());
                     System.out.println(obj.length());
String b[]=s.split(" ");
StringBuffer g=new StringBuffer("123");
//int d= Integer.parseInt(g);
byte []t={97,98,111,68};
String r=new String(t);
StringBuffer f=new StringBuffer(r);
if(f==g){
    System.out.println("equal");
}
else 
System.out.println("not equal");
for (String sg:b) {
    System.out.println(sg);
}
System.out.println(r);
Stack D=new Stack<>();
D.add("hello");
D.add(45);

System.out.println(D);
        } 
        catch (IOException e) {



    


            
        }
        
   ArrayList<Integer> h=new ArrayList<>();
     LinkedList<Integer> li=new LinkedList<>();
li.add(45);
li.add(41);
li.add(47);
     System.out.println(li); 

    }
}