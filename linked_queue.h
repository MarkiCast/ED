//! Copyright [2018] <Marcelo Dutra Mendonça>

#include <stdexcept>

namespace structures {
template<typename T>

//!...
class LinkedQueue {
 public:
    //!...
    LinkedQueue() = default;
    //!...
    ~LinkedQueue() = default;
    //!...
    void clear() {
      this->size_ = 0;
      this->tail = nullptr;
      this->head = nullptr;
    }  // limpar
    //!...
    void enqueue(const T& data) {
      auto n = new Node(data);

      if ( n == nullptr ) {
        throw std::out_of_range("Fila cheia");
      } else if ( empty() ) {
        tail = n;
        head = n;
      } else {
        tail->next(n);
        tail = n;
      }
      size_++;
    }  // enfilerar
    //!...
    T dequeue() {
      if ( empty() ) {
            throw std::out_of_range("Fila vazia");
      }
      auto ret = head;
      head = head->next();

      if (size() == 1) {
        tail = nullptr;
      }


      size_--;

      return ret->data();
    }  // desenfilerar
    //!...
    T& front() const {
      if ( empty() ) {
          throw std::out_of_range("Fila vazia");
      }
      return this->head->data();
    }  // primeiro dado
    //!...
    T& back() const {
      if ( empty() ) {
        throw std::out_of_range("Fila vazia");
      }
      return this->tail->data();
    }  // último dado
    //!...
    bool empty() const {
      if ( size() == 0 ) {
        return true;
      } else {
        return false;
      }
    }  // fila vazia
    //!...
    int size() const {
      return this->size_;
    }  // tamanho

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
        Node* next_{nullptr};
    };

    Node* head{nullptr};  // nodo-cabeça
    Node* tail{nullptr};  // nodo-fim
    int size_ = 0;  // tamanho
};

}  // namespace structures
