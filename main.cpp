#include "gloghelper.h"
using namespace std;
 
int main()
{
    GLogHelper loghelper;
    loghelper.InitLogger();
    LOG(ERROR)<<"log test";
 
    return 0;
}
 
 
