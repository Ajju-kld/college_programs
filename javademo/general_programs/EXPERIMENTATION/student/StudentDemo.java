import java.util.Scanner;

class StudentDemo {
    public static void main(String[] args) {
        try (Scanner obj = new Scanner(System.in)) {
            Student[] s;
            String name;
            System.out.println("Enter the number of student: ");
            int n = obj.nextInt();

            // name=new String[5];
            s = new Student[n];

            for (int i = 0; i < s.length; i++) {

                System.out.print("\n\nName: ");

                name = obj.next();

                System.out.print("rollno: ");

                int rollno = obj.nextInt();

                System.out.print("Maths mark:");
                int Maths = obj.nextInt();
                while (Maths > 100) {

                    System.out.print("Error : Enter the mark  out of 100: ");

                    Maths = obj.nextInt();
                }
                System.out.print("Physics mark:");
                int Physics = obj.nextInt();
                while (Physics > 100) {

                    System.out.print("Error : Enter the mark  out of 100: ");

                    Physics = obj.nextInt();
                }

                System.out.print("Chemistry mark:");
                int Chemistry = obj.nextInt();

                while (Chemistry > 100) {

                    System.out.print("Error : Enter the mark  out of 100: ");

                    Chemistry = obj.nextInt();
                }

                s[i] = new Student(name, rollno, Chemistry, Maths, Physics);
            }
            int flag = 0;
            System.out.println("\t\t\t<------------Student who Qualified for writing the Entrance Exam------------>\n");
            for (int i = 0; i < s.length; i++) {

                if (s[i].total() > 71) {
                    flag = 1;
                    System.out.print("\nRollno:" + s[i].Displayroll() + "\nName:" + s[i].Displayname() + "\n");

                }
            }

            if (flag != 1)
                System.out.print("No Students are eligible for the exam\n");
        }
    }
}
