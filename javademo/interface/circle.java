public class circle implements shape {
    private int radius;
 public circle(int radius){
     this.radius=radius;
 }
 
 public double area() {
          
     return 3.14*radius*radius;
 }
 
 public int perimeter() {
      
     return (int)(2*3.14*radius);
 }
 
 public void print() {
     System.out.println("Circle \n area: "+area()+"\nperimeter: "+perimeter());
     
 }
}
