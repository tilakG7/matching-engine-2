#pragma once
#include <cstdint>
#include <iostream>

#include "market_order_book.h"

// include boost C++ library
#include "boost/date_time/posix_time/posix_time.hpp"

template<bool bid>
struct MarketOrder {
    const uint64_t sec_id;
    const uint64_t order_id;
    uint64_t quantity;
    boost::posix_time::ptime time;

    void print() {
        std::cout << "-------MarketOrder---------" << std::endl;
        std::cout << "order id = " << order_id << std::endl;
        std::cout << "security id = " << sec_id << std::endl;
        std::cout << "quantithy = " << quantity << std::endl;
        std::cout << (bid ? "bid" : "ask") << std::endl;
        std::cout << "time = " << time << std::endl;
        std::cout << "---------------------------" << std::endl;
    }
};

template<bool bid>
struct LimitOrder {
    double limit;
    const uint64_t sec_id;
    const uint64_t order_id;
    uint64_t quantity;
    boost::posix_time::ptime time;
    
    void print() {
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
