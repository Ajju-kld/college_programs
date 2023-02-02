public class linkedlist {
          private int info;
          private linkedlist link ;
       
public linkedlist(int item) {
    this.info=item;
    this.link = null;
    
}
public linkedlist(){
         this.info=0;
         this.link=null;
}
public linkedlist add_at_begining(int item,linkedlist header){
  linkedlist newnode= new linkedlist(item);
    if(header!=null){
      newnode.link=header;
      header=newnode;
      
    }
    else{
        header=newnode;
    }
    return header;
}


public linkedlist add_at_end(int item,linkedlist header){
  linkedlist newnode=new linkedlist(item);
     
    if(header==null)
{   header=newnode;  }
else{
    linkedlist demo=header;
    while(demo.link!=null)
    {    demo=demo.link;}
    demo.link=newnode;
}

return header;
}





public void printf(linkedlist header){
if (header.link!=null){
  linkedlist li =header;
   while (li!=null) {
       System.out.print("\t"+li.info);
       li=li.link;
   }
}
 else System.out.println("list is empty");

}


public linkedlist add_in_sort(int item,linkedlist header){

    linkedlist newnode=new linkedlist(item);
   if(header!=null)
     {
            linkedlist next=header;
            linkedlist prev=null;
            while(next!=null&&next.info<item){
                prev=next;
                next=next.link;
            }
           if (prev==null) {
               newnode.link=next;
               header=newnode;
           }
           else{
               prev.link=newnode;
               newnode.link=next;
           }

     }
     else header=newnode;


    return header;
}


public linkedlist delete_from_front(linkedlist header)
{
    if(header!=null){  
        linkedlist temp=header;
        header=temp.link;
     
    }
    else System.out.println("list is empty");
return header;
}
public linkedlist delete_from_end(linkedlist header){
    if(header==null){
        System.out.println("list is empty");
    }
    else{
        linkedlist l1=header;
        linkedlist l2=null; 
        while(l1.link!=null){
            l2=l1;
            l1=l1.link;
        }
        l2.link=null;
        l1=null;
    }
    return header;
}

}