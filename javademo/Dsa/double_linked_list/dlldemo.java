import java.util.Scanner;

public class dlldemo {
  public static void main(String[] args) {
      doublelinkedlist d=new doublelinkedlist();
     int choice=0;
     Scanner s=new Scanner(System.in);

      do{ 
          System.out.println("enter the choice \n1.add to the list\n2.delete from the list\n3.display the list\n4.Exit: ");
          int select=s.nextInt();
switch (select) {
    case 1:System.out.print("enter the number to be inserted :");
         select=s.nextInt();
        d.append(select);
        break;
        case 2:
        System.out.print("enter the number to be deleted :");
        select = s.nextInt();
        d.deletion(select);
        break;
        case 3:
      d.display();
        break;
    case 4:
     choice=4;
        break;

    default:System.out.println("invalid choice");
        break;
}
     }while(choice!=4);
  
    }
}
