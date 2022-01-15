class MatrixDemo{
    public static void main(String[] args) {
       int [][]a={{11,22,10},{21,22,52},{25,32,44}};    

       int [][]b={{1,2,3},{1,4,5},{5,6,7}};    
      Matrix m1=new Matrix(a,a.length,a[0].length);
      Matrix m2= new Matrix(b,b.length,b[0].length);
      Matrix m3= m1.multiply(m2);
      if(m3!=null){
       m3.print();


      }
      else {
          System.out.print("not possible");
      }
    }
        
}