# Queueing-System-Simulation
A C++ discrete-event simulation of a two-server queueing system with breakdowns, repairs, and customer arrival patterns. Models server states (idle, busy, down, blocked) and tracks customer flow between servers.
# 📖 Overview
This C++ project simulates a two-server queueing system with the following characteristics:

- Two servers with different service times and breakdown patterns
- Customer arrivals at regular intervals
- Server breakdowns and repair mechanisms
- Queue management between servers
- Real-time tracking of system states

# 🏗 System Architecture
## Key Components
- **Customer Class:** Represents customers with ID, arrival time, and waiting time.
- **Server Class:** Manages server states and operations.
- **Queues:** Two queues for each server using STL queues.

## Server States
- **Idle:** Server available but no customers.
- **Busy:** Server actively processing a customer.
- **Down:** Server under repair after breakdown.
- **Blocked:** Server cannot accept new customers (queue full).

# ⚙️ Simulation Parameters
## Server 1 Configuration
- **Operation Time:** 200 units
- **Repair Time:** 50 units
- **Service Time:** 20 units
- **Initial Break:** 80 units

## Server 2 Configuration
- **Operation Time:** 300 units
- **Repair Time:** 150 units
- **Service Time:** 30 units
- **Initial Break:** 90 units

## Customer Arrival
- **Initial arrival at time:** 10
- **Subsequent arrivals every:** 40 time units

# 📊 Output Metrics
The simulation outputs for each time unit:
- Current time
- Next arrival time
- Queue sizes for both servers
- Service completion times
- Server statuses
- Breakdown and repair information

# 🚀 How to Run
## Compilation
