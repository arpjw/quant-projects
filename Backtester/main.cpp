#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct PriceData {
    string date;
    double close;
};

struct Trade {
    string date;
    string action;
    double price;
};

vector<PriceData> load_price_data(const string& filename) {
    vector<PriceData> data;
    ifstream file(filename);
    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string date, closeStr;
        getline(ss, date, ','); // date
        getline(ss, closeStr, ','); // close
        data.push_back({date, stod(closeStr)});
    }
    return data;
}

double moving_average(const vector<PriceData>& data, int end, int window) {
    if (end < window - 1 || end >= data.size()) return -1.0;

    double sum = 0.0;
    for (int i = end - window + 1; i <= end; ++i) {
        if (i < 0 || i >= data.size()) return -1.0;
        sum += data[i].close;
    }
    return sum / window;
}

int main() {
    vector<PriceData> prices = load_price_data("data/prices.csv");
    vector<Trade> trades;

    double cash = 10000.0;
    double position = 0.0;
    double last_buy_price = 0.0;

    int short_window = 5;
    int long_window = 20;

    for (int i = 0; i < prices.size(); ++i) {
        double short_ma = moving_average(prices, i, short_window);
        double long_ma = moving_average(prices, i, long_window);

        if (short_ma < 0 || long_ma < 0) continue;

        const auto& p = prices[i];

        if (short_ma > long_ma && position == 0) {
            position = cash / p.close;
            last_buy_price = p.close;
            cash = 0;
            trades.push_back({p.date, "BUY", p.close});
        }
        else if (short_ma < long_ma && position > 0) {
            cash = position * p.close;
            trades.push_back({p.date, "SELL", p.close});
            position = 0;
        }
    }

    double final_value = cash + position * prices.back().close;
    cout << "Final Portfolio Value: $" << final_value << endl;

    for (const auto& trade : trades) {
        cout << trade.date << " - " << trade.action << " @ " << trade.price << endl;
    }

    return 0;
}
