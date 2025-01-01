#include "tqdm.h"
#include <unistd.h> // For usleep

int main() {
  tqdm bar;
  init_tqdm(&bar, "Loading", false, "items", true, 100, 10);

  for (int i = 0; i <= 100; ++i) {
    update_tqdm(&bar, 1, false);
    usleep(50000); // Simulate work
  }

  close_tqdm(&bar);
  return 0;
}