class QueueDemo{
   public static void main(String[] args){
    Queue q1=new Queue(4);
  try {
     q1.Enqueue(5);
     q1.Enqueue(6);
     q1.Enqueue(12);
     q1.Enqueue(7);
     //q1.Enqueue(7);
     q1.Display();
    q1.Dequeue();
     //q1.Enqueue(5);
     q1.Enqueue(6);
     q1.Enqueue(5);
     //q1.Enqueue(6);
     /*
      * q1.Dequeue();
      * q1.Dequeue();
      * q1.Dequeue();
      * q1.Dequeue();
      */
     q1.Display();
     
  } catch (queue_exception e) {
   System.out.println(e);
  }  


   }



}