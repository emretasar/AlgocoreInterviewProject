#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include "strategyupdate.h"
#include "orderupdate.h"

inline QString toString(StrategyUpdate::Type type) {
    switch (type) {
    case StrategyUpdate::Type::StrategyType1: return "StrategyType1";
    case StrategyUpdate::Type::StrategyType2: return "StrategyType2";
    default: return "Unknown";
    }
}

inline QString toString(StrategyUpdate::State state) {
    switch (state) {
    case StrategyUpdate::State::Paused: return "Paused";
    case StrategyUpdate::State::Running: return "Running";
    default: return "Unknown";
    }
}

inline QString toString(OrderUpdate::Side side) {
    switch (side) {
    case OrderUpdate::Side::Buy: return "Buy";
    case OrderUpdate::Side::Sell: return "Sell";
    default: return "Unknown";
    }
}

#endif // UTILS_H
