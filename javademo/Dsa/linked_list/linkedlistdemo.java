import java.util.Scanner;
class linkedlistdemo {
    public static void main(String[] args) {
        try (Scanner item = new Scanner(System.in)) {
          
            linkedlist list = new linkedlist();
   int choice,repeat=1,items;
   
  while (repeat==1) {
     System.out.println("1.add at begining\n2.add at end\n3.add in sort\n4.display\n5.delete from front\n6.delete from end\n7.exit");
     choice=item.nextInt();
     switch (choice) {
              case 1:System.out.println("enter the info to be added");
                  items=item.nextInt();
                  list=list.add_at_begining(items, list);
                  break;
                  case 2:
                      System.out.println("enter the info to be added");
                      items = item.nextInt();
                      list=list.add_at_end(items, list);
                  break;
                  case 3:
                  System.out.println("enter the info to be added");
                  items=item.nextInt();
                  list=list.add_in_sort(items, list);
                     break;

                  case 4:list.printf(list);
                  System.out.println(" ");

                  break;
                  case 5:
                         list=list.delete_from_front(list);
                  break;
                  case 6: list=list.delete_from_end(list);

                  break;
                  case 7:
                  repeat=0;

                  break;
     
              default:
                  break;
     }
  }
        }





}
}
