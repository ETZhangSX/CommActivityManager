#ifndef _QueryServer_H_
#define _QueryServer_H_

#include <iostream>
#include "servant/Application.h"

using namespace tars;

/**
 *
 **/
class QueryServer : public Application
{
public:
    /**
     *
     **/
    virtual ~QueryServer() {};

    /**
     *
     **/
    virtual void initialize();

    /**
     *
     **/
    virtual void destroyApp();
};

extern QueryServer g_app;

////////////////////////////////////////////
#endif
