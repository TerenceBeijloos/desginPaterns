#pragma once

#define INPUTS 10;

class AND :: public Node {
public:
	AND();
	virtual ~AND();
	bool compareValues(bool inputValues[]);

private:
	bool inputValues[INPUTS];
	bool result;
};


#ifndef __Afgeleide
#define __Afgeleide

#include "Basis.h"

class Afgeleide : public  Basis
{
private:
                        Afgeleide();
                        Afgeleide( int );
public:
    virtual            ~Afgeleide();

public:
            void        actie()         override;

            Basis      *clone() const   override;

private:
    static Afgeleide    m_cInstance;
};

#endif
