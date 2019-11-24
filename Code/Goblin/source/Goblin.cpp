
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
    mlTime::Timestamp2String( m_lToday, "%Y%m%d", date_, char_size_ );
}

//-------------------------------------------------------------------------
bool Goblin::SetDay( const char * date_ )
{
    if ( !_Date2Timestamp( date_, m_lToday ) )
    {
        mlLog::Warning("date format wrong.");
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
    char bPath[255];
    mlPath::HomeDash2Absolute( m_sWorkPath.c_str(), bPath );
    sprintf(bPath, "%s/%s.cache.xml", bPath, m_sType.c_str() );
    
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file( bPath );
    if ( !result )
    {
        doc.append_child("NumbershXml").append_attribute("type").set_value(m_sType.c_str());
    }
    pugi::xml_node root = doc.child("NumbershXml");
    
    char cToday[10];
    mlTime::Timestamp2String(m_lToday, "C%Y%m%d", cToday, 10);
    pugi::xml_node node = root.append_child( cToday );
    
    node.append_attribute("Classify").set_value(m_sClassify.c_str());
    node.append_attribute("Kind").set_value(m_sKind.c_str());
    node.append_attribute("Comment").set_value(comment_);
    node.append_attribute("Value").set_value(data_);
    
    doc.save_file( bPath );
}

//-------------------------------------------------------------------------
void Goblin::CacheToStorage()
{
    char bPath[255], bCachePath[255], bStoragePath[255];
    mlPath::HomeDash2Absolute( m_sWorkPath.c_str(), bPath );
    sprintf(bCachePath, "%s/%s.cache.xml", bPath, m_sType.c_str() );
    sprintf(bStoragePath, "%s/%s.xml", bPath, m_sType.c_str() );
    
    pugi::xml_document cache_doc, storage_doc;
    pugi::xml_parse_result cache_result = cache_doc.load_file( bCachePath );
    pugi::xml_parse_result storage_result = storage_doc.load_file( bStoragePath );
    if ( storage_result && cache_result )
    {
        pugi::xml_node cache_root = cache_doc.child("NumbershXml");
        pugi::xml_node storage_root = storage_doc.child("NumbershXml");
        if ( storage_root && cache_root )
        {
            for ( pugi::xml_node node : cache_root.children() )
            {
                pugi::xml_node cur = storage_root.append_child(node.name());
                cur.append_attribute("Classify").set_value(node.attribute("Classify").as_string());
                cur.append_attribute("Kind").set_value(node.attribute("Kind").as_string());
                cur.append_attribute("Comment").set_value(node.attribute("Comment").as_string());
                cur.append_attribute("Value").set_value(node.attribute("Value").as_string());
            }
        }
        storage_doc.save_file( bStoragePath );
        cache_doc.reset();
        cache_doc.save_file( bCachePath );
    }
    else if ( cache_result )
    {
        cache_doc.save_file( bStoragePath );
        cache_doc.reset();
        cache_doc.save_file( bCachePath );
    }
}

void Goblin::ShowStatus()
{
    char cDate[11];
    Goblin::Instance()->GetDay( cDate, 11 );
    mlLog::Print( "[%s] %s\n", m_sType.c_str(), cDate );
    mlLog::Print( "%s / %s\n", m_sClassify.c_str(), m_sKind.c_str() );
}

//-------------------------------------------------------------------------
void Goblin::ShowCache()
{
    char bPath[255];
    mlPath::HomeDash2Absolute( m_sWorkPath.c_str(), bPath );
    sprintf(bPath, "%s/%s.cache.xml", bPath, m_sType.c_str() );
    _ShowList( bPath, m_sType.c_str() );
}

//-------------------------------------------------------------------------
void Goblin::ShowStorage()
{
    char bPath[255];
    mlPath::HomeDash2Absolute( m_sWorkPath.c_str(), bPath );
    sprintf(bPath, "%s/%s.xml", bPath, m_sType.c_str() );
    _ShowList( bPath, m_sType.c_str() );
}

//-------------------------------------------------------------------------
void Goblin::ShowGeneral()
{
    
}

//-------------------------------------------------------------------------
void Goblin::ShowAllData()
{
    char bPath[255];
    mlPath::HomeDash2Absolute( m_sWorkPath.c_str(), bPath );
    sprintf(bPath, "%s/%s.xml", bPath, m_sType.c_str() );
    _ShowList( bPath, m_sType.c_str() );
    
    mlPath::HomeDash2Absolute( m_sWorkPath.c_str(), bPath );
    sprintf(bPath, "%s/%s.cache.xml", bPath, m_sType.c_str() );
    _ShowList( bPath, "cache" );
}

//-------------------------------------------------------------------------
void Goblin::ShowHelp()
{
    
}

//-------------------------------------------------------------------------
bool Goblin::_SaveRuntimeData()
{
    pugi::xml_document doc;
    
    pugi::xml_node root = doc.append_child("NumbershRuntime");
    root.append_attribute("ConfigPath").set_value(m_sConfigPath.c_str());
    
    pugi::xml_node runtime = root.append_child("Runtime");
    
    char cToday[9];
    mlTime::Timestamp2String(m_lToday, "%Y%m%d", cToday, 9);
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
            mlLog::Warning("file today date format wrong.");
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
void Goblin::_ShowList( const char * path_, const char * tag_ )
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file( path_ );
    if ( result )
    {
        pugi::xml_node root = doc.child("NumbershXml");
        if ( root )
        {
            mlLog::Print("---%s---\n", tag_ );
            for ( pugi::xml_node node : root.children() )
            {
                mlLog::Print("[%s] %s/%s: %.2f\t%s\n", node.name() + 1, node.attribute("Classify").as_string(), node.attribute("Kind").as_string(),
                             node.attribute("Value").as_float(), node.attribute("Comment").as_string() );
            }
        }
    }
}

//-------------------------------------------------------------------------
bool Goblin::_Date2Timestamp( const char * date_, long & timestamp_ )
{
    if ( strlen(date_) == 8 )
    {
        char cDatetime[18];
        strcpy(cDatetime, date_);
        strcat(cDatetime, " 00:00:00");
        mlTime::String2Timestamp(cDatetime, "%Y%m%d %H:%M:%S", timestamp_);
        
        return timestamp_ >= 0;
    }
    return false;
}
