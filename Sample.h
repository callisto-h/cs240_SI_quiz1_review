// What are these? Why do we use them?
#ifndef SAMPLE_H
#define SAMPLE_H

#include <string>
#include <iostream>

class Sample{
    private:
        int num;
        std::string *str_pointer;

    public:

        // What are these functions?
        // How are they different?
        // Can you come up with the ways they are called?
        Sample();
        Sample(int n, std::string const &str);
        Sample(Sample const &s);

        // This isn't a constructor, but we
        // need it... Why?
        // Why do we return a 'Sample&' instead
        // of void?
        Sample & operator=(Sample const &s);

        // How is the `const` keyword
        // different in these two cases?
        void set_str_pointer_memory(std::string const &str);
        std::string get_str_from_str_pointer() const;

        // How are these different?
        void set_num_plus_5_value(int n);
        void set_num_plus_5_reference(int &n);

        // Without looking at the implementation
        // What *should* the destructor do?
        ~Sample();

        // What does this do?
        // Why do we define it as
        // a friend function?
        friend std::ostream& operator<<(std::ostream &o, Sample const &s){
            o << "num=" << s.num;
            o << " | str_pointer points to ";

            if (s.str_pointer == nullptr){
                o << "a nullptr";
                return o;
            }

            // What could happen if we didn't
            // have the above check?
            o << *(s.str_pointer);
            return o;
        }

};



#endif
