#include <cstdint>
#include <iostream>

// include boost C++ library
#include "boost/date_time/posix_time/posix_time.hpp"

struct MarketOrder {
    const uint64_t sec_id;
    const uint64_t order_id;
    uint64_t quantity;
    const bool bid;
    boost::posix_time::ptime time;
};

struct LimitOrder {
    double limit;
    const uint64_t sec_id;
    const uint64_t order_id;
    uint64_t quantity;
    const bool bid;
    boost::posix_time::ptime time;
};

void printMarketOrder(MarketOrder &o) {
    std::cout << "-------MarketOrder---------" << std::endl;
    std::cout << "order id = " << o.order_id << std::endl;
    std::cout << "security id = " << o.sec_id << std::endl;
    std::cout << "quantithy = " << o.quantity << std::endl;
    std::cout << (o.bid ? "bid" : "ask") << std::endl;
    std::cout << "time = " << o.time << std::endl;
    std::cout << "---------------------------" << std::endl;
}

void printLimitOrder(LimitOrder &o) {
    std::cout << "-------LimitOrder---------" << std::endl;
    std::cout << "limit price = " << o.limit << std::endl;
    std::cout << "order id = " << o.order_id << std::endl;
    std::cout << "security id = " << o.sec_id << std::endl;
    std::cout << "quantithy = " << o.quantity << std::endl;
    std::cout << (o.bid ? "bid" : "ask") << std::endl;
    std::cout << "time = " << o.time << std::endl;
    std::cout << "---------------------------" << std::endl;
}