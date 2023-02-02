import java.util.Scanner;

public class quicksort {
    public static void quicksorts(String[]strings,int first,int last){

if(first<last)
        {int i=first;
int j=last;
String pivot=strings[first];
while (i<j) {
    while((i<last)&&strings[i].compareTo(pivot)<=0)
    i++;
    while(strings[j].compareTo(pivot)>0)
    j--;
    if (i<j) {
        String a=strings[i];
        strings[i]=strings[j];
        strings[j]=a;
        
    }
    
}
strings[first]=strings[j];
strings[j]=pivot;
quicksorts(strings, first,j-1);
quicksorts(strings, j+1, last);
    }
    }
public static void main(String[] args) {
    Scanner s=new Scanner(System.in);
  
    System.out.println("enter the number of names: ");
    int n=s.nextInt();
    String[] samples=new String[n];
    for (int i = 0; i < samples.length; i++) {
          samples[i]=s.next();
    }
    System.out.println(" ");
quicksorts(samples,0,samples.length-1);
for (int i = 0; i < samples.length; i++) {
    System.out.println(samples[i]);
}
}
}
