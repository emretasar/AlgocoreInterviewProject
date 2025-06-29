#ifndef ORDERGENERATOR_H
#define ORDERGENERATOR_H

#pragma once

#include <QObject>
#include <QTimer>
#include <random>
#include <unordered_set>
#include "orderupdate.h"
#include "strategyupdate.h"

class OrderGenerator : public QObject {
    Q_OBJECT

public:
    explicit OrderGenerator(QObject* parent = nullptr);

signals:
    void orderGenerated(const OrderUpdate& order);
private slots:
    void generate();
public slots:
    void handleNewStrategy(const StrategyUpdate& strategy);

private:
    QTimer m_timer;
    int m_nextOrderId = 1;

    std::unordered_set<int> m_strategyIds;

    std::mt19937 m_rng;  // Mersenne Twister RNG
    std::uniform_int_distribution<int> m_strategyDist;
    std::uniform_real_distribution<double> m_priceDist;
    std::uniform_real_distribution<double> m_volumeDist;
};

#endif // ORDERGENERATOR_H
