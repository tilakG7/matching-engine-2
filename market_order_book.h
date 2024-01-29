#pragma once

#include "order.h"

#include <iostream>
#include <deque>

class MarketOrderBook {
public:
    bool empty() {
        return m_book.empty();
    }
    
    // returns the quantity of shares in the order at the front of the queue
    uint64_t& getQuantity() {
        assert(!empty());
        return m_book.front().quantity;
    }

    void addOrder(const MarketOrder &&o) {
        m_book.push_back(o);
    }

    void completeFront() {
        assert(!empty());
        m_book.front().complete();
        m_book.pop_front();
    }

    void print() const noexcept{
        for(const auto& o : m_book) {
            o.print();
        }
    }

private:
    std::deque<MarketOrder> m_book{};
};