public class stack {
    private int top,size;
    private int[] a;
    public stack(int size)
    {
        top=-1;
        this.size=size;
        a=new int[size];
    }
    public void push(int item) {
           if(top<size-1){
               top=top+1;
               a[top]=item;
           
    
            }
    else{
       System.out.println("the stack is full");
    }
        }
        public int pop(){
            if (top>=0) {
                int item=a[top];
                top=top-1;
                return item;
            }
            else{
                System.out.println("the stack is empty");
            return 0;
            }
        }
        public void display(){
        for (int i = top; i>=0; i--) {
            System.out.println(a[i]);
        }
        }

}

