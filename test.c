#include "tqdm.h"

#ifdef _WIN32
#include <windows.h>
#define usleep(x) Sleep((x) / 1000)
#else
#include <unistd.h>
#endif

int main() {
  tqdm bar;
  init_tqdm(&bar, "Loading update: ", false, "items", true, 100, 10);

  for (int i = 0; i <= 100; i++) {
    update_tqdm(&bar, 1, i == 100);
    usleep(50000);  // simulating work
  }

  close_tqdm(&bar);
  return 0;
}