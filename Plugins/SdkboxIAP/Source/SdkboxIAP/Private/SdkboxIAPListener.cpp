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
#include "SdkboxIAPListener.h"
#include "SdkboxIAPProduct.h"

/**
* Called when IAP initialized
*/
void USdkboxIAPListener::onInitialized(bool success)
{
    USdkboxIAPComponent::OnInitializedDelegate.Broadcast(success);
}

/**
* Called when an IAP processed successfully
*/
void USdkboxIAPListener::onSuccess(const sdkbox::Product& p)
{
    auto product = USdkboxIAPProduct::ProductFromSdkboxProduct(p);
    USdkboxIAPComponent::OnSuccessDelegate.Broadcast(product);
    product->ConditionalBeginDestroy();
}

/**
* Called when an IAP fails
*/
void USdkboxIAPListener::onFailure(const sdkbox::Product& p, const std::string& msg)
{
    auto product = USdkboxIAPProduct::ProductFromSdkboxProduct(p);
    USdkboxIAPComponent::OnFailureDelegate.Broadcast(product);
    product->ConditionalBeginDestroy();    
}

/**
* Called when user canceled the IAP
*/
void USdkboxIAPListener::onCanceled(const sdkbox::Product& p)
{
    auto product = USdkboxIAPProduct::ProductFromSdkboxProduct(p);
    USdkboxIAPComponent::OnCanceledDelegate.Broadcast(product);
    product->ConditionalBeginDestroy();
}

/**
* Called when server returns the IAP items user already purchased
* @note this callback will be called multiple times if there are multiple IAP
*/
void USdkboxIAPListener::onRestored(const sdkbox::Product& p)
{
    auto product = USdkboxIAPProduct::ProductFromSdkboxProduct(p);
    USdkboxIAPComponent::OnRestoredDelegate.Broadcast(product);
    product->ConditionalBeginDestroy();
}

/**
* Called the product request is successful, usually developers use product request to update the latest info(title, price) from IAP
*/
void USdkboxIAPListener::onProductRequestSuccess(const std::vector<sdkbox::Product>& products)
{
    TArray<TSubclassOf<USdkboxIAPProduct*>> productsArray;
    for (auto p : products)
    {
        productsArray.Add(USdkboxIAPProduct::ProductFromSdkboxProduct(p));
    }
    
    USdkboxIAPComponent::OnProductRequesSuccessDelegate.Broadcast(productsArray);

    for (auto i : productsArray)
    {
        i->ConditionalBeginDestroy();
    }
}

/**
* Called when the product request fails
*/
void USdkboxIAPListener::onProductRequestFailure(const std::string& msg)
{
    USdkboxIAPComponent::OnProductRequesFailureDelegate.Broadcast(msg.c_str());
}

/**
 * Called when the restore completed
 */
void USdkboxIAPListener::onRestoreComplete(bool ok, const std::string& msg)
{
    USdkboxIAPComponent::OnRestoreCompleteDelegate.Broadcast(ok, msg.c_str());  
}
