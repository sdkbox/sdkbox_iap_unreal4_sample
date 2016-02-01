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

USdkboxIAPListener* USdkboxIAPFunctions::_listener = nullptr;

void USdkboxIAPFunctions::SdkboxIapInitialize(FString jsonstring)
{
#if PLATFORM_IOS || PLATFORM_ANDROID
    if (!_listener)
    {
        _listener = NewObject<USdkboxIAPListener>(USdkboxIAPListener::StaticClass());
        sdkbox::IAP::setListener(_listener);
    }
    
    sdkbox::IAP::init(TCHAR_TO_ANSI(*jsonstring));
#endif
}

void USdkboxIAPFunctions::SdkboxIapShutdown()
{
#if PLATFORM_IOS || PLATFORM_ANDROID
    if (_listener && _listener->IsValidLowLevel())
    {
        _listener->ConditionalBeginDestroy();
        _listener = nullptr;
    }
#endif
}

void USdkboxIAPFunctions::SdkboxIapPurchase(FString product) 
{
#if PLATFORM_IOS || PLATFORM_ANDROID 
    std::string s(TCHAR_TO_ANSI(*product)); 
    sdkbox::IAP::purchase(s);
#endif
}

void USdkboxIAPFunctions::SdkboxIapRefresh() 
{
#if PLATFORM_IOS || PLATFORM_ANDROID        
    sdkbox::IAP::refresh();
#endif
}

void USdkboxIAPFunctions::SdkboxIapRestore() 
{
#if PLATFORM_IOS || PLATFORM_ANDROID        
    sdkbox::IAP::restore();
#endif
}

FString USdkboxIAPFunctions::SdkboxIapJsonStringFromProductDescriptions(const TArray<FSdkboxIAPProductDescription>& Descriptions)
{
#if PLATFORM_IOS || PLATFORM_ANDROID            
    TSharedPtr<FJsonObject> jo    =  MakeShareable(new FJsonObject);
    TSharedPtr<FJsonObject> ios[] = {MakeShareable(new FJsonObject), MakeShareable(new FJsonObject), MakeShareable(new FJsonObject)};
    TSharedPtr<FJsonObject> drd[] = {MakeShareable(new FJsonObject), MakeShareable(new FJsonObject), MakeShareable(new FJsonObject)};
    
    jo->SetObjectField("ios", ios[0]);
    ios[0]->SetObjectField("iap", ios[1]);
    ios[1]->SetObjectField("items", ios[2]);
    
    jo->SetObjectField("android", drd[0]);
    drd[0]->SetObjectField("iap", drd[1]);
    drd[1]->SetObjectField("items", drd[2]);
 
    for (auto d : Descriptions)
    {
        TSharedPtr<FJsonObject> item = MakeShareable(new FJsonObject);
        item->SetStringField("type", d.Consumable ? "consumable" : "non_consumable");
        item->SetStringField("id", d.Id);
        
        switch (d.Affinity)
        {
            case EProductAffinityEnum::PAE_IOS:
                ios[2]->SetObjectField(d.Name, item);
                break;
            case EProductAffinityEnum::PAE_ANDROID:
                drd[2]->SetObjectField(d.Name, item);
                break;
            case EProductAffinityEnum::PAE_ALL:
            default:
                ios[2]->SetObjectField(d.Name, item);
                drd[2]->SetObjectField(d.Name, item);
                break;
        }
    }
    
    FString OutputString;
    TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
    FJsonSerializer::Serialize(jo.ToSharedRef(), Writer);
    
    return OutputString;
#else
    return "";
#endif
}

void USdkboxIAPFunctions::SdkboxIapEnableUserSideVerification(bool enabled)
{
#if PLATFORM_IOS || PLATFORM_ANDROID        
    sdkbox::IAP::enableUserSideVerification(enabled);
#endif    
}
