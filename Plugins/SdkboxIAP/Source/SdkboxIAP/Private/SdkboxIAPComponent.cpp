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

USdkboxIAPComponent::FBoolDelegate          USdkboxIAPComponent::OnInitializedDelegate;
USdkboxIAPComponent::FProductDelegate       USdkboxIAPComponent::OnSuccessDelegate;
USdkboxIAPComponent::FProductStringDelegate USdkboxIAPComponent::OnFailureDelegate;
USdkboxIAPComponent::FProductDelegate       USdkboxIAPComponent::OnCanceledDelegate;
USdkboxIAPComponent::FProductDelegate       USdkboxIAPComponent::OnRestoredDelegate;
USdkboxIAPComponent::FProductArrayDelegate  USdkboxIAPComponent::OnProductRequestSuccessDelegate;
USdkboxIAPComponent::FProductStringDelegate USdkboxIAPComponent::OnProductRequestFailureDelegate;
USdkboxIAPComponent::FBoolStringDelegate    USdkboxIAPComponent::OnRestoreCompleteDelegate;

USdkboxIAPComponent::USdkboxIAPComponent(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

void USdkboxIAPComponent::OnRegister()
{
	Super::OnRegister();
    
	USdkboxIAPComponent::OnInitializedDelegate.AddUObject(this, &USdkboxIAPComponent::OnInitializedDelegate_Handler);
    USdkboxIAPComponent::OnSuccessDelegate.AddUObject(this, &USdkboxIAPComponent::OnSuccessDelegate_Handler);
    USdkboxIAPComponent::OnFailureDelegate.AddUObject(this, &USdkboxIAPComponent::OnFailureDelegate_Handler);
    USdkboxIAPComponent::OnCanceledDelegate.AddUObject(this, &USdkboxIAPComponent::OnCanceledDelegate_Handler);
    USdkboxIAPComponent::OnRestoredDelegate.AddUObject(this, &USdkboxIAPComponent::OnRestoredDelegate_Handler);
    USdkboxIAPComponent::OnProductRequestSuccessDelegate.AddUObject(this, &USdkboxIAPComponent::OnProductRequestSuccessDelegate_Handler);
    USdkboxIAPComponent::OnProductRequestFailureDelegate.AddUObject(this, &USdkboxIAPComponent::OnProductRequestFailureDelegate_Handler);
    USdkboxIAPComponent::OnRestoreCompleteDelegate.AddUObject(this, &USdkboxIAPComponent::OnRestoreCompleteDelegate_Handler);
}

void USdkboxIAPComponent::OnUnregister()
{
	Super::OnUnregister();
  
	USdkboxIAPComponent::OnInitializedDelegate.RemoveAll(this);
    USdkboxIAPComponent::OnSuccessDelegate.RemoveAll(this);
    USdkboxIAPComponent::OnFailureDelegate.RemoveAll(this);
    USdkboxIAPComponent::OnCanceledDelegate.RemoveAll(this);
    USdkboxIAPComponent::OnRestoredDelegate.RemoveAll(this);
    USdkboxIAPComponent::OnProductRequestSuccessDelegate.RemoveAll(this);
    USdkboxIAPComponent::OnProductRequestFailureDelegate.RemoveAll(this);
    USdkboxIAPComponent::OnRestoreCompleteDelegate.RemoveAll(this);
}

