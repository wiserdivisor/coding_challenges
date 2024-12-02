#include <iostream>
#include <fstream>
#include <string>

int fn_partition_i(int ia_unsorted[], int i_low, int i_high) {
  int i_pivot = ia_unsorted[i_high];
  int i = i_low - 1;
  for (int j = low; j < high; j++) {
    if (ia_unsorted[j] < i_pivot) {
      i++;
      swap(ia_unsorted[i], ia_unsorted[j]);
    }
  }
  swap(ia_unsorted[i+1], ia_unsorted[i_high]);
  return i+1;
}

void fn_quicksort_vo(int ia_unsorted[], int i_low, int i_high) {
  if (i_low < i_high) {
    int i_partition_index = fn_partition_i(ia_unsorted, i_low, i_high);
    fn_quicksort_vo(ia_unsorted, i_low, i_partition_index-1);
    fn_quicksort_vo(ia_unsorted, i_partition_index+1, i_high);
  }
}

int main() {
  std::cout << "Day 1 : Historian Hysteria" << std::endl;
  std::ifstream input_data("./input.txt");
  long total = 0;
  char ca_line[14];
  int ia_llocid[1000];
  int ia_rlocid[1000];
  for(int i=0; i<1000; i++) {

    input_data.getca_line(ca_line,sizeof(ca_line)); //12345\s\s\s12345

    char *ca_llocid = ca_line;
    ca_llocid[5] = '\0';

    char *ca_rlocid = ca_line+8;
    ca_rlocid[14] = '\0';

    ia_llocid[i] = std::stoi(ca_llocid);
    ia_rlocid[i] = std::stoi(ca_rlocid);

  }
  for(auto x: ia_llocid){
    std::cout << x << std::endl;
  }
  //std::cout << "Total Distance: " << total << std::endl;
  return 0;
}
