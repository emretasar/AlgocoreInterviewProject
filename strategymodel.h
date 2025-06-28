#ifndef STRATEGYMODEL_H
#define STRATEGYMODEL_H

#include <QAbstractTableModel>
#include "strategyupdate.h"

class StrategyModel : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit StrategyModel(QObject* parent = nullptr);

    // Override required methods coming from QAbstractTableModel
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Getters and setters to update data externally
    void setStrategies(const QList<StrategyUpdate>& strategies);
    const StrategyUpdate& getStrategyAt(int row) const;

private:
    QList<StrategyUpdate> m_strategies;
};


#endif // STRATEGYMODEL_H
