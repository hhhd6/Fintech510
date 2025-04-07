# Dictionary of companies in the Dow Jones Industrial Average
dow_jones_companies = {
    "AAPL": {
        "company_name": "Apple Inc.",
        "CEO": "Tim Cook",
        "latest_stock_price": 176.15,
        "last_year_earnings": 99.8  # in billion USD
    },
    "MSFT": {
        "company_name": "Microsoft Corporation",
        "CEO": "Satya Nadella",
        "latest_stock_price": 337.80,
        "last_year_earnings": 72.7  # in billion USD
    },
    "JNJ": {
        "company_name": "Johnson & Johnson",
        "CEO": "Joaquin Duato",
        "latest_stock_price": 165.12,
        "last_year_earnings": 17.9  # in billion USD
    },
    "V": {
        "company_name": "Visa Inc.",
        "CEO": "Ryan McInerney",
        "latest_stock_price": 240.25,
        "last_year_earnings": 18.8  # in billion USD
    },
    "JPM": {
        "company_name": "JPMorgan Chase & Co.",
        "CEO": "Jamie Dimon",
        "latest_stock_price": 147.40,
        "last_year_earnings": 48.3  # in billion USD
    }
}

# alternate way to create
apple = {  "company_name": "Apple Inc.",  "CEO": "Tim Cook", "latest_stock_price": 176.15, "last_year_earnings": 99.8  }
microsoft = { "company_name": "Microsoft Corporation", "CEO": "Satya Nadella", "latest_stock_price": 337.80, "last_year_earnings": 72.7 }
jnj = { "company_name": "Johnson & Johnson", "CEO": "Joaquin Duato","latest_stock_price": 165.12, "last_year_earnings": 17.9  }
v = { "company_name": "Visa Inc.", "CEO": "Ryan McInerney", "latest_stock_price": 240.25, "last_year_earnings": 18.8   }
jpm = { "company_name": "JPMorgan Chase & Co.", "CEO": "Jamie Dimon", "latest_stock_price": 147.40, "last_year_earnings": 48.3  }

companies = { }
companies["AAPL"] = apple
companies["MSFT"] = microsoft
companies["JNJ"] = jnj
companies["V"] = v
companies["JPM"] = jpm

print("Apple:",apple)
print(dow_jones_companies["AAPL"] == apple)
print("Dictionaires equal -", dow_jones_companies == companies)
# Example of accessing data
print(dow_jones_companies["AAPL"]["CEO"])  # Output: Tim Cook

for key in companies:
    print("{:>5s}: {}".format(key,companies[key]["company_name"]))