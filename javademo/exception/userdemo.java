public class userdemo {
    public static void main(String[] args) {
    
        String a="a";

try {
    hello(a);
} catch (userexception e) {
    System.out.println(e);
}
      
    }
    
    public static void hello(String a) throws userexception {
        if(a=="a"){
            throw new userexception("single letter");
        }
        else
        System.out.println(a);

    }
}
