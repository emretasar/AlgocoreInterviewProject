#ifndef ORDERGENERATOR_H
#define ORDERGENERATOR_H

#pragma once

#include <QObject>
#include <QTimer>
#include "orderupdate.h"

class OrderGenerator : public QObject {
    Q_OBJECT

public:
    explicit OrderGenerator(QObject* parent = nullptr);

signals:
    void orderGenerated(const OrderUpdate& order);

private slots:
    void generate();

private:
    QTimer m_timer;
    int m_nextOrderId = 1;
};

#endif // ORDERGENERATOR_H
