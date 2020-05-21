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




#include "Node.h"

class AND : public  NODE
{
private:
                        AND();
                        AND( int );
public:
    virtual            ~NODE();

public:
            void        actie()         override;

            Basis      *clone() const   override;

private:
    static Afgeleide    m_cInstance;
};


