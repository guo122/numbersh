
#include "Phrase.h"

namespace mlCmd
{

//-------------------------------------------------------------------------
Phrase::Phrase( int argc, const char * argv[] )
    : m_argc( argc )
    , m_argv( argv )
{
    
}

//-------------------------------------------------------------------------
Phrase::~Phrase()
{
    
}

//-------------------------------------------------------------------------
const char * Phrase::next()
{
    if ( m_lNextCmd > 0 && m_lNextCmd < m_argc )
    {
        if ( m_argv[m_lNextCmd][0] == '-' )
        {
            m_lNextCmd += 2;
        }
        return m_argv[m_lNextCmd++];
    }
    else
    {
        m_lNextCmd = -1;
    }
    return "";
}

};
