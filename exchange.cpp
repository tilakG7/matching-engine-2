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

    for(uint64_t i=0; i < m_mob_ask.size(); i++)
    {
        std::cout << m_securities[i] << ": Order books" << std::endl;
        std::cout << "---MarketOrderBook Bid Side---" << std::endl;
        m_mob_bid[i].print();
        std::cout << "------------------------------" << std::endl;
        std::cout << "---MarketOrderBook Ask Side---" << std::endl;
        m_mob_ask[i].print();
        std::cout << "------------------------------" << std::endl;
    }
}

template<bool Bid>
void Exchange::matchMarketOrder(MarketOrder& o) {
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
        curr_book.addOrder(std::move(o));
    }
}

// void Exchange::matchLimitOrder(LimitOrder &o) {
    // steps:
    // 1. check if the limit condition is being met
    // bid: at limit price or lower
    // ask: at limit price or higher

    // 2. If it is not being met, store in data structure (TBD)

    // 3. Being met:
    // Try match with market order
    //      opposing side market order must exist
    // Try match with other limit order
    //      opposing side limit order must be met
    //      take the difference between the 2 prices and update the securities 
    //      prices
// }

// need 1 side for bidding, 1 side for asking...
// order by limit price...

// code to test...
int main(int argc, char *argv[]) {
    MarketOrder order_1{
        1U,
        1U,
        100U,
        true,
        boost::posix_time::microsec_clock::local_time()
    };

    MarketOrder order_2{
        1U,
        2U,
        1200,
        false,
        boost::posix_time::microsec_clock::local_time()
    };
    // order_1.print();
    // order_2.print();
    // e.printInfo();
    Exchange e;
    if(order_1.bid) {
        e.matchMarketOrder<true>(order_1);
    } else {
        e.matchMarketOrder<false>(order_1);
    }
    if(order_2.bid) {
        e.matchMarketOrder<true>(order_2);
    } else {
        e.matchMarketOrder<false>(order_2);
    }
    e.printInfo();

    LimitOrder o3{
        100.0,
        1U,
        1U,
        100U,
        false,
        boost::posix_time::microsec_clock::local_time()
    };
    LimitOrder o4{
        200.0,
        1U,
        1U,
        100U,
        false,
        boost::posix_time::microsec_clock::local_time()
    };

    LimitOrder o5{
        150.0,
        1U,
        1U,
        100U,
        false,
        boost::posix_time::microsec_clock::local_time()
    };
    e.delete_after.addOrder(o3);
    e.delete_after.addOrder(o4);
    e.delete_after.addOrder(o5);

    e.delete_after.print();



    // matching market orders
    // how to?
    // storing past market orders
    // per security, there needs to be a bid side and ask side queue
    // 1. check if there are any market orders on the sell side...

    
}


