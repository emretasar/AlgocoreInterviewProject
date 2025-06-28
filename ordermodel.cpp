#include "ordermodel.h"
#include "utils.h"

OrderModel::OrderModel(QObject* parent)
    : QAbstractTableModel(parent) {}

int OrderModel::rowCount(const QModelIndex&) const {
    return m_orders.size();
}

int OrderModel::columnCount(const QModelIndex&) const {
    return 6;
}

QVariant OrderModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole) return {};

    const OrderUpdate& order = m_orders.at(index.row());
    switch (index.column()) {
    case 0: return order.unique_order_id;
    case 1: return order.unique_strategy_id;
    case 2: return order.price;
    case 3: return order.active_volume;
    case 4: return order.filled_volume;
    case 5: return toString(order.side);
    default: return {};
    }
}

QVariant OrderModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole) return {};

    switch (section) {
    case 0: return "Order ID";
    case 1: return "Strategy ID";
    case 2: return "Price";
    case 3: return "Active Volume";
    case 4: return "Filled Volume";
    case 5: return "Side";
    default: return {};
    }
}

void OrderModel::setOrders(const QList<OrderUpdate>& orders) {
    beginResetModel();
    m_orders = orders;
    endResetModel();
}

const OrderUpdate& OrderModel::getOrderAt(int row) const {
    return m_orders.at(row);
}
