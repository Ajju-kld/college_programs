

class shapedemo {
public static void main(String[] args) {
     shape[] s=new shape[5]; 
       s[0]=new circle(4);
       s[1]=new rectangle(10, 14);
       s[2]=new circle(6);
       s[3]=new rectangle(11, 2);
       s[4]=new circle(3);
       sort(s); 
       System.out.println("sort based on area\n");    
     for (int i = 0; i < s.length; i++) {
         s[i].print();
         System.out.println(" ");
     }

    }

   public static void sort(shape s[]){
     for (int i = 0; i < s.length; i++) {
         for (int j= i; j< s.length; j++) {
             if(s[i].area()>s[j].area())
             {shape temp=s[i];
            s[i]=s[j];
        s[j]=temp;
        }
           }
                }
                    }
                          }
