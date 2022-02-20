// Describe what this #include statement does
#include "Sample.h"

// Why do we use 'Sample::'
// instead of 'class Sample{}' here?

Sample::Sample(){
    std::cout << "**DEFAULT CONSTRUCTOR CALLED**" << std::endl;

    // What is the purpose of this?
    str_pointer = nullptr;
}

Sample::Sample(int n, std::string const &str){
    std::cout << "**VALUE CONSTRUCTOR CALLED**" << std::endl; 
    
    num = n;

    // What does this line do?
    // What does 'new' do, and what 
    // constructor is being called?
    str_pointer = new std::string(str);
}

Sample::Sample(Sample const &s){
    std::cout << "**COPY CONSTRUCTOR CALLED**" << std::endl;

    // What does this do?
    // Why do we bother?
    if(this == &s){return;}

    this->num = s.num;

    if(s.str_pointer == nullptr){
        this->str_pointer = nullptr;
        return;
    }
    

    // Complicated line. What are we
    // doing, and what are we AVOIDING
    // with this?
    this->str_pointer = new std::string(*(s.str_pointer));
    
    // Hint: start from the inside of parenthesis
    // and work your way out.
    // Hint: what would 
    // 'this->str_pointer = s.str_pointer' do?
}

void Sample::operator=(Sample const &s){
    std::cout << "**OVERLOADED = OPERATOR CALLED**" << std::endl;

    // Notice any similarities to the copy constructor?
    if(this == &s){return;}
    this->num = s.num;
    if(s.str_pointer == nullptr){
        this->str_pointer = nullptr;
        return;
    }
    this->str_pointer = new std::string(*(s.str_pointer));
}




void Sample::set_str_pointer_memory(std::string const &str){

    // Why would we want this check? 
    // When could str_pointer be nulllptr?
    // Hint: Check the constructors
    if(str_pointer == nullptr){
        str_pointer = new std::string(str);
        return;
    }

    // Huh? Why aren't we using 'new' here?
    // I thought that if we were using the heap
    // that we assigned with 'new'? Why would we
    // do this?
    *str_pointer = str;
    // Hint: What would happen to the old string
    // that str_pointer points to if we used
    // 'new'?
}

std::string Sample::get_str_from_str_pointer() const{

    // No way. This is getting ridiculous.
    // Why on earth does this WORK???
    return *&*&*&*&*&*&*&*&*&*&*&*&*str_pointer;

    //Hint: here's a diagram.
    /*
    *    str_pointer at          the string, at
    *    address 0x15            address 0x75
    *     ┌─────────┐             ┌──────────┐
    *     │         │             │          │
    * 0x15│  0x75   ├────────►0x75│ "string!"│
    *     │         │             │          │
    *     └─────────┘             └──────────┘
    */
}


// What's going on here? 
// Which of these two functions
// is *more* correct?
void Sample::set_num_plus_5_value(int n){
    n += 5;
    num = n;
}

void Sample::set_num_plus_5_reference(int &n){
    n += 5;
    num = n;
}

Sample::~Sample(){
    std::cout << "**DESTRUCTOR CALLED**" << std::endl;

    // What if 'str_pointer == nullptr'?
    delete str_pointer;

    // Why set it to nullptr after deletion?
    str_pointer = nullptr;
}

