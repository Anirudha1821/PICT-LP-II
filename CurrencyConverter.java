public class CurrencyConverter {
    public static Decimal convertCurrency(Decimal amount, Decimal conversionRate) {
        // Perform currency conversion
        Decimal convertedAmount = amount * conversionRate;
        return convertedAmount;
    }
}

/*


Decimal amountToConvert = 100; // Amount to convert
Decimal conversionRate = 1.2; // Example conversion rate (e.g., from USD to EUR)

Decimal convertedAmount = CurrencyConverter.convertCurrency(amountToConvert, conversionRate);

System.debug('Converted amount: ' + convertedAmount);


*/