/**
 * car
 */
public class car {

    public static void main(String[] args) {
        CarParameters factory= new CarParameters().
        setColor("yellow").
        setModel("modelt").
        setName("ford").
        setPrice(15000).
        setYear(10);
        factory.printdetails();


    }
}