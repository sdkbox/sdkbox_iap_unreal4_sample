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

#include "SdkboxIAPProduct.generated.h"

namespace sdkbox
{
    struct Product;
}

UCLASS(ClassGroup=SDKBOX, meta=(BlueprintSpawnableComponent))
class USdkboxIAPProduct
    : public UObject
{
	GENERATED_BODY()
    
public:
  
	USdkboxIAPProduct(const FObjectInitializer& ObjectInitializer);
        
    static USdkboxIAPProduct* ProductFromSdkboxProduct(const sdkbox::Product& product);
    
    // The name of the product
    UPROPERTY(BlueprintReadOnly, Category=General, meta=(DisplayName="Name"))
    FString Name;

    // The product id of an In App Purchase
    UPROPERTY(BlueprintReadOnly, Category=General, meta=(DisplayName="Id"))
    FString Id;

    // Type of iap item true if consumable
    UPROPERTY(BlueprintReadOnly, Category=General, meta=(DisplayName="Consumable"))
    bool Consumable;

    // The title of the IAP item
    UPROPERTY(BlueprintReadOnly, Category=General, meta=(DisplayName="Title"))
    FString Title;

    // The description of the IAP item
    UPROPERTY(BlueprintReadOnly, Category=General, meta=(DisplayName="Description"))
    FString Description;

    // Price value in float
    UPROPERTY(BlueprintReadOnly, Category=General, meta=(DisplayName="PriceValue"))
    float PriceValue;

    // Localized price
    UPROPERTY(BlueprintReadOnly, Category=General, meta=(DisplayName="Price"))
    FString Price;
    
    // price currency code
    UPROPERTY(BlueprintReadOnly, Category=General, meta=(DisplayName="CurrencyCode"))
    FString CurrencyCode;

    // cyphered payload
    UPROPERTY(BlueprintReadOnly, Category=General, meta=(DisplayName="ReceiptCipheredPayload"))
    FString ReceiptCipheredPayload;

    // receipt info. will be empty string for iOS
    UPROPERTY(BlueprintReadOnly, Category=General, meta=(DisplayName="Receipt"))
    FString Receipt;
};