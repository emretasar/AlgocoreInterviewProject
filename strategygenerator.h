#ifndef STRATEGYGENERATOR_H
#define STRATEGYGENERATOR_H

#include <QObject>
#include <QTimer>
#include "strategyupdate.h"

class StrategyGenerator : public QObject {
    Q_OBJECT

public:
    explicit StrategyGenerator(QObject* parent = nullptr);

signals:
    void strategyGenerated(const StrategyUpdate& strategy);

private slots:
    void generate();

private:
    QTimer m_timer;
    int m_nextId = 1;
};


#endif // STRATEGYGENERATOR_H
