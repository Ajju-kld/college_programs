class prime implements Runnable  {
    private int n;
    public prime(int n){
        this.n=n;
    
    }
  public synchronized  void run(){
        
             for(int i=2;i<=n;i++)
{             int flag=0;
           for(int j=2;j<i;j++)
             {
                 if(i%j==0){ flag=1;
                 break;}
             }
             if(flag==0)
             System.out.println("prime number : "+i);
      
}
  }}