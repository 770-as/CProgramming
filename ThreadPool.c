import queue
import threading
import time
import random

# A ThreadPool class to manage a fixed number of worker threads.
class ThreadPool:
    def __init__(self, num_threads):
        # A queue to hold the tasks (in our case, simple functions with arguments).
        self.tasks = queue.Queue()
        # A list to store the worker threads.
        self.workers = []
        # A lock to control access to the queue and other shared resources.
        self.lock = threading.Lock()
        # A flag to signal the workers to stop.
        self.is_running = True

        # Create and start the worker threads.
        for _ in range(num_threads):
            worker = threading.Thread(target=self.worker_loop)
            self.workers.append(worker)
            worker.start()

    # The main loop for each worker thread.
    def worker_loop(self):
        while self.is_running:
            try:
                # Attempt to get a task from the queue with a timeout.
                # The timeout is important to allow the worker to check the `is_running` flag.
                task, args = self.tasks.get(timeout=1)
                # Execute the task.
                task(*args)
                # Signal that the task is done.
                self.tasks.task_done()
            except queue.Empty:
                # If the queue is empty, continue the loop and check the `is_running` flag.
                continue

    # Method to add a new task to the queue.
    def add_task(self, task, *args):
        self.tasks.put((task, args))

    # Method to gracefully shut down the thread pool.
    def shutdown(self):
        print("Shutting down thread pool...")
        # Signal workers to stop after they've finished all tasks.
        self.tasks.join()
        # Set the flag to stop the worker loops.
        self.is_running = False
        # Wait for all worker threads to terminate.
        for worker in self.workers:
            worker.join()
        print("Thread pool shut down.")

# --- Example Tasks ---

# A simple producer function that simulates placing orders.
def place_order(order_id):
    sleep_time = random.uniform(0.1, 0.5)
    print(f"Producer: Placing order {order_id}...")
    time.sleep(sleep_time)
    print(f"Producer: Order {order_id} placed.")

# A simple consumer function that simulates processing orders.
def process_order(order_id):
    sleep_time = random.uniform(0.5, 2.0)
    print(f"Consumer: Processing order {order_id}...")
    time.sleep(sleep_time)
    print(f"Consumer: Order {order_id} processed.")

# --- Main Program ---
if __name__ == "__main__":
    # Create a thread pool with a fixed number of worker threads.
    # We'll use 5 workers to show how tasks are managed and distributed.
    pool = ThreadPool(num_threads=5)
    print("Thread pool with 5 workers created.")

    # We'll simulate 20 "producer" tasks (placing orders).
    num_orders = 20
    for i in range(1, num_orders + 1):
        # We can add a mix of tasks to the pool.
        if i % 2 == 0:
            pool.add_task(place_order, i)
        else:
            pool.add_task(process_order, i)

    # Shut down the pool after all tasks have been processed.
    # The `join()` call will block until the queue is empty and all workers are idle.
    pool.shutdown()
