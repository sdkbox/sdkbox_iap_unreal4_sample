// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SdkboxIAPProduct.h"
#include "PurchaseHandler.generated.h"

UCLASS(ClassGroup=TEST, meta=(BlueprintSpawnableComponent))
class TEST1_410_CPP_API UPurchaseHandlerComponent : public UActorComponent
{
    GENERATED_BODY()

public:

    UPurchaseHandlerComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, Category = "TEST")
    void handleInitialize(bool status);
        
    UFUNCTION(BlueprintCallable, Category = "TEST")
    void handleProductRequest(const TArray<USdkboxIAPProduct*>& products);
    
    UFUNCTION(BlueprintCallable, Category = "TEST")
    void handlePurchase(const USdkboxIAPProduct* product);
};
