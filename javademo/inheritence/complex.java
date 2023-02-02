public class complex {
    protected int real,img;
    public complex(int real,int img){
        this.img=img;
        this.real=real;
    }
    public complex add(complex c){
        int real=this.real+c.real;
        int img=this.img+c.real;
        complex result=new complex(real, img);
        return result;
    }
    public void display(){
        System.out.println(real+"+"+img+"i");
    }
}
