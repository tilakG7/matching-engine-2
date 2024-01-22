#include <cstdint>
#include <iostream>

class Exchange {
public:
    void printInfo() const noexcept;

private:
    static constexpr uint64_t kNumSecurities{8};
    static constexpr std::array<std::string_view, kNumSecurities> securities_{
        "TSLA",
        "AMZN",
        "AAPL",
        "AMD " ,
        "NVDA",
        "GOOG",
        "ASML",
        "META",
    };

    static std::array<double, kNumSecurities> prices_{
        238.45,
        148.47,
        184.25,
        135.32,
        475.69,
        140.36,
        703.37,
        344.47,
    };
    // MarketOrderBook m_mob;
    // LimitOrderBook m_lob;
};
