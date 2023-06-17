 #include "MagicalContainer.hpp"
 #include <math.h>
 #include <algorithm>

using namespace std;

namespace ariel{

// check if prime
    bool isPrime(int element)
{
    if (element < 2) {
        return false;
    }

    for (int i = 2; i <= sqrt(element); i++)
 {
        if (element % i == 0) {
            return false;
        }
    }

    return true;
}

    void MagicalContainer::sortBaselElem()
    {
        for(unsigned long i = 0; i < baseElam.size(); i++)
        {
            for(unsigned long j = 0; j < baseElam.size() - i - 1; j++)
            {
                if(baseElam[j] > baseElam[j + 1])
                {
                    int temp = baseElam[j];
                    baseElam[j] = baseElam[j + 1];
                    baseElam[j + 1] = temp;
                }
            }
        }
    }

    //update the ascend
    void MagicalContainer::refreshAscend()
{
    ascendElam.clear();
    ascendElam.reserve(baseElam.size());

    for (int& element : baseElam)
    {
        ascendElam.push_back(&element);
    }
}

    //update the prime
   void MagicalContainer::refreshPrime()
{
    primeElem.clear();
    primeElem.reserve(baseElam.size());

    for (int& element : baseElam)
    {
        if (isPrime(element))
        {
            primeElem.push_back(&element);
        }
    }
}

    //update the cross
    void MagicalContainer::refreshCross()
    {
        crossElem.clear();
        auto start = baseElam.begin();
        auto end = --baseElam.end();

        while(start < end)
        {
            crossElem.push_back(&(*start));
            crossElem.push_back(&(*end));
            start++;
            end--;
        }
        if (start == end)
        {
            crossElem.push_back(&(*start));
        }

    }

    //  MagicalContainer 

    //func to add elements
    void MagicalContainer::addElement(int element)
    {   
        // add to baseElam
        baseElam.push_back(element);
        
        sortBaselElem();

        refreshAscend();
        refreshPrime();
        refreshCross();
    }

     //func to remove elements
    void MagicalContainer::removeElement(int element)
    {
        // check if element is in baseElam
        bool found = false;
        for (auto it = baseElam.begin(); it != baseElam.end(); ++it)
        {
            if (*it == element)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            throw std::runtime_error("Invalid argument");
        }

        baseElam.erase(std::remove(baseElam.begin(), baseElam.end(), element), baseElam.end());
        refreshAscend();
        refreshPrime();
        refreshCross();

    }

    //return the size
    int MagicalContainer::size()
    {
        return baseElam.size();
    }





    //  AscendingIterator



    // Constructors

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container) : container(container), iter(container.ascendElam.begin()), ind(0) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) : container(other.container), iter(other.iter), ind(other.ind) {}

    //assigning the value of one AscendingIterator object to another
   MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other)
{
    if (this == &other) // Check for self-assignment
    {
        return *this;
    }
    
    if (&container != &other.container) // Check if they are not the same container
    {
        throw std::runtime_error("Invalid argument");
    }

    container = other.container;
    iter = other.iter;
    ind = other.ind;
    
    return *this;
}


    // Operators

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
{
    if (iter == container.ascendElam.end())
    {
        throw std::runtime_error("Out of range");
    }
    
    ++iter;
    ++ind;
    
    return *this;
}

int MagicalContainer::AscendingIterator::operator*()
{
    if (iter == container.ascendElam.end())
    {
        throw std::out_of_range("Out of range");
    }
    return **iter; 
}


    // Comparison operators

   bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const
{
    if (&container != &other.container) 
    {
        throw std::invalid_argument("Invalid argument");
    }
    
    return iter == other.iter;
}

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const
    {
        return !(*this == other);
    }

   bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const
{
    if(&container != &other.container) 
    {
        throw std::invalid_argument("Invalid argument");
    }
    return ind < other.ind;
}


    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const
    {
        if(&container != &other.container) 
        {
            throw std::invalid_argument("Invalid argument");
        }
        return ind > other.ind;
    }

    // Getters

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::begin()
    {
        iter = container.ascendElam.begin(); 
        ind = 0;                             
        return *this;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::end()
    {
        iter = container.ascendElam.end(); 
        ind = container.ascendElam.size(); 
        return *this;
    }


    //  SideCrossIterator 


    // Constructors

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) : container(container), iter(container.crossElem.begin()), ind(0) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) : container(other.container), iter(other.iter), ind(other.ind) {}

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other)
    {
        if (this == &other) // Check for self-assignment
    {
        return *this;
    }
    
    if (&container != &other.container) 
    {
        throw std::runtime_error("Invalid argument");
    }

    container = other.container;
    iter = other.iter;
    ind = other.ind;
    
    return *this;
    }
    // Operators

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++()
    {
        if(iter == container.crossElem.end())
        {
            throw std::runtime_error("Out of range");
        }
        ++iter;
        ++ind;
        return *this;
    }

    int& MagicalContainer::SideCrossIterator::operator*()
    {
        if(iter == container.crossElem.end())
        {
            throw std::out_of_range("Out of range");
        }
        return **iter;
    }

    // Comparison operators

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const
    {
        if(&container != &other.container) 
        {
            throw std::invalid_argument("Invalid argument");
        }
        return ind == other.ind;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const
    {
        if(&container != &other.container) 
        {
            throw std::invalid_argument("Invalid argument");
        }
        return ind < other.ind;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const
    {
        if(&container != &other.container) 
        {
            throw std::invalid_argument("Invalid argument");
        }
        return ind > other.ind;
    }

    // Getters

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::begin()
    {
        iter = container.crossElem.begin();
        ind = 0;                             
        return *this;
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::end()
    {
        iter = container.crossElem.end(); 
        ind = container.crossElem.size();
        return *this;
    }


    // PrimeIterator

    // Constructors

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container) : container(container), iter(container.primeElem.begin()), ind(0) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) : container(other.container), iter(other.iter), ind(other.ind) {}

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other)
    {
       if (this == &other) // Check for self-assignment
    {
        return *this;
    }
    
    if (&container != &other.container) 
    {
        throw std::runtime_error("Invalid argument");
    }

    container = other.container;
    iter = other.iter;
    ind = other.ind;
    
    return *this;
    }
    // Operators

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++()
    {
        if(iter == container.primeElem.end())
        {
            throw std::runtime_error("Out of range");
        }
        ++iter;
        ++ind;
        return *this;
    }

    int& MagicalContainer::PrimeIterator::operator*()
    {   
        if(iter == container.primeElem.end())
        {
            throw std::out_of_range("Out of range");
        }
        return **iter;
    }

    // Comparison operators

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const
    {
        if(&container != &other.container)
        {
            throw std::invalid_argument("Invalid argument");
        }
        return ind == other.ind;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const
    {
        if(&container != &other.container)
        {
            throw std::invalid_argument("Invalid argument");
        }
        return ind < other.ind;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const
    {
        if(&container != &other.container) 
        {
            throw std::invalid_argument("Invalid argument");
        }
        return ind > other.ind;
    }

    // Getters

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::begin()
    {
        iter = container.primeElem.begin(); 
        ind = 0;                             
        return *this;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::end()
    {
        iter = container.primeElem.end();
        ind = container.primeElem.size(); 
        return *this;
    }

}

