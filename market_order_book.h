#pragma once

#include "order.h"

#include <iostream>
#include <queue>

class MarketOrderBook {
public:
    bool empty() {
        return m_book.empty();
    }
    
    // returns the number of orders in the current order
    uint64_t& getQuantity() {
        assert(!empty());
        return m_book.front.quantity;
    }

    void addOrder(const MarketOrder &&o) {
        q.emplace(o.sec_id, o.order_id, o.quantity, o.bid, o.time);
    }

    void completeFront() {
        assert(!empty());
        m_book.front().complete();
        m_book.pop();
    }

private:
    std::queue<MarketOrder> m_book{};
};