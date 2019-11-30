
#ifndef _GOBLIN_H_9ED50DDE725C9E67C1D265678FD027F0_
#define _GOBLIN_H_9ED50DDE725C9E67C1D265678FD027F0_

#include "define.h"

static const int _PATH_MAX = 255;
static const int _CLASSIFY_MAX = 50;

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
    
public:
    void    ShowStatus();
    void    ShowCache();
    void    ShowStorage();
    void    ShowGeneral( const char * c1, const char * c2 );
    void    ShowAllData();
    void    ShowHelp();
    void    ShowVersion();
    
public:
    void    PrintComplete( const char * cmd_ );
    
private:
    bool    _SaveRuntimeData();
    bool    _LoadRuntimeData();
    
    bool    _LoadConfig();
    
    void    _ShowGeneral( const char * path_, const long & begin_ = -1, const long & end_ = -1 );
    void    _ShowList( const char * path_, const char * tag_ );
    
private:
    char     m_cConfigPath[_PATH_MAX]{ "~/Documents/numbersh.xml" };
    char     m_cWorkPath[_PATH_MAX]{ "~/Documents" };
    long     m_lToday{ 0 };
    char     m_cType[_CLASSIFY_MAX]{ "" };
    char     m_cClassify[_CLASSIFY_MAX]{ "" };
    char     m_cKind[_CLASSIFY_MAX]{ "" };
    
private:
    Goblin();
    ~Goblin();
};

#endif // _GOBLIN_H_9ED50DDE725C9E67C1D265678FD027F0_
