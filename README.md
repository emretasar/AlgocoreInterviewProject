# Algocore Interview Project

This is a Qt-based C++ desktop application developed as part of an interview process. The app simulates part of a trading system UI where strategies and their associated orders are monitored in real time. Strategy and order updates are generated asynchronously and reflected live in the UI.

You can view the demonstration video of the project from the following unlisted [https://youtu.be/QpsI2FNMlLo](Youtube link).

---

## Key Components

### ✅ `MainWindow`
- Hosts the main UI.
- Contains two `QTableView`s: one for strategies, one for orders.
- Responds to user selection and updates order filtering accordingly.
- Provides a "Show All Orders" button to reset filtering.

### ✅ `StrategyGenerator`
- Simulates asynchronous incoming strategy updates using a timer.
- Emits `strategyGenerated(StrategyUpdate)` signal.

### ✅ `StrategyManager`
- Owns the list of active strategies.
- Receives updates from `StrategyGenerator`.
- Emits `strategiesUpdated(QList<StrategyUpdate>)`.

### ✅ `StrategyModel`
- Subclass of `QAbstractTableModel`.
- Provides tabular access to strategy data for the strategy table view.

### ✅ `OrderGenerator`
- Simulates incoming order updates using a timer.
- Emits `orderGenerated(OrderUpdate)` signal.

### ✅ `OrderManager`
- Stores and maps orders to strategies.
- Emits `ordersUpdated(QList<OrderUpdate>)` when the order list changes.

### ✅ `OrderModel`
- Subclass of `QAbstractTableModel`.
- Displays all orders or filters by selected strategy ID.

### ✅ `utils.h`
- Contains helper functions like converting enums (state, type, side) to strings.

---

## 🛠️ Build Instructions

### ⚙️ Requirements

- **C++17**
- **Qt 6.x** or **Qt 5.x** (Widgets module)
- **CMake ≥ 3.16**
- **Compiler**
  - GCC (Linux)
  - Clang (MacOS)
  - MSVC or MinGW (Windows)

---

### 🐧 Building

I developed and built the project on Linux OS but thanks to I used CMake as build tool, I believe it should be built on Windows as well without so much effort. I used the Qt version 6.9.1 and Qt Creator version 17.0.0. I think just opening the project with Qt Creator and building it will be sufficient for running the application.

### 🖥️ Features

- Periodic simulation of strategies and orders
- Two-section UI: Strategy table & filtered Order table
- Select a strategy to see related orders
- Press "Show All Orders" to clear selection and show all data
- Fully reactive with Qt’s signal/slot architecture

### 🚧 Notes
- Networking is mocked using QTimer. No real socket or TCP implementation is included.
- The UI layout is manually constructed using Qt C++ (no .ui files).