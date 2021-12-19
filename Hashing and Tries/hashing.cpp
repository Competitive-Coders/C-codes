 #include<iostream>
 #include "hashtable(with rehashing).h"
 using namespace std;
 int main()
 {
     hashtable<int> h(3);
     h.insert_data("mango",100);
     h.insert_data("guava",100);
     h.insert_data("orange",100);
     h.insert_data("pineapple",100);
     h.insert_data("apple",100);
     h.insert_data("grapes",100);
     h.insert_data("banana",100);
     h.insert_data("strawberry",100);
     h.insert_data("orange",100);
     h.insert_data("mango",100);
     h.insert_data("cheeku",100);
     h.insert_data("raddish",100);
     h.insert_data("bright",100);
     h.print();
     return 0;
 }
