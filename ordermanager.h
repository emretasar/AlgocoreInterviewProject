#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include <QObject>
#include <QList>
#include "orderupdate.h"

class OrderManager : public QObject {
    Q_OBJECT

public:
    explicit OrderManager(QObject* parent = nullptr);

    void handleNewOrder(const OrderUpdate& order);
    QList<OrderUpdate> getAllOrders() const;
    QList<OrderUpdate> getOrdersForStrategy(int strategyId) const;

signals:
    void ordersUpdated(const QList<OrderUpdate>& orders);

private:
    QList<OrderUpdate> m_orders;
};


#endif // ORDERMANAGER_H
