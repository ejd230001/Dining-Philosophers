# Dining Philosophers – Concurrency Simulation

This program simulates the **Dining Philosophers problem** using C++ and explores two different synchronization strategies: **coarse-grain locking** and **fine-grain locking**.  

Philosophers sit in a circle with forks (locks) between them. Each philosopher alternates between thinking, becoming hungry, and eating, while competing for access to the forks. Synchronization ensures that no two philosophers improperly share the same fork at the same time.

---

## Synchronization Approaches

### Coarse-Grain Synchronization
- Only one philosopher can eat at a time.  
- Uses a tournament tree lock based on **Peterson’s algorithm**.  
- Guarantees safety but reduces concurrency.  

### Fine-Grain Synchronization
- Multiple philosophers can eat at the same time, as long as they can claim both the lock to their left and the lock to their right.  
- Uses Peterson-style locks placed between each philosopher in a circle.  
- Increases concurrency but requires more careful lock coordination.  

---

## Key Components

- **Philosopher**  
  - Represents a philosopher at the table.  
  - Provides `think()` and `eat()` functions, which pause for a random amount of time.  

- **CoarsePetersenLock**  
  - Implements acquire/release using a tournament tree lock.  
  - Restricts eating to a single philosopher at a time.  

- **FinePetersenLock**  
  - Implements acquire/release for individual locks between neighbors.  
  - Allows multiple philosophers to eat concurrently if they don’t share a fork.  

- **CoarseGrain**  
  - Sets up philosopher threads with coarse-grain synchronization.  

- **FineGrain**  
  - Sets up philosopher threads with fine-grain synchronization.  

---

## How to Compile and Run

### Using the Makefile
```bash
# Compile both versions
make

# Run coarse-grain version with N philosophers
./coarse N

# Run fine-grain version with N philosophers
./fine N
