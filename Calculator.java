public class Calculator {
    // Addition method
    public static void add(Decimal num1, Decimal num2) {
        System.debug( num1 + num2);
    }
    // Subtraction method
    public static Decimal subtract(Decimal num1, Decimal num2) {
        return num1 - num2;
    }
    // Multiplication method
    public static void multiply(Decimal num1, Decimal num2) {
        System.debug( num1 * num2);
    }
    // Division method
    public static Decimal divide(Decimal num1, Decimal num2) {
        if(num2 == 0) {
            throw new System.MathException('Cannot divide by zero');
        }
        return num1 / num2;
    }
    // Modulus method
    public static void modulus(Decimal num1, Decimal num2) {
        Integer intNum1 = num1.intValue();
        Integer intNum2 = num2.intValue();
        Integer result = Math.mod(intNum1, intNum2);
        System.debug('Remainder of division: ' + result);
    }
    // Exponentiation method
    public static void power(Decimal baseNum, Decimal exponent) {
        System.debug('Result of exponentiation: ' + Decimal.valueOf(Math.pow(baseNum.doubleValue(), exponent.doubleValue())));
    }
}


/*

Calculator.add(5, 3); // Should return 8
Decimal resultSubtract = Calculator.subtract(5, 3); // Should return 2
Calculator.multiply(5, 3); // Should return 15
Decimal resultDivide = Calculator.divide(6, 3); // Should return 2
Calculator.modulus(10, 3); // Output: Remainder of division: 1
Calculator.power(2, 3); // Output: Result of exponentiation: 8

 */