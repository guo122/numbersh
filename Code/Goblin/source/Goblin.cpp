
#include "Goblin.h"

Goblin *Goblin::Instance()
{
    static Goblin * obj = new Goblin;
    return obj;
}

Goblin::Goblin()
{
    
}

Goblin::~Goblin()
{
    
}

bool Goblin::_LoadConfig()
{
    bool ret = false;
    
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(s_DataPath);
    if (result)
    {
        for (pugi::xml_node tool: doc.child("Profile").child("Tools").children("Tool"))
        {
            int timeout = tool.attribute("Timeout").as_int();

            if (timeout > 0)
                std::cout << "Tool " << tool.attribute("Filename").value() << " has timeout " << timeout << "\n";
        }
    }
    
    return ret;
}
