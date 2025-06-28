#include "ordergenerator.h"
#include <QRandomGenerator>

OrderGenerator::OrderGenerator(QObject* parent)
    : QObject(parent) {
    connect(&m_timer, &QTimer::timeout, this, &OrderGenerator::generate);
    m_timer.start(1000); // generate an order every second
}

void OrderGenerator::generate() {
    OrderUpdate o;
    o.unique_order_id = m_nextOrderId++;

    // Simulate orders for strategy IDs between 1 and 5
    o.unique_strategy_id = QRandomGenerator::global()->bounded(1, 6);

    std::default_random_engine re;
    std::uniform_real_distribution<double> unifPrice(100.0, 200.0);
    o.price = unifPrice(re);
    std::uniform_real_distribution<double> unifActiveVolume(0.0, 20.0);
    o.active_volume = unifActiveVolume(re);
    std::uniform_real_distribution<double> unifFilledVolume(0.0, o.active_volume);
    o.filled_volume = unifFilledVolume(re);
    o.side = (o.unique_order_id % 2 == 0) ? OrderUpdate::Side::Buy : OrderUpdate::Side::Sell;

    emit orderGenerated(o);
}

