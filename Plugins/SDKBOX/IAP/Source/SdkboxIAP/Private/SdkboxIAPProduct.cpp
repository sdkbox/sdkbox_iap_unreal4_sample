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
#include "SdkboxIAPProduct.h"
#include "PluginIAP.h"

USdkboxIAPProduct::USdkboxIAPProduct(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

USdkboxIAPProduct* USdkboxIAPProduct::ProductFromSdkboxProduct(const sdkbox::Product& product)
{
    auto p = NewObject<USdkboxIAPProduct>(USdkboxIAPProduct::StaticClass());
    p->Name         = product.name.c_str();
    p->Id           = product.id.c_str();
    p->Consumable   = product.type == sdkbox::CONSUMABLE ? true : false;
    p->Title        = product.title.c_str();
    p->Description  = product.description.c_str();
    p->PriceValue   = product.priceValue;
    p->Price        = product.price.c_str();
    p->CurrencyCode = product.currencyCode.c_str();
    p->ReceiptCipheredPayload = product.receiptCipheredPayload.c_str();
    p->Receipt      = product.receipt.c_str();
    return p;
}