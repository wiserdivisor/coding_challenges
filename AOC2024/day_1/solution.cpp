#include <iostream>
#include <fstream>
#include <string>

int fn_partition_i(int ia_unsorted[], int i_low, int i_high) {
  int i_pivot = ia_unsorted[i_high];
  int i = i_low - 1;
  for (int j = i_low; j < i_high; j++) {
    if (ia_unsorted[j] < i_pivot) {
      i++;
      std::swap(ia_unsorted[i], ia_unsorted[j]);
    }
  }
  std::swap(ia_unsorted[i+1], ia_unsorted[i_high]);
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

  long l_total = 0;
  char ca_line[14];
  int ia_llocid[1000];
  int ia_rlocid[1000];

  std::ifstream input_data("./input.txt");
  for(int i=0; i<1000; i++) {

    input_data.getline(ca_line,sizeof(ca_line)); //12345\s\s\s12345

    char *ca_llocid = ca_line;
    ca_llocid[5] = '\0';

    char *ca_rlocid = ca_line+8;
    ca_rlocid[14] = '\0';

    ia_llocid[i] = std::stoi(ca_llocid);
    ia_rlocid[i] = std::stoi(ca_rlocid);

  }
  input_data.close();

  fn_quicksort_vo(ia_llocid,0,999);
  fn_quicksort_vo(ia_rlocid,0,999);

  for(int i=0; i<1000; i++){
    l_total += std::abs(ia_llocid[i] - ia_rlocid[i]);
  }

  std::cout << "Total Distance: " << l_total << std::endl;
  return 0;
}
