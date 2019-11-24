
#ifndef _GOBLIN_H_9ED50DDE725C9E67C1D265678FD027F0_
#define _GOBLIN_H_9ED50DDE725C9E67C1D265678FD027F0_

#include "define.h"

class Goblin
{
public:
    static Goblin * Instance();
    
private:
    bool    _LoadConfig();
    
private:
    bool    m_bReady{false};
    int     m_today{0};
    
private:
    Goblin();
    ~Goblin();
};

#endif // _GOBLIN_H_9ED50DDE725C9E67C1D265678FD027F0_
