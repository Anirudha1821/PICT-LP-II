public class GreatestNumberFinder {
    public static Integer findGreatest(Integer num1, Integer num2, Integer num3) {
        if (num1 >= num2 && num1 >= num3) {
            return num1;
        } else if (num2 >= num1 && num2 >= num3) {
            return num2;
        } else {
            return num3;
        }
    }
}

/*

Integer num1 = 10;
Integer num2 = 20;
Integer num3 = 15;

Integer greatestNumber = GreatestNumberFinder.findGreatest(num1, num2, num3);

System.debug('The greatest number is: ' + greatestNumber);


*/