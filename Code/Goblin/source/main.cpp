
#include "Goblin.h"

int main( int argc, const char * argv[] )
{
    if ( argc > 1 )
    {
        mlCmd::Phrase phrase( argc, argv );
        const char * cmd = phrase.next();
        if ( strcmp( cmd, "type") == 0 )
        {
            Goblin::Instance()->SetType( phrase.next() );
        }
        else if ( strcmp( cmd, "classify") == 0 )
        {
            Goblin::Instance()->SetClassify( phrase.next() );
        }
        else if ( strcmp( cmd, "kind") == 0 )
        {
            Goblin::Instance()->SetKind( phrase.next() );
        }
        else if ( strcmp( cmd, "next") == 0 )
        {
            Goblin::Instance()->NextDay();
        }
        else if ( strcmp( cmd, "prev") == 0 )
        {
            Goblin::Instance()->PrevDay();
        }
        else if ( strcmp( cmd, "date") == 0 )
        {
            Goblin::Instance()->SetDay( phrase.next() );
        }
        else if ( strcmp( cmd, "save") == 0 )
        {
            Goblin::Instance()->CacheToStorage();
        }
        else if ( strcmp( cmd, "cache") == 0 )
        {
            Goblin::Instance()->ShowCache();
        }
        else if ( strcmp( cmd, "storage") == 0 )
        {
            Goblin::Instance()->ShowStorage();
        }
        else if ( strcmp( cmd, "all") == 0 )
        {
            Goblin::Instance()->ShowAllData();
        }
        else if ( strcmp( cmd, "current") == 0 )
        {
            Goblin::Instance()->ShowGeneral();
        }
        else if ( strcmp( cmd, "help") == 0 )
        {
            Goblin::Instance()->ShowHelp();
        }
        else
        {
            Goblin::Instance()->AddDataToCache( atof( cmd ), phrase.next() );
        }
    }
    else
    {
        Goblin::Instance()->ShowStatus();
    }
    Goblin::Destory();
    return 0;
}
