public class ElectricityBillingCalculator {
    public static Decimal calculateBill(Integer previousReading, Integer currentReading, Decimal ratePerUnit) {
        Integer unitsConsumed = currentReading - previousReading;
        Decimal billAmount = unitsConsumed * ratePerUnit;
        return billAmount;
    }
}

/*


Integer previousReading = 500; // Previous meter reading
Integer currentReading = 700; // Current meter reading
Decimal ratePerUnit = 8.5; // Rate per unit

Decimal billAmount = ElectricityBillingCalculator.calculateBill(previousReading, currentReading, ratePerUnit);
System.debug('Electricity bill amount: $' + billAmount);


*/