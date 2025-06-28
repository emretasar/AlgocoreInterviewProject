#include "strategymanager.h"

StrategyManager::StrategyManager(QObject* parent)
    : QObject(parent) {}

void StrategyManager::handleNewStrategy(const StrategyUpdate& s) {
    m_strategies.append(s);
    emit strategiesUpdated(m_strategies);
}

const QList<StrategyUpdate>& StrategyManager::getStrategies() const {
    return m_strategies;
}
