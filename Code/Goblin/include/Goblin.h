
#ifndef _GOBLIN_H_9ED50DDE725C9E67C1D265678FD027F0_
#define _GOBLIN_H_9ED50DDE725C9E67C1D265678FD027F0_

#include "define.h"

class Goblin
{
public:
    static Goblin * Instance();
    static void Destory();
    
public:
    void    NextDay();
    void    PrevDay();
    void    GetDay( char * date_, int char_size_ );
    bool    SetDay( const char * date_ );
    
    const char *    GetType();
    void            SetType( const char * type_ );
    const char *    GetClassify();
    void            SetClassify( const char * classify_ );
    const char *    GetKind();
    void            SetKind( const char * kind_ );
    
public:
    void    AddDataToCache( float data_, const char * comment_ );
    void    CacheToStorage();
    
private:
    bool    _SaveRuntimeData();
    bool    _LoadRuntimeData();
    
    bool    _LoadConfig();
    
    bool    _Date2Timestamp( const char * date_, long & timestamp_ );
    
private:
    std::string     m_sConfigPath{ "~/etc/numbersh.xml" };
    std::string     m_sWorkPath{ "~/Documents" };
    long            m_lToday{ 0 };
    std::string     m_sType{ "" };
    std::string     m_sClassify{ "" };
    std::string     m_sKind{ "" };
    
private:
    Goblin();
    ~Goblin();
};

#endif // _GOBLIN_H_9ED50DDE725C9E67C1D265678FD027F0_
