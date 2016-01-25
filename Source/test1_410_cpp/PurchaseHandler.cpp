// Fill out your copyright notice in the Description page of Project Settings.

#include "test1_410_cpp.h"
#include "PurchaseHandler.h"

UPurchaseHandlerComponent::UPurchaseHandlerComponent(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

void UPurchaseHandlerComponent::handleInitialize(bool status)
{
    FString text = FString::Printf(TEXT("Initialized successful = %s"), status ? TEXT("true") : TEXT("false"));
    
    FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(text));    
}
        
void UPurchaseHandlerComponent::handleProductRequest(const TArray<USdkboxIAPProduct*>& products)
{
    FString productsDescription;
    
    for (auto p : products)
    {
        productsDescription += FString::Printf(TEXT("%s $%0.2f\n"), *p->Name, p->PriceValue);
    }
    
    FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(productsDescription));    
}
    
void UPurchaseHandlerComponent::handlePurchase(const USdkboxIAPProduct* product)
{
    FString text = FString::Printf(TEXT("Purchased product %s for $%0.2f"), *product->Name, product->PriceValue);
    
    FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(text));
}
