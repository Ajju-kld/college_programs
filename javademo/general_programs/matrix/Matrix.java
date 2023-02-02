class Matrix{


private int row;
private int col;
private int [][]a;

public Matrix(int a[][],int row,int col)
{
   this.row=row;
   this.col=col;
   this.a=new int [row][col];
   for(int i=0;i<row;i++)
   {
       for (int j = 0; j <col; j++) {
           this.a[i][j]=a[i][j];

       }
   }


}
public Matrix(int row,int col)

{
 this.row=row;
 this.col=col;

   a=new int [row][col];
   for (int i = 0; i < a.length; i++) {
       for (int j = 0; j < a[0].length; j++) {
           a[i][j]=0;
       }
   }

}


public Matrix multiply(Matrix m){
if(this.col!=m.row){

return null;

}
Matrix result=new Matrix(this.row,m.col);
for (int i = 0; i < this.row; i++) {
    for (int j = 0; j < m.col; j++) {
        for (int k = 0; k < this.col; k++) {
            result.a[i][j]+=this.a[i][k]*m.a[k][j];
        }
    }
}



return result;


}







public void print(){


for (int i = 0; i < a.length; i++) {
    for (int j = 0; j < a[0].length; j++) {
       System.out.print(" "+a[i][j]);
    }
    System.out.println(" ");

}

}

}
