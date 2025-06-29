#include "ordergenerator.h"
#include <QRandomGenerator>
#include <QDebug>

OrderGenerator::OrderGenerator(QObject* parent)
    : QObject(parent),
    m_rng(std::random_device{}()),  // seed RNG
    m_strategyDist(1, 5),           // strategy ID range: [1, 5]
    m_priceDist(100.0, 200.0),      // price: 100.0 to 200.0
    m_volumeDist(1.0, 10.0)         // volume: 1.0 to 10.0
{
    connect(&m_timer, &QTimer::timeout, this, &OrderGenerator::generate);
    m_timer.start(1000); // generate an order every second
}

void OrderGenerator::generate() {
    if (m_strategyIds.empty())
        return;

    // Pick a random strategy ID from the set
    std::vector<int> ids(m_strategyIds.begin(), m_strategyIds.end());
    std::uniform_int_distribution<size_t> indexDist(0, ids.size() - 1);
    int strategyId = ids[indexDist(m_rng)];

    OrderUpdate o;
    o.unique_order_id = m_nextOrderId++;
    o.unique_strategy_id = strategyId;

    o.price = m_priceDist(m_rng);
    o.active_volume = m_volumeDist(m_rng);
    std::uniform_real_distribution<double> filledDist(0.0, o.active_volume);
    o.filled_volume = filledDist(m_rng);
    o.side = (o.unique_order_id % 2 == 0) ? OrderUpdate::Side::Buy : OrderUpdate::Side::Sell;

    emit orderGenerated(o);
}


void OrderGenerator::handleNewStrategy(const StrategyUpdate& strategy) {
    m_strategyIds.insert(strategy.unique_strategy_id);
}

