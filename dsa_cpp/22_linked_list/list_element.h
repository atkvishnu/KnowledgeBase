#include <memory>

#ifndef PROJECT_LISTELEMENT_H
#define PROJECT_LISTELEMENT_H

namespace kv{

    template <class T>
    class ListElement {
    private:
        ListElement<T> *next_;
        T data_;

    public:
        ListElement(const T &value): next_(nullptr), data_(value) {}    // constructor
        ListElement(const ListElement &) = delete;                      // copy constructor
        ListElement &operator=(const ListElement &) = default;          // assignment operator
        
        ~ListElement() {}                                               // destructor

        const T &GetData() const {     // get data
            return data_; 
        }                     
        ListElement<T> *GetNext() const {     // get next
            return next_;
        }               
        void SetData(const T &data) {   // set data
            data_ = data; 
        }                   
        void SetNext(ListElement<T> *elem) {    // set next
            next_ = elem; 
        }                
    };
}

#endif //PROJECT_LISTELEMENT_H