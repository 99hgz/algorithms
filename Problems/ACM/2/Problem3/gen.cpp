#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <set>
using namespace std;
typedef long long ll;
ll a[100010];
set<ll> s;

class Random {
public:
  static void InitSeed() { srand(time(0)); } // set random seed

  static float Value() {
    return (float)rand() / RAND_MAX;
  } // get a random value between [0.0, 1.0]

  static int Range(int min,
                   int max) // return a int random value between [min, max)
  {
    return min + (max - min) * Value();
  }

  static float
  Range(float min, float max) // return a float random value between [min, max]
  {
    return min + (max - min) * Value();
  }
};
ll randll() { return ((rand() % 100) + 2333333333); }

int main(int argc, char **argv) {
  Random r;
  // printf("%d\n", argv[1]);
  srand(atoi(argv[1]));
  int sl = atoi(argv[2]);
  // printf("%d\n", RAND_MAX);
  // int sl = 1000;
  // srand(1517897);
  freopen("lln.in", "w", stdout);
  printf("%d\n", sl);
  ll tmp;
  for (int i = 1; i <= sl; i++) {
    tmp = randll();
    // tmp = r.Range(0, 1000000000);
    /*while (s.count(tmp))
    {
        tmp = randll();
        printf("%d ", tmp);
    }*/
    a[i] = tmp;
    // s.insert(tmp);
    printf("%lld ", a[i]);
  }
  printf("\n");
  int left, right, mid, kind, j;
  int delta;
  for (int i = 0; i < sl; i++) {
    left = r.Range(0, sl - 5);
    right = r.Range(left, sl - 1);
    printf("%d %d\n", left, right);
  }
  // system("pause");
  fclose(stdout);
  return 0;
}