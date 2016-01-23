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

#include "SdkboxIAPFunctions.h"
#include "SdkboxIAPComponent.generated.h"

UCLASS(ClassGroup=SDKBOX, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))
class USdkboxIAPComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
    
    void OnRegister() override;
    void OnUnregister() override;
    
    DECLARE_MULTICAST_DELEGATE_OneParam(FBoolDelegate, bool);
   	DECLARE_MULTICAST_DELEGATE_OneParam(FProductDelegate, const USdkboxIAPProduct&);
    DECLARE_MULTICAST_DELEGATE_TwoParam(FProductStringDelegate, const USdkboxIAPProduct&, const FString&);   
       
    static FBoolDelegate OnInitializedDelegate;
    
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBoolDynDelegate, bool, Status);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProductDynDelegate, const USdkboxIAPProduct&, Product);
    
    UPROPERTY(BlueprintAssignable)
    FBoolDynDelegate OnInitialized;
    
    UPROPERTY(BlueprintAssignable)
    FProductDynDelegate OnSuccess;
    
protected:

	void OnInitializedDelegate_Handler(bool result) { OnInitialized.Broadcast(result); }
    void OnSuccessDelegate_Handler(const USdkboxIAPProduct& product) { OnSuccess.Broadcast(product); }
};
