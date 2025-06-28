#include "mainwindow.h"
#include <QVBoxLayout>
#include <QSplitter>
#include <QItemSelectionModel>
#include <QHeaderView>


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
    m_strategyGenerator(new StrategyGenerator(this)),
    m_strategyManager(new StrategyManager(this)),
    m_strategyModel(new StrategyModel(this)),
    m_strategyTable(new QTableView(this)),

    m_orderGenerator(new OrderGenerator(this)),
    m_orderManager(new OrderManager(this)),
    m_orderModel(new OrderModel(this)),
    m_orderTable(new QTableView(this)) {

    setupUi();
    setupConnections();
}

MainWindow::~MainWindow() {

}

void MainWindow::setupUi() {
    QWidget* central = new QWidget(this);

    m_strategyTable->setModel(m_strategyModel);
    m_strategyTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_strategyTable->setSelectionMode(QAbstractItemView::SingleSelection);
    m_strategyTable->horizontalHeader()->setStretchLastSection(true);

    m_orderTable->setModel(m_orderModel);
    m_orderTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_orderTable->setSelectionMode(QAbstractItemView::SingleSelection);
    m_orderTable->horizontalHeader()->setStretchLastSection(true);

    QSplitter* splitter = new QSplitter(Qt::Horizontal, this);
    splitter->addWidget(m_strategyTable);
    splitter->addWidget(m_orderTable);
    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 2);

    QVBoxLayout* layout = new QVBoxLayout(central);
    layout->addWidget(splitter);
    setCentralWidget(central);

    resize(1000, 600);
    setWindowTitle("Strategy/Order Monitor");
}

void MainWindow::setupConnections() {
    connect(m_strategyGenerator, &StrategyGenerator::strategyGenerated,
            m_strategyManager, &StrategyManager::handleNewStrategy);

    connect(m_strategyManager, &StrategyManager::strategiesUpdated,
            this, &MainWindow::onStrategiesUpdated);

    connect(m_strategyTable->selectionModel(), &QItemSelectionModel::currentChanged,
            this, &MainWindow::onStrategySelected);

    connect(m_orderGenerator, &OrderGenerator::orderGenerated,
            m_orderManager, &OrderManager::handleNewOrder);

    connect(m_orderManager, &OrderManager::ordersUpdated,
            this, &MainWindow::onOrdersUpdated);
}


void MainWindow::onStrategiesUpdated(const QList<StrategyUpdate>& strategies) {
    int selectedStrategyId = -1;
    QModelIndex currentIndex = m_strategyTable->currentIndex();
    if (currentIndex.isValid()) {
        const StrategyUpdate& selected = m_strategyModel->getStrategyAt(currentIndex.row());
        selectedStrategyId = selected.unique_strategy_id;
    }

    m_strategyModel->setStrategies(strategies);

    if (selectedStrategyId != -1) {
        for (int row = 0; row < m_strategyModel->rowCount(); ++row) {
            const StrategyUpdate& s = m_strategyModel->getStrategyAt(row);
            if (s.unique_strategy_id == selectedStrategyId) {
                QModelIndex index = m_strategyModel->index(row, 0);
                m_strategyTable->setCurrentIndex(index);
                break;
            }
        }
    }
}

void MainWindow::onOrdersUpdated(const QList<OrderUpdate>& /*orders*/) {
    if (m_selectedStrategyId == -1) {
        m_orderModel->setOrders(m_orderManager->getAllOrders());
    } else {
        m_orderModel->setOrders(m_orderManager->getOrdersForStrategy(m_selectedStrategyId));
    }
}

void MainWindow::onStrategySelected(const QModelIndex& current, const QModelIndex&) {
    if (!current.isValid()) {
        m_selectedStrategyId = -1;
        m_orderModel->setOrders(m_orderManager->getAllOrders());
        return;
    }

    const StrategyUpdate& selected = m_strategyModel->getStrategyAt(current.row());
    m_selectedStrategyId = selected.unique_strategy_id;

    m_orderModel->setOrders(m_orderManager->getOrdersForStrategy(m_selectedStrategyId));
}
