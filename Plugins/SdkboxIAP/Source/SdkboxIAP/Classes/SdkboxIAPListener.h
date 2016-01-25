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

#pragma once

#include "PluginIAP.h"
#include "SdkboxIAPListener.generated.h"

// UE4 HeaderTool fails to parse the namespace properly, so...
struct UListener : public sdkbox::IAPListener {};

UCLASS(NotBlueprintable)
class USdkboxIAPListener 
    : public UObject
    , public UListener
{
	GENERATED_BODY()
    
public:

    /**
    * Called when IAP initialized
    */
    void onInitialized(bool success);

    /**
    * Called when an IAP processed successfully
    */
    void onSuccess(const sdkbox::Product& p);

    /**
    * Called when an IAP fails
    */
    void onFailure(const sdkbox::Product& p, const std::string& msg);

    /**
    * Called when user canceled the IAP
    */
    void onCanceled(const sdkbox::Product& p);

    /**
    * Called when server returns the IAP items user already purchased
    * @note this callback will be called multiple times if there are multiple IAP
    */
    void onRestored(const sdkbox::Product& p);

    /**
    * Called the product request is successful, usually developers use product request to update the latest info(title, price) from IAP
    */
    void onProductRequestSuccess(const std::vector<sdkbox::Product>& products);

    /**
    * Called when the product request fails
    */
    void onProductRequestFailure(const std::string& msg);
    
    /**
        * Called when the restore completed
        */
    void onRestoreComplete(bool ok, const std::string& msg);  
};