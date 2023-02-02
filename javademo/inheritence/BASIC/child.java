public class child extends parent {
    int z;
    public child(int a,int b,int c){

     super(a, b);
     z=c;

    }
    int sum(){

         return super.x+super.y+z;
    }
}
