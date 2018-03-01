#ifndef _OFX_WATCHBOOT_H
#define _OFX_WATCHBOOT_H

#include "ofMain.h"
#include "ofxNetwork.h"

class ofxWatchBoot
{
public:
    ofxWatchBoot(){
    
    }
    
    ~ofxWatchBoot(){
    
    }
    
    void setup(string _host)
    {
        host = _host;
        client.setMessageDelimiter("\r\n");
    }
    
    void power(bool on_off, int port)
    {
        if(client.isConnected() == false){
            client.setup(host.c_str(), 23);
            
            ofSleepMillis(2);
            
            client.send("\r\n");

            ofSleepMillis(2);

            client.send("admin");
            ofSleepMillis(2);
            client.send("magic");
            ofSleepMillis(2);
            
            if(port == 1 && on_off == true) client.send("PON1");
            if(port == 2 && on_off == true) client.send("PON2");
            if(port == 1 && on_off == false) client.send("POF1");
            if(port == 2 && on_off == false) client.send("POF2");

            ofSleepMillis(2);

            client.close();
        }
    }
    
private:
    string host;
    ofxTCPClient client;
    
};

#endif
