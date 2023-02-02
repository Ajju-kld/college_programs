public class inheritance {
    public static void main(String[] args) {
        
        complexchild c1=new complexchild(5, 450);
           complexchild c2=new complexchild(3, 300);
           complexchild c=c1.sub(c2);
           c.display();
           complexchild c3=(complexchild) c.add(c1);
    c3.display();
        }
     

    
}
