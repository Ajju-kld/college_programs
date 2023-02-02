public class rectangle implements shape {
    private int length,width;

public rectangle(int length,int width){
    this.length=length;
    this.width=width;
}
public double area(){
    return (double)(length*width);
}
public int perimeter(){
    return 2*(length+width);
}
public void print(){
    System.out.println("rectangle \narea: "+area()+"\nperimeter: "+perimeter());
}
}
