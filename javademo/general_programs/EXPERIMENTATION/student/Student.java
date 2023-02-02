class Student {
    private String name;
    private int rollno;

    private int Chemistry, Maths, Physics;

    public Student(String name2, int rollno, int Chemistry, int Maths, int Physics) {
        name = name2;
        this.Chemistry = Chemistry;
        this.Maths = Maths;
        this.Physics = Physics;
        this.rollno = rollno;

    }

    String Displayname() {

        return name;
    }

    int Displayroll() {
        return rollno;

    }

    int total() {

        return (Chemistry + Physics + Maths) / 3;

    }

}
