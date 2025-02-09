#include <iostream>
#include <vector>
#include <bitset>

int main() {
  // Using std::vector<char> as a safer alternative
  std::vector<char> boolVec;
  boolVec.push_back(true);
  boolVec.push_back(false);
  boolVec[0] = false; //Safe
  std::cout << boolVec[0] << " " << boolVec[1] << std::endl;

  //Or using std::bitset
  std::bitset<2> bitsetVec;
  bitsetVec[0] = true;
  bitsetVec[1] = false;
  std::cout << bitsetVec[0] << " " << bitsetVec[1] << std::endl;
  return 0;
}
