#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::cout << "Day 1 : Historian Hysteria" << std::endl;
  std::ifstream input_data("./input.txt");
  char line[14];
  int index = 0;
  int ia_llocid[1000];
  int ia_rlocid[1000];
  long total = 0;
  while(input_data.getline(line,sizeof(line))){

    char *ca_llocid = line;
    ca_llocid[5] = '\0';
    char *ca_rlocid = line+8;
    ca_rlocid[14] = '\0';

    int i_llocid, i_rlocid;

    i_llocid = std::stoi(ca_llocid);
    i_rlocid = std::stoi(ca_rlocid);

    ia_llocid[index] = i_llocid;
    ia_rlocid[index++] = i_rlocid;
    //int diff = i_llocid - i_rlocid;
    //total += diff;
  }
  for(auto x: ia_llocid){
    std::cout << x << std::endl;
  }
  //std::cout << "Total Distance: " << total << std::endl;
  return 0;
}
