

class paliendrome {
 public static void main(String[] args) {



String s="malayalam";


int i=0;
System.err.println(s.length());
int j=s.length()-1;
while (i<j) {
    if (s.charAt(i)!=s.charAt(j)) 
    break;
    i++;
    j--;
        
    
}
if (i>=j) {
    System.out.println("paliendrome");
}
else System.out.println("not paliendrome");
}    
}
