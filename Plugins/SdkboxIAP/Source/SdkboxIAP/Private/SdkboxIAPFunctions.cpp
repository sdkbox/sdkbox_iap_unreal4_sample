/****************************************************************************
 Copyright (c) 2015 SDKBOX Inc.
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "SdkboxIAPPrivatePCH.h"
#include "PluginIAP.h"

int USdkboxIAPFunctions::_initCount = 0;
USdkboxIAPListener* USdkboxIAPFunctions::_listener = nullptr;

void USdkboxIAPFunctions::SdkboxIapInitialize(FString jsonstring)
{
#if PLATFORM_IOS || PLATFORM_ANDROID
    if (0 == _initCount && !_listener)
    {
        _listener = NewObject<USdkboxIAPListener>(USdkboxIAPListener::StaticClass());
        sdkbox::IAP::setListener(_listener);
    }
    
    const char* s = (const char*)TCHAR_TO_UTF8(*jsonstring);
    if (s)
    {
        printf("got a string %s\n", s);
    }
    else
    {
        printf("wtf jsonstring is NULL\n");
    }
    sdkbox::IAP::init(s);
#endif
}

void USdkboxIAPFunctions::SdkboxIapShutdown()
{
#if PLATFORM_IOS || PLATFORM_ANDROID
    if (0 == _initCount && _listener && _listener->IsValidLowLevel())
    {
        _listener->ConditionalBeginDestroy();
        _listener = nullptr;
    }
#endif
}

void USdkboxIAPFunctions::SdkboxIapPurchase(FString product) 
{
#if PLATFORM_IOS //|| PLATFORM_ANDROID    
    sdkbox::IAP::purchase((const char*)TCHAR_TO_ANSI(*product));
#endif
}

void USdkboxIAPFunctions::SdkboxIapRefresh() 
{
#if PLATFORM_IOS //|| PLATFORM_ANDROID        
    sdkbox::IAP::refresh();
#endif
}

void USdkboxIAPFunctions::SdkboxIapRestore() 
{
#if PLATFORM_IOS //|| PLATFORM_ANDROID        
    sdkbox::IAP::restore();
#endif
}