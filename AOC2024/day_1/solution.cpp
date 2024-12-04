#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <unordered_map>

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
  long l_similarityScore = 0;
  char ca_line[14];
  int ia_llocid[1000];
  int ia_rlocid[1000];
  std::unordered_map<int, std::array<int,2>> similarity_map;

  std::ifstream input_data("./input.txt");
  for(int i=0; i<1000; i++) {

    input_data.getline(ca_line,sizeof(ca_line)); //12345\s\s\s12345

    char *ca_llocid = ca_line;
    ca_llocid[5] = '\0';

    char *ca_rlocid = ca_line+8;
    ca_rlocid[14] = '\0';

    int i_llocid = std::stoi(ca_llocid);
    int i_rlocid = std::stoi(ca_rlocid);

    ia_llocid[i] = i_llocid;
    ia_rlocid[i] = i_rlocid;

    if(similarity_map.find(i_llocid) != similarity_map.end()) {
      similarity_map[i_llocid][0] += 1;
    } else {
      similarity_map[i_llocid] = {1,0};
    }

    if(similarity_map.find(i_rlocid) != similarity_map.end()) {
      similarity_map[i_rlocid][1] += 1;
    } else {
      similarity_map[i_rlocid] = {0,1};
    }

  }
  input_data.close();

  fn_quicksort_vo(ia_llocid,0,999);
  fn_quicksort_vo(ia_rlocid,0,999);

  for(int i=0; i<1000; i++){
    l_total += std::abs(ia_llocid[i] - ia_rlocid[i]);
  }

  for(std::unordered_map<int, std::array<int,2>>::iterator  itr = similarity_map.begin();
                                                itr != similarity_map.end(); itr++){
    l_similarityScore += (itr->first * itr->second[0] * itr->second[1]);
  }

  std::cout << "Total Distance: " << l_total << std::endl;
  std::cout << "Similarity Score: " << l_similarityScore << std::endl;

  return 0;
}
