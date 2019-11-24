
#include "Goblin.h"

static Goblin * obj = nullptr;

//-------------------------------------------------------------------------
Goblin *Goblin::Instance()
{
    if ( !obj )
    {
        obj = new Goblin;
    }
    return obj;
}

//-------------------------------------------------------------------------
void Goblin::Destory()
{
    if ( obj )
    {
        delete obj;
        obj = nullptr;
    }
}

//-------------------------------------------------------------------------
Goblin::Goblin()
{
    _LoadRuntimeData();
    _LoadConfig();
}

//-------------------------------------------------------------------------
Goblin::~Goblin()
{
    _SaveRuntimeData();
}

//-------------------------------------------------------------------------
void Goblin::NextDay()
{
    if ( m_lToday <= LONG_MAX - 86400 )
    {
        m_lToday += 86400;
    }
}

//-------------------------------------------------------------------------
void Goblin::PrevDay()
{
    if ( m_lToday >= LONG_MIN + 86400 )
    {
        m_lToday -= 86400;
    }
}
//-------------------------------------------------------------------------
void Goblin::GetDay( char * date_, int char_size_ )
{
    mlTime::Timestamp2String( m_lToday, "%Y-%m-%d", date_, char_size_ );
}

//-------------------------------------------------------------------------
bool Goblin::SetDay( const char * date_ )
{
    if ( !_Date2Timestamp( date_, m_lToday ) )
    {
        std::cout << "[Warning] date format wrong." << std::endl;
        return false;
    }

    return true;
}

//-------------------------------------------------------------------------
const char * Goblin::GetType()
{
    return m_sType.c_str();
}

//-------------------------------------------------------------------------
void Goblin::SetType( const char * type_ )
{
    m_sType = type_;
}

//-------------------------------------------------------------------------
const char * Goblin::GetClassify()
{
    return m_sClassify.c_str();
}

//-------------------------------------------------------------------------
void Goblin::SetClassify( const char * classify_ )
{
    m_sClassify = classify_;
}

//-------------------------------------------------------------------------
const char * Goblin::GetKind()
{
    return m_sKind.c_str();
}

//-------------------------------------------------------------------------
void Goblin::SetKind( const char * kind_ )
{
    m_sKind = kind_;
}

//-------------------------------------------------------------------------
void Goblin::AddDataToCache( float data_, const char * comment_ )
{
    
}

//-------------------------------------------------------------------------
void Goblin::CacheToStorage()
{
    
}

//-------------------------------------------------------------------------
bool Goblin::_SaveRuntimeData()
{
    pugi::xml_document doc;
    
    pugi::xml_node root = doc.append_child("NumbershRuntime");
    root.append_attribute("ConfigPath").set_value(m_sConfigPath.c_str());
    
    pugi::xml_node runtime = root.append_child("Runtime");
    
    char cToday[11];
    mlTime::Timestamp2String(m_lToday, "%Y-%m-%d", cToday, 11);
    runtime.append_attribute("Today").set_value(cToday);
    runtime.append_attribute("Type").set_value(m_sType.c_str());
    runtime.append_attribute("Classify").set_value(m_sClassify.c_str());
    runtime.append_attribute("Kind").set_value(m_sKind.c_str());
    
    char bPath[255];
    mlPath::HomeDash2Absolute( s_RuntimeDataPath, bPath );
    return doc.save_file( bPath );
}

//-------------------------------------------------------------------------
bool Goblin::_LoadRuntimeData()
{
    bool ret = false;
    
    pugi::xml_document doc;
    char bPath[255];
    mlPath::HomeDash2Absolute( s_RuntimeDataPath, bPath );
    pugi::xml_parse_result result = doc.load_file( bPath );
    if (result)
    {
        pugi::xml_node root  = doc.child("NumbershRuntime");
        m_sConfigPath = root.attribute("ConfigPath").as_string();
        
        pugi::xml_node runtime = root.child("Runtime");
        if ( !_Date2Timestamp( runtime.attribute("Today").as_string(), m_lToday ) )
        {
            std::cout << "[Warning] file today datetime wrong." << std::endl;
        }
        m_sType = runtime.attribute("Type").as_string();
        m_sClassify = runtime.attribute("Classify").as_string();
        m_sKind = runtime.attribute("Kind").as_string();
    }
    
    return ret;
}

//-------------------------------------------------------------------------
bool Goblin::_LoadConfig()
{
    pugi::xml_document doc;
    char bPath[255];
    mlPath::HomeDash2Absolute( m_sConfigPath.c_str(), bPath );
    pugi::xml_parse_result result = doc.load_file(bPath);
    if (result)
    {
        pugi::xml_node root  = doc.child("NumbershConfig");
        
        m_sWorkPath = root.attribute("WorkPath").as_string();
        return true;
    }
    else
    {
        pugi::xml_node root = doc.append_child("NumbershConfig");
        root.append_attribute("WorkPath").set_value("~/Documents");
        return doc.save_file( bPath );
    }
}
//-------------------------------------------------------------------------
bool Goblin::_Date2Timestamp( const char * date_, long & timestamp_ )
{
    if ( strlen(date_) == 10 )
    {
        char cDatetime[20];
        strcpy(cDatetime, date_);
        strcat(cDatetime, " 00:00:00");
        mlTime::String2Timestamp(cDatetime, "%Y-%m-%d %H:%M:%S", timestamp_);
        
        return timestamp_ >= 0;
    }
    return false;
}
