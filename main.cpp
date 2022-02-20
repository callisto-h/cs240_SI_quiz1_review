#include <iostream>
#include "Sample.h"

int main(){
    std::string s1, s2, s3, s4;
    s1 = "string_1";
    s2 = "string_2";
    s3 = "string_3";
    s4 = "string_4";

    std::cout << "================================================" << std::endl;

    // What constructors do each of
    // these lines call?
    // Professor Lewis said this would
    // be a quiz question!
    Sample a(0, s1);
    Sample b(a);
    Sample c = a;
    Sample d;
    d = c;

    std::cout << "================================================" << std::endl;

    // Checking to see what the values on a, b, c, d are.
    std::cout << "a.) " << a << std::endl;
    std::cout << "b.) " << b << std::endl;
    std::cout << "c.) " << c << std::endl;
    std::cout << "d.) " << d << std::endl;

    int n = 10;

    // Manually setting values
    b.set_str_pointer_memory(s2);
    b.set_num_plus_5_value(n);

    c.set_str_pointer_memory(s3);
    c.set_num_plus_5_reference(n);
    
    d.set_str_pointer_memory(s4);
    d.set_num_plus_5_value(n);

    std::cout << "================================================" << std::endl;

    // Checking again
    std::cout << "a.) " << a << std::endl;
    std::cout << "b.) " << b << std::endl;
    std::cout << "c.) " << c << std::endl;
    std::cout << "d.) " << d << std::endl;
    
    std::cout << "================================================" << std::endl;

    return 0;
    
}