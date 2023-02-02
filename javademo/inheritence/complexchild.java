public class complexchild extends complex {
     public complexchild(int real,int img){
         super( real,img);

     }
public complexchild sub(complexchild c){
 real=real-c.real;
 img=img-c.img;
 complexchild result=new complexchild(real, img);
 
 
    return result;
}
}
