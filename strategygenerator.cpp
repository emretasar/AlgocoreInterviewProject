#include "strategygenerator.h"

StrategyGenerator::StrategyGenerator(QObject* parent)
    : QObject(parent) {
    connect(&m_timer, &QTimer::timeout, this, &StrategyGenerator::generate);
    m_timer.start(2000);        // Emit every 2 seconds
}

void StrategyGenerator::generate() {        // todo: make it more randomized.
    StrategyUpdate s;
    s.unique_strategy_id = m_nextId++;
    s.strategy_name = QString("Strategy %1").arg(s.unique_strategy_id);
    s.type = (s.unique_strategy_id % 2 == 0)
                 ? StrategyUpdate::Type::StrategyType1
                 : StrategyUpdate::Type::StrategyType2;
    s.state = (s.unique_strategy_id % 2 == 0)
                  ? StrategyUpdate::State::Paused
                  : StrategyUpdate::State::Running;

    emit strategyGenerated(s);
}
