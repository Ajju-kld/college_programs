class Queue {

    private int[] a;
    private int size;
    private int front, rear;

    public Queue() {

        size = 5;
        front = -1;
        rear = -1;

        a = new int[size];

    }

    public Queue(int size) {

        this.size = size;
        front = -1;
        rear = -1;
        a = new int[size];
    }

    
    
    
    
    public void Enqueue(int item) {
       
       
       
        if (rear != size - 1) {
            rear = rear + 1;
            a[rear] = item;
            if (front == -1) {

                front =front+1;


            }
            System.out.println("elemented added successfully");
        }
        
        else {
            
       System.out.println("overflow");
        }

    }

    public void Dequeue(int item) {

        if (front == -1) {
            System.out.print("queue is empty");
        } 
        else if (item==a[front])

        {
            if (front == rear) {
                front = -1;
                rear = -1;
                System.out.println("element removed sucessfully");

            } else {

                front = front + 1;
                System.out.println("element removed sucessfully");
            }
        }
        
    else
        System.out.println("element not found");

    }

    public void Display() {

        for (int i = front; i <= rear; i++) {
            System.out.println(a[i]);

        }

    }

}