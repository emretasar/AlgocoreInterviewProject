#ifndef ORDERMODEL_H
#define ORDERMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include "orderupdate.h"

class OrderModel : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit OrderModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    void setOrders(const QList<OrderUpdate>& orders);
    const OrderUpdate& getOrderAt(int row) const;

private:
    QList<OrderUpdate> m_orders;
};

#endif // ORDERMODEL_H
