public class TemperatureConverter {
    public static Decimal celsiusToFahrenheit(Decimal celsius) {
        Decimal fahrenheit = (celsius * 9/5) + 32;
        return fahrenheit;
    }
}

/*

Decimal celsiusTemperature = 20;
Decimal fahrenheitTemperature = TemperatureConverter.celsiusToFahrenheit(celsiusTemperature);
System.debug('20 degrees Celsius is equal to ' + fahrenheitTemperature + ' degrees Fahrenheit.');

*/