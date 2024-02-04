import java.lang.Math;

public class Math_Test {
    public static void main(String[] args) {
        int dividend = -10;
        int divisor = 3;

        // Calculate quotient and remainder using Math methods
        int quotient = Math.floorDiv(dividend, divisor);
        int remainder = Math.floorMod(dividend, divisor);

        // Print results
        System.out.println("Quotient: " + quotient);
        System.out.println("Remainder: " + remainder);
    }
}
