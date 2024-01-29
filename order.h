#pragma once
#include <cstdint>
#include <iostream>

#include "market_order_book.h"

// include boost C++ library
#include "boost/date_time/posix_time/posix_time.hpp"

struct MarketOrder {
    const uint64_t sec_id;
    const uint64_t order_id;
    uint64_t quantity;
    const bool bid;
    boost::posix_time::ptime time;

    void print() const {
        std::cout << "-------MarketOrder---------" << std::endl;
        std::cout << "order id = " << order_id << std::endl;
        std::cout << "security id = " << sec_id << std::endl;
        std::cout << "quantithy = " << quantity << std::endl;
        std::cout << (bid ? "bid" : "ask") << std::endl;
        std::cout << "time = " << time << std::endl;
        std::cout << "---------------------------" << std::endl;
    }

    void complete() const {
        std::cout << "-------MarketOrder---------" << std::endl;
        std::cout << "COMPLETE" << std::endl;
        std::cout << "order id = " << order_id << std::endl;
        std::cout << "---------------------------" << std::endl;
    }
};

struct LimitOrder {
    double limit;
    const uint64_t sec_id;
    const uint64_t order_id;
    uint64_t quantity;
    const bool bid;
    boost::posix_time::ptime time;

    void print() const {
        std::cout << "-------LimitOrder---------" << std::endl;
        std::cout << "limit price = " << limit << std::endl;
        std::cout << "order id = " << order_id << std::endl;
        std::cout << "security id = " << sec_id << std::endl;
        std::cout << "quantithy = " << quantity << std::endl;
        std::cout << (bid ? "bid" : "ask") << std::endl;
        std::cout << "time = " << time << std::endl;
        std::cout << "---------------------------" << std::endl;
    }
};


