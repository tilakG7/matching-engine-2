#include "exchange.h"
#include "order.h"

#include <queue>
#include <iostream>

// include boost C++ library
#include "boost/date_time/posix_time/posix_time.hpp"

void Exchange::printInfo() const noexcept {
    auto sec_it = securities_.begin();
    auto price_it = prices_.begin();
    for(; sec_it != securities_.end() && price_it != prices_.end(); sec_it++, price_it++) {
        std::cout << *sec_it << ": " << *price_it << std::endl;
    }
}


// code to test...
int main(int argc, char *argv[]) {
    MarketOrder order_1{
        1U,
        1U,
        100U,
        true,
        boost::posix_time::microsec_clock::local_time()
    };

    LimitOrder order_2{
        202.34,
        1U,
        2U,
        1200,
        true,
        boost::posix_time::microsec_clock::local_time()
    };
    printMarketOrder(order_1);
    printLimitOrder(order_2);
    Exchange e;
    e.printInfo();

}


