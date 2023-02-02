public class doublelinkedlist {
    class Node{
        int item;
        Node prev;
        Node next;

        public Node(int item){
            this.item=item;
            prev=null;
            next=null;
        }
    }
    private Node head;
    private Node tail;

    public doublelinkedlist(){
        head=null;
        tail=null;

    }
    
    //adding the node to the list
    
    public void append(int item){
        Node newnode=new Node(item);
        if (head==null) {
            head=newnode;
            tail=newnode;
        }
        else{
            tail.next=newnode;
            newnode.prev=tail;
            tail=newnode;
        }
    }
    //deletion of node based on matching number
    public void deletion(int item){
       
            
            Node n=head;
            while (n!=null&& n.item != item) {
                n=n.next;
            }
            if (n==null) {
                System.out.println("the number is not present");
                return;
                //list is empty
            }
            else{
              if (n==head) {
                  head=head.next;
                  head.prev=null;
              }
              else if (n==tail) {
                  tail=tail.prev;
              }
              else{
                  Node temp=n.prev;
                  temp.next=n.next;
                  temp=n.next;
                  temp.prev=n.prev;
              }
            }

    }
    //to display the list
    public void display(){
        Node n=head;
        while (n!=null) {
            System.out.print(n.item+" ");
            n=n.next;
        }
        System.out.println(" ");
    }
}
