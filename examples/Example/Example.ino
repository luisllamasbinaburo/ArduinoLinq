#include "ArduinoLinq.hpp"
  
void setup() {
  Serial.begin(115200);
  Serial.println("\n\n");
    
  int ints[] = {107, 1, 80, 3, 8, 20, 30, 5, 77, 102};
 
  int maxVal = from_array(ints)
               >> max();
 
  Serial.print("Max element of the array: ");
  Serial.println(maxVal);
  
  int minVal = from_array(ints)
               >> min();
 
  Serial.print("Min element of the array: ");
  Serial.println(minVal);
 
  auto reversed = from_array(ints)
               >> reverse()
               >> to_vector();
 
  Serial.print("Reversed Array: ");
 
  for(int i=0; i<reversed.size(); ++i){
    Serial.print(reversed[i]);
    Serial.print("|");
  }
  
  auto filtered = from_array(ints)
               >> where([](int i) {return i > 10;})
               >> orderby_ascending([](int i) {return i;})
               >> to_vector();
 
  Serial.print("\nFiltered Array: ");
 
  for(int i=0; i<filtered.size(); ++i){
    Serial.print(filtered[i]);
    Serial.print("|");
  }
}
  
void loop() {}
