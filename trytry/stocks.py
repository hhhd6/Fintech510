stock_list = [ "Steve:IBM:100",
               "Bill:TSLA:40",
               "Ada:F:50",
               "Steve:F:25",
               "Ada:T:50",
               "Bill:BAC:40"]

stocks = {}
for line in stock_list:
    name, ticker, shares = line.split(":")
    stocks[ticker] = stocks.get(ticker,0) + 1
print(stocks)

popularity_keys = sorted(stocks,key=stocks.get,reverse=True)
for ticker in popularity_keys:
    print("{:>5s}:{:5d}".format(ticker,stocks[ticker]))
    