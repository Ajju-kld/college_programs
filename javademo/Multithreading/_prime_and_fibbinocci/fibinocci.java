class fibinocci implements Runnable{
    private int n;
     public fibinocci(int n) {
         this.n=n;
     }   
     public synchronized void run(){
         int a=0;
         int b=1,c;
         System.out.println("fibinocci:"+a);
         System.out.println("fibinocci:"+b);
         for(int i=2;i<n;i++){
             c=a+b;
             System.out.println("fibinocci:"+c);
             a=b;b=c;
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.err.println("error");
            } 
        finally{
            System.out.println("hello world"
            );
        }
         }
     }
}
