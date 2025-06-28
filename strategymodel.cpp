#include "strategymodel.h"
#include "utils.h"

StrategyModel::StrategyModel(QObject* parent)
    : QAbstractTableModel(parent) {}

int StrategyModel::rowCount(const QModelIndex& /*parent*/) const {
    return m_strategies.size();
}

int StrategyModel::columnCount(const QModelIndex& /*parent*/) const {
    return 4;  // ID, Type, Name, State
}

QVariant StrategyModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || index.row() >= m_strategies.size())
        return {};

    const StrategyUpdate& strategy = m_strategies.at(index.row());

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0: return strategy.unique_strategy_id;
        case 1: return toString(strategy.type);
        case 2: return strategy.strategy_name;
        case 3: return toString(strategy.state);
        }
    }

    return {};
}

QVariant StrategyModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch (section) {
        case 0: return "Strategy ID";
        case 1: return "Type";
        case 2: return "Name";
        case 3: return "State";
        }
    }
    return {};
}

void StrategyModel::setStrategies(const QList<StrategyUpdate>& strategies) {
    beginResetModel();
    m_strategies = strategies;
    endResetModel();
}

const StrategyUpdate& StrategyModel::getStrategyAt(int row) const {
    return m_strategies.at(row);
}
