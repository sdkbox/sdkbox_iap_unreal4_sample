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

class USdkboxIAPListener;

UCLASS(ClassGroup=SDKBOX, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))
class USdkboxIAPComponent
    : public UActorComponent
{
	GENERATED_BODY()
	
public:
    
    typedef TArray<TSubclassOf<USdkboxIAPProduct>> tProductArray;
        
    USdkboxIAPComponent(const FObjectInitializer& ObjectInitializer);
    
    void OnRegister() override;
    void OnUnregister() override;
    
    DECLARE_MULTICAST_DELEGATE_OneParam(FBoolDelegate, bool);
   	DECLARE_MULTICAST_DELEGATE_OneParam(FProductDelegate, const USdkboxIAPProduct*);
    DECLARE_MULTICAST_DELEGATE_TwoParams(FProductStringDelegate, const USdkboxIAPProduct*, const FString*);
    DECLARE_MULTICAST_DELEGATE_OneParam(FProductArrayDelegate, const tProductArray*);
   	DECLARE_MULTICAST_DELEGATE_OneParam(FStringDelegate, const FString*); 
    DECLARE_MULTICAST_DELEGATE_TwoParams(FBoolStringDelegate, bool, const FString*);
     
    static FBoolDelegate          OnInitializedDelegate;
    static FProductDelegate       OnSuccessDelegate;
    static FProductStringDelegate OnFailureDelegate;
    static FProductDelegate       OnCanceledDelegate;
    static FProductDelegate       OnRestoredDelegate;
    static FProductArrayDelegate  OnProductRequestSuccessDelegate;
    static FProductStringDelegate OnProductRequestFailureDelegate;
    static FBoolStringDelegate    OnRestoreCompleteDelegate;
    
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBoolDynDelegate, bool, Status);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProductDynDelegate, const USdkboxIAPProduct*, Product);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FProductStringDynDelegate, const USdkboxIAPProduct*, Product, const FString*, Message);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProductArrayDynDelegate, const tProductArray*, Products);
   	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStringDynDelegate, const FString*, Message); 
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBoolStringDynDelegate, bool, Status, const FString*, Message);
    
    UPROPERTY(BlueprintAssignable)
    FBoolDynDelegate OnInitialized;
    
    UPROPERTY(BlueprintAssignable)
    FProductDynDelegate OnSuccess;
    
    UPROPERTY(BlueprintAssignable)
    FProductStringDynDelegate OnFailure;
    
    UPROPERTY(BlueprintAssignable)
    FProductDynDelegate OnCanceled;
    
    UPROPERTY(BlueprintAssignable)
    FProductDynDelegate OnRestored;
    
    UPROPERTY(BlueprintAssignable)
    FProductArrayDynDelegate OnProductRequestSuccess;
    
    UPROPERTY(BlueprintAssignable)
    FProductStringDynDelegate OnProductRequestFailure;
    
    UPROPERTY(BlueprintAssignable)
    FBoolDynDelegate OnRestoreComplete;
    
protected:

	void OnInitializedDelegate_Handler(bool result) { OnInitialized.Broadcast(result); }
    void OnSuccessDelegate_Handler(const USdkboxIAPProduct* product) { OnSuccess.Broadcast(product); }
    void OnFailureDelegate_Handler(const USdkboxIAPProduct* product, FString* message) { OnFailure.Broadcast(product, message); }
    void OnCanceledDelegate_Handler(const USdkboxIAPProduct* product) { OnCanceled.Broadcast(product); }
    void OnRestoredDelegate_Handler(const USdkboxIAPProduct* product) { OnRestored.Broadcast(product); }
    void OnProductRequestSuccessDelegate_Handler(const tProductArray* productArray) { OnProductRequestSuccess.Broadcast(productArray); }
    void OnProductRequestFailureDelegate_Handler(const FString* message) { OnProductRequestFailure.Broadcast(message); }
    void OnRestoreCompleteDelegate_Handler(bool message) { OnRestoreComplete.Broadcast(message); }
};
