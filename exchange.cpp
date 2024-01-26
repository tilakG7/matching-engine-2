#include "exchange.h"
#include "order.h"

#include <queue>
#include <iostream>

// include boost C++ library
#include "boost/date_time/posix_time/posix_time.hpp"

void Exchange::printInfo() const noexcept {
    auto sec_it = m_securities.begin();
    auto price_it = m_prices.begin();
    for(; sec_it != m_securities.end() && price_it != m_prices.end(); sec_it++, price_it++) {
        std::cout << *sec_it << ": " << *price_it << std::endl;
    }
}

template<bool Bid>
void Exchange::matchMarketOrder(const MarketOrder& o) {
    MarketOrderBook &oppo_book = (Bid ? m_mob_ask[o.sec_id] : m_mob_bid[o.sec_id]);
    MarketOrderBook &curr_book = (Bid ? m_mob_bid[o.sec_id] : m_mob_ask[o.sec_id]);

    // try to match while we still have orders left and
    // there are orders to match to
    while(!oppo_book.empty() && o.quantity) {
        uint64_t &oppo_quantity = oppo_book.getQuantity();

        if(oppo_quantity > o.quantity) {
            oppo_quantity -= o.quantity;
            o.complete();
        }
        else if(o.quantity > oppo_quantity) {
            o.quantity -= oppo_quantity;
            oppo_book.completeFront();
        }
        else {
            o.complete();
            oppo_book.completeFront();
        }
    }

    if(o.quantity) {
        curr_book.add(o);
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
    order_1.print();
    order_2.print();
    Exchange e;
    e.printInfo();

    // matching market orders
    // how to?
    // storing past market orders
    // per security, there needs to be a bid side and ask side queue
    // 1. check if there are any market orders on the sell side...

    
}


