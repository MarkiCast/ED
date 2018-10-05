//! Copyright [2018] <Marcelo Dutra Mendonça>
namespace structures {

#include <memory>
#include <stdexcept>

template<typename T>

//!...
class LinkedStack {
 public:
    //!...
    LinkedStack() = default;
    //!...
    ~LinkedStack() = default;

    void clear() {
      this->size_ = 0;
      this->top = nullptr;
    } // limpa pilha

    void push(const T& data) {
      Node* n = new Node(data);
      if (n == nullptr) {
          throw std::out_of_range("Pilha cheia");
      }
      n->next(top_);
      this->top_ = n;
      this->size_++;
    } // empilha

    T pop() {
      if( empty() ) {
        throw std::out_of_range("Pilha vazia");
      } else {
      auto tmp = this->top_;
      this->top_ = this->top_->next();
      this->size_--;
      return tmp->data();
      }
    } // desempilha

    T& top() const {
      auto out = top_->data();
    } // dado no topo

    bool empty() const {
      if (size() == 0) {
        return true;
      } else {
        return false;
      }
    } // pilha vazia

    std::size_t size() const {
      return size_;
    } // tamanho da pilha

 private:
    class Node {
     public:
       explicit Node(const T& data):
           data_{data}
       {}

       Node(const T& data, Node* next):
           data_{data},
           next_{next}
       {}

       T& data() {  // getter: dado
           return data_;
       }

       const T& data() const {  // getter const: dado
           return data_;
       }

       Node* next() {  // getter: próximo
           return next_;
       }

       const Node* next() const {  // getter const: próximo
           return next_;
       }

       void next(Node* node) {  // setter: próximo
           next_ = node;
       }

     private:
        T data_;
        Node* next_;
    };

    Node* top_; // nodo-topo
    int size_ = 0; // tamanho
};

} // namespace structures
