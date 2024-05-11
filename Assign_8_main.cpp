#include <bits/stdc++.h>
using namespace std;

class Fact
{
private:
    string symbol;
    double stockValue;
    double volatility;

public:
    Fact(string symbol, double stockValue, double volatility)
    {
        this->symbol = symbol;
        this->stockValue = stockValue;
        this->volatility = volatility;
    }

    string getSymbol() const
    {
        return symbol;
    }

    double getStockValue() const
    {
        return stockValue;
    }

    double getVolatility() const
    {
        return volatility;
    }
};

class DefaultKnowledgeBase
{
public:
    static vector<Fact> getDefaultFacts()
    {
        vector<Fact> defaultFacts;

        defaultFacts.push_back(Fact("AAPL", 1500, 0.2));
        defaultFacts.push_back(Fact("GOOGL", 1000, 0.3));
        defaultFacts.push_back(Fact("MSFT", 800, 0.4));
        defaultFacts.push_back(Fact("AMZN", 2000, 0.1));

        return defaultFacts;
    }
};

class MarketAnalysisRule
{
private:
    string getMarketSentiment()
    {
        if (rand() > RAND_MAX / 2)
        {
            return "Bullish";
        }
        else
        {
            return "Neutral";
        }
    }

public:
    void apply(const Fact &fact)
    {
        cout << "Performing market analysis for: " << fact.getSymbol() << endl;
        double stockValue = fact.getStockValue();
        double volatility = fact.getVolatility();
        string marketSentiment = getMarketSentiment();

        if (stockValue > 1500 && volatility < 0.2 && marketSentiment == "Bullish")
        {
            cout << "Decision: Buy" << endl;
        }
        else if (stockValue > 1000 && volatility < 0.3 && marketSentiment == "Neutral")
        {
            cout << "Decision: Hold" << endl;
        }
        else
        {
            cout << "Decision: Sell" << endl;
        }
    }
};

int main()
{
    // Seed random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    string symbol;
    cout << "Enter the symbol of the share: ";
    cin >> symbol;

    vector<Fact> defaultFacts = DefaultKnowledgeBase::getDefaultFacts();

    MarketAnalysisRule rule;
    for (const auto &fact : defaultFacts)
    {
        if (fact.getSymbol() == symbol)
        {
            rule.apply(fact);
            return 0;
        }
    }

    cout << "No information found for symbol: " << symbol << endl;

    return 0;
}

//An expert system in AI is a computer system designed to emulate the decision-making ability of a human expert in a specific domain. It relies on a knowledge base, which contains facts, rules, and heuristics about a particular subject, along with an inference engine that applies logical reasoning to draw conclusions or make recommendations based on the provided knowledge.