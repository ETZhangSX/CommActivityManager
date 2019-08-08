#include "QueryServer.h"
#include "QueryImp.h"
#include "Config.h"

using namespace std;

QueryServer g_app;

/////////////////////////////////////////////////////////////////
void
QueryServer::initialize()
{
    //initialize application here:
    //...

    addConfig(ServerConfig::ServerName + ".conf");
    const std::string strConfFileName = ServerConfig::BasePath + ServerConfig::ServerName + ".conf";
    LOG->debug()<< "conf: " << strConfFileName << endl;
    SConfig::getInstance()->LoadConfig(strConfFileName);
    
    addServant<QueryImp>(ServerConfig::Application + "." + ServerConfig::ServerName + ".QueryObj");
}
/////////////////////////////////////////////////////////////////
void
QueryServer::destroyApp()
{
    //destroy application here:
    //...
}
/////////////////////////////////////////////////////////////////
int
main(int argc, char* argv[])
{
    try
    {
        g_app.main(argc, argv);
        g_app.waitForShutdown();
    }
    catch (std::exception& e)
    {
        cerr << "std::exception:" << e.what() << std::endl;
    }
    catch (...)
    {
        cerr << "unknown exception." << std::endl;
    }
    return -1;
}
/////////////////////////////////////////////////////////////////
