#pragma once

#include <cstdint>
#include <iostream>

#include "market_order_book.h"
#include "limit_order_book.h"

class Exchange {
public:
    void printInfo() const noexcept;

    template<bool Bid>
    void matchMarketOrder(MarketOrder& o);

    LimitOrderBook<false> delete_after{};

private:
    static constexpr uint64_t kNumSecurities{8};
    inline static std::array<MarketOrderBook, kNumSecurities> m_mob_bid{}; // must declare as inline (non-const data members are implic)
    inline static std::array<MarketOrderBook, kNumSecurities> m_mob_ask{}; // must declare as inline (non-const data members are implic)
    static constexpr std::array<std::string_view, kNumSecurities> m_securities{
        "TSLA",
        "AMZN",
        "AAPL",
        "AMD " ,
        "NVDA",
        "GOOG",
        "ASML",
        "META",
    };

    inline static std::array<double, kNumSecurities> m_prices{
        238.45,
        148.47,
        184.25,
        135.32,
        475.69,
        140.36,
        703.37,
        344.47,
    };
};
