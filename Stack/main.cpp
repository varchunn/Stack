#include <iostream>
using namespace std;
template<typename Essence>
class Stack
{
private:
    struct NodeOfDestiny 
    {
        Essence payload;
        NodeOfDestiny* nextPhase;

        NodeOfDestiny(const Essence& element) : payload(element), nextPhase(nullptr) {}
    };

    NodeOfDestiny* apex;
    int magnitude;
public:
    
   Stack() : apex(nullptr), magnitude(0) {}
    ~Stack()
    {
        while (!isEjected()) 
        {
            pullTime();
        }
    }

    void pushTime(const Essence& element) 
    {
        NodeOfDestiny* newPhase = new NodeOfDestiny(element);
        newPhase->nextPhase = apex;
        apex = newPhase;
        magnitude++;
    }
    
    void pullTime() 
    {
        if (isEjected()) 
        {
            std::cerr << "Stack is empty. Cannot pull.\n";
            return;
        }
        NodeOfDestiny* oldPhase = apex;
        apex = apex->nextPhase;
        delete oldPhase;
        magnitude--;
    }
    Essence peakTime() const 
    {
        if (isEjected()) 
        {
            std::cerr << "Stack is empty. Cannot peak.\n";
            return Essence();
        }
        return apex->payload;
    }

    bool isEjected() const
    {
        return apex == nullptr;
    }

    int sizeOfFlux() const 
    {
        return magnitude;
    }
};

int main() 
{
    Stack<int> myFlux;

    myFlux.pushTime(1);
    myFlux.pushTime(2);
    myFlux.pushTime(3);

    cout << "Peak: " << myFlux.peakTime() << std::endl;
    myFlux.pullTime();
    cout << "Peak after pull: " << myFlux.peakTime() << std::endl;

    cout << "Size: " << myFlux.sizeOfFlux() << std::endl;
    return 0;
}

