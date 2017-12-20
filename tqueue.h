
#ifndef ADTSTACK_TQUEUE_H
#define ADTSTACK_TQUEUE_H

#include <iostream>
#include <cstdlib>
using namespace std;

namespace fsu{
    template <typename T>
    class Queue{
    public:
        Queue (); // default constructor
        Queue (char ofc); // sets output formatting character
        Queue (const Queue&); // copy constructor
        ~Queue (); // destructor
        Queue& operator = (const Queue&); // assignment operator

        void Push (const T& t);
        T Pop ();
        T& Front ();
        const T& Front () const;
        size_t Size () const;
        bool Empty () const;
        void Clear ();
        // extra goodies
        size_t Capacity () const;
        void Append (const Queue& q);
        void Release ();

        void Display (std::ostream& os) const; // output queue contents through os - depends on ofc
        void SetOFC (char ofc); // sets output formatting character
        void Dump (std::ostream& os) const; // output all private data (for development use only)

    private:
        char ofc_;

        class Link {
            Link ( const T& t ) : element_(t), nextLink_(nullptr) {}
            T element_;
            Link * nextLink_;
            friend class Queue<T>;
        };
        Link * firstLink_;
        Link * lastLink_;
    };

    template < typename T >
    std::ostream& operator << (std::ostream& os, const Queue<T>& q) {
        q.Display (os);
        return os;
    }

    template <typename T>
    Queue<T>::Queue() {
        ofc_ = '\0';
        firstLink_ = nullptr;
        lastLink_ = nullptr;
    }

    template <typename T>
    Queue<T>::Queue(char ofc) {
        ofc_ = ofc;
        firstLink_ = nullptr;
        lastLink_ = nullptr;
    }

    template <typename T>
    Queue<T>::Queue(const Queue &q) {
        // todo: done
//        cout << "Inside cppy ctor\n";
        ofc_ = q.ofc_;
        firstLink_ = nullptr;
        lastLink_ = nullptr;
        Append(q);
    }

    template <typename T>
    Queue<T>::~Queue() {
        // todo: done
        Release();
    }

    template <typename T>
    Queue<T>& Queue<T>::operator=(const Queue &q) {
        // todo: done
        if(this != &q){
            Release();
            Append(q);
        }
        return *this;
    }

    template <typename T>
    void Queue<T>::Push(const T &t) {  // Insert at the end of the list
        Link *newLink = new Link(t);
        if(!firstLink_){
            firstLink_ = lastLink_ = newLink;
            return;
        }
        lastLink_->nextLink_ = newLink;//cout << "new node\n";
        lastLink_ = newLink;
    }

    template <typename T>
    T Queue<T>::Pop() {                // Delete it from the front of the list
        if(Empty()){
            cout << "Queue is empty. Operation will be undefined\n";
//            return round_toward_infinity;
            return T();
        }
        Link *tempLink = firstLink_;
        T element = tempLink->element_;
        firstLink_ = firstLink_->nextLink_;
        delete tempLink;

        return element;
    }

    template <typename T>
    T& Queue<T>::Front() {
        if(Empty()){
            cout << "Queue is empty. Operation will be undefined\n";
//            return round_toward_infinity;
        }

        return firstLink_->element_;
    }

    template <typename T>
    const T& Queue<T>::Front() const {
        if(Empty()){
            cout << "Queue is empty. Operation will be undefined\n";
//            return round_toward_infinity;
        }

        return firstLink_->element_;
    }

    template <typename T>
    size_t Queue<T>::Size() const {
        Link *temp = firstLink_;
        size_t count = 0;
        while(temp){
            count++;
            temp = temp->nextLink_;
        }

        return count;
    }

    template <typename T>
    bool Queue<T>::Empty() const {
        return Size() == 0;
    }

    template <typename T>
    void Queue<T>::Clear() {
        // todo: done
        Release();
    }

    template <typename T>
    size_t Queue<T>::Capacity() const {
        return Size();
    }

    template <typename T>
    void Queue<T>::Append(const Queue &q) {
        Link *tempLink = q.firstLink_;

        if(tempLink == nullptr){
            firstLink_ = lastLink_ = tempLink;
            return;
        }
//        cout << q;
        while(tempLink){
//            cout << tempLink->element_;
            Link *newLink = new Link(tempLink->element_);

            if(!firstLink_){
                firstLink_ = lastLink_ = newLink;
                tempLink = tempLink->nextLink_;
                continue;
            }

            lastLink_->nextLink_ = newLink;
            lastLink_ = newLink;
            tempLink = tempLink->nextLink_;
        }
    }

    template <typename T>
    void Queue<T>::Release() {
        Link *tempLink = firstLink_;
        while(tempLink){
            firstLink_ = firstLink_->nextLink_;
            delete tempLink;
            tempLink = firstLink_;
        }
    }

    template <typename T>
    void Queue<T>::Display(std::ostream &os) const {
        if(!firstLink_){
            cout << "Queue is empty\n";
            return;
        }
        for(Link *i = firstLink_; i != nullptr; i = i->nextLink_){
            os << i->element_;
            if(ofc_ != '\0'){
                cout << ofc_;
            }
        }
        std::cout << "\n";
    }

    template <typename T>
    void Queue<T>::SetOFC(char ofc) {
        ofc_ = ofc;
    }

    template <typename T>
    void Queue<T>::Dump(std::ostream &os) const {
        os << "Queue: " << *this;
        os << "Capacity: " << Capacity() << "\n";
        os << "Size: " << Size() << "\n";
        os << "OFC: " << ofc_ << "\n";
    }
}




#endif //ADTSTACK_TQUEUE_H
