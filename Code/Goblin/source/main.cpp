
#include "Goblin.h"

int main()
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("test.xml");
    if (!result)
        return -1;
        
    for (pugi::xml_node tool: doc.child("Profile").child("Tools").children("Tool"))
    {
        int timeout = tool.attribute("Timeout").as_int();
        
        if (timeout > 0)
            std::cout << "Tool " << tool.attribute("Filename").value() << " has timeout " << timeout << "\n";
    }
    
    return 0;
}
