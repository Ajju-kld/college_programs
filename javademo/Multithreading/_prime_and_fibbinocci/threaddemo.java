class threaddemo {
    public static void main(String[] args) {
        prime p=new prime(15);
        fibinocci f=new fibinocci(10);
        Thread t1=new Thread(p);
        Thread t2=new Thread(f);
        t1.start();
        t2.start();
    }
}
