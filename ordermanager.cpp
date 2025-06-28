#include "ordermanager.h"

OrderManager::OrderManager(QObject* parent)
    : QObject(parent) {}

void OrderManager::handleNewOrder(const OrderUpdate& order) {
    m_orders.append(order);
    emit ordersUpdated(m_orders);  // Always emit full list (model will filter if needed)
}

QList<OrderUpdate> OrderManager::getAllOrders() const {
    return m_orders;
}

QList<OrderUpdate> OrderManager::getOrdersForStrategy(int strategyId) const {
    QList<OrderUpdate> filtered;
    for (const auto& order : m_orders) {
        if (order.unique_strategy_id == strategyId) {
            filtered.append(order);
        }
    }
    return filtered;
}
