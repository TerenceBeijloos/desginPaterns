#pragma once

#include <map>

namespace Factory
{
    template <typename nodeType, typename Class>
    class FactoryMethod
    {
    private:
        FactoryMethod() = default;
        virtual            ~FactoryMethod() = default;

    private:
        static  void        assign(const nodeType&, const Class*);
    public:
        static  Class* create(const nodeType&);

    private:
        typedef std::map<nodeType, const Class*> FactoryMap;

        static  FactoryMap& getMap();
    private:
        friend Class;
    };
#include "factoryMethod.hpp"
}
