#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include "strategymodel.h"
#include "strategymanager.h"
#include "strategygenerator.h"
#include "ordermodel.h"
#include "ordermanager.h"
#include "ordergenerator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStrategiesUpdated(const QList<StrategyUpdate>& strategies);
    void onStrategySelected(const QModelIndex& current, const QModelIndex& previous);
    void onOrdersUpdated(const QList<OrderUpdate>& orders);

private:
    Ui::MainWindow *ui;

    StrategyGenerator* m_strategyGenerator;
    StrategyManager* m_strategyManager;
    StrategyModel* m_strategyModel;

    QTableView* m_strategyTable;

    OrderGenerator* m_orderGenerator;
    OrderManager* m_orderManager;
    OrderModel* m_orderModel;

    QTableView* m_orderTable;

    int m_selectedStrategyId = -1;

    void setupUi();
    void setupConnections();
};
#endif // MAINWINDOW_H
