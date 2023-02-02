class Queue {

    private int[] a;
    private int size;
    private int front, rear;

  
    public Queue(int size) {

        this.size = size;
        front = -1;
        rear = -1;
        a = new int[size];
    }

    
    
    
    // YOU SHOULD INCLUDE EXCEPTION JAVAFILE ALSO WHICH IS IN EXCEPTION DIRECTORY 
    // CREATE THE CLASS OF EXCEPTION FIRST THEN EXECUTE THIS
    
    public void Enqueue (int item)throws queue_exception {
       
       
        if (front == ((rear + 1) % size))
            throw new queue_exception("queue overflow");
    else
    {
        if (front == -1)
        {
            front = front + 1;
        }
        rear = (rear + 1) % size;
        a[rear] = item;
        System.out.println("element addded");
    }
        
      

    }

    public void Dequeue() throws queue_exception{
int item;
        if (front == -1) {
            throw new queue_exception("queue is empty");
        } 
        else 

        {
            if (front == rear) {
                item=a[front];
                front = -1;
                rear = -1;
                System.out.println(item+"is removed sucessfully");

            } else {
                 item=a[front];
                 front = (front + 1) % size;
                System.out.println(item +"is removed sucessfully");
            }
        }
    }      
  

    public void Display()throws queue_exception {
int i;
if(front==-1)
throw new queue_exception("underflow");
else
    {    for (i = front; i != rear; i = (i + 1) % size){
            System.out.print(" "+a[i]);

        }
        System.out.print(" "+a[i]+"\n");

    }
    }
}
