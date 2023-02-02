public class CarParameters {
    private String name;
    private String model;
    private double price;
    private int year = 2011;
    private String color;

    public CarParameters setName(String name) {
        this.name = name;
        return this;
    }

    public CarParameters setModel(String model) {
        this.model = model;
        return this;
    }

    public CarParameters setPrice(double price) {
        this.price = price;
        return this;
    }

    public CarParameters setYear(int year) {
        this.year = year;
        return this;
    }

    public CarParameters setColor(String color) {
        this.color = color;
        return this;
    }
    void printdetails(){
        System.out.println(name);
        System.out.println(model);
        System.out.println(price);
        System.out.println(color);
    
    }
}
// to make it shorter getters was omitted}