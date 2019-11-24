
#ifndef _PHRASE_H_4AC508E9C56D2942346890B1E6A207A8_
#define _PHRASE_H_4AC508E9C56D2942346890B1E6A207A8_

namespace mlCmd
{

class Phrase
{
public:
    Phrase( int argc, const char * argv[] );
    ~Phrase();
    
public:
    const char * next();
    
private:
    const int m_argc;
    const char ** m_argv;
    int m_lNextCmd{ 1 };
    // todo(gzy): option
    int m_lNextOption{ -1 };
};

};

#endif // _PHRASE_H_4AC508E9C56D2942346890B1E6A207A8_
