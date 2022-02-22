// What are these? Why do we use them?
// ANSWER: These are header guards. We include them
// to prevent the same class from getting defined
// multiple times.
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
        Sample();                               // default constructor: Sample a;
        Sample(int n, std::string const &str);  // value constructor: Sample a(10, "string");
        Sample(Sample const &s);                // copy constructor: Sample a(b);

        // This isn't a constructor, but we
        // need it... Why?
        // Why do we return a 'Sample&' instead
        // of void?
        // ANSWER: We need it to assign the value of one Sample
        // to another.
        // Example:
        // Sample a, b;
        // a = b;
        // We return a `Sample&` to enable assignment chaining.
        // Example:
        // Sample a, b, c;
        // a = b = c;
        Sample & operator=(Sample const &s);

        // How is the `const` keyword
        // different in these two cases?
        // ANSWER: the 'const' keyword in the first function ensures
        // that the string 'str' is never modified. The 'const' keyword
        // in the second ensures that the function does not modify
        // ANY member variables of the object it is called upon.
        void set_str_pointer_memory(std::string const &str);
        std::string get_str_from_str_pointer() const;

        // How are these different?
        // ANSWER: The first is pass by value, the second is pass
        // by reference. The first creates a copy (by calling the
        // copy constructor) of 'n' for the function to use/modify
        // as it likes. The second does not create a copy, allowing
        // the function to modify the 'n' that is outside of the
        // function.
        void set_num_plus_5_value(int n);
        void set_num_plus_5_reference(int &n);

        // Without looking at the implementation
        // What *should* the destructor do?
        // ANSWER: it should use 'delete' on any dynamically
        // allocated memory belonging to the object.
        // In our case, it should 'delete' the 'str_pointer'
        ~Sample();

        // What does this do?
        // Why do we define it as
        // a friend function?
        // ANSWER: This allows us to print the contents of our object
        // (among other things) by putting the member variables into an ostream.
        // It allows us to write the following code:
        // Sample a;
        // std::cout << a << std::endl;
        // The reason that we define it as a friend function is (in non-technical terms)
        // it really SHOULD be a member function of the ostream class, but since we can't
        // edit the ostream class source code -- we write it here and treat it like
        // a ostream member function.
        // Professor Lewis, correct me if I'm wrong!
        friend std::ostream& operator<<(std::ostream &o, Sample const &s){
            o << "num=" << s.num;
            o << " | str_pointer points to ";

            if (s.str_pointer == nullptr){
                o << "a nullptr";
                return o;
            }

            // What could happen if we didn't
            // have the above check?
            // ANSWER: We could have a segmentation fault from dereferencing
            // a nullpointer, or even worse, undefined behavior! We don't want that!
            o << *(s.str_pointer);
            return o;
        }

};



#endif
