#include "tqdm.h"
#include <thread>
#include <chrono>

int main() {
  tqdm bar;
  init_tqdm(&bar, "Processing", false, "tasks", true, 50, 5);

  for (int i = 0; i <= 50; ++i) {
    update_tqdm(&bar, 1, false);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
  }

  close_tqdm(&bar);
  return 0;
}