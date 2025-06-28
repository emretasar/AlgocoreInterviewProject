#ifndef STRATEGYMANAGER_H
#define STRATEGYMANAGER_H

#include <QObject>
#include <QList>
#include "strategyupdate.h"

class StrategyManager : public QObject {
    Q_OBJECT

public:
    explicit StrategyManager(QObject* parent = nullptr);

    void handleNewStrategy(const StrategyUpdate& s);
    const QList<StrategyUpdate>& getStrategies() const;

signals:
    void strategiesUpdated(const QList<StrategyUpdate>& strategies);

private:
    QList<StrategyUpdate> m_strategies;
};

#endif // STRATEGYMANAGER_H
