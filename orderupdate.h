#ifndef ORDERUPDATE_H
#define ORDERUPDATE_H

#include <QString>

struct OrderUpdate {
    int unique_order_id;
    int unique_strategy_id;
    double price;
    double active_volume;
    double filled_volume;
    enum class Side { Buy, Sell } side;
};


#endif // ORDERUPDATE_H
