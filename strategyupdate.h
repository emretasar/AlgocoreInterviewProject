#ifndef STRATEGYUPDATE_H
#define STRATEGYUPDATE_H


#include <QString>

struct StrategyUpdate {
    int unique_strategy_id;
    enum class Type { StrategyType1, StrategyType2 } type;
    QString strategy_name;
    enum class State { Paused, Running } state;
};


#endif // STRATEGYUPDATE_H
