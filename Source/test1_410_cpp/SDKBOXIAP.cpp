// Fill out your copyright notice in the Description page of Project Settings.

#include "test1_410_cpp.h"
#include "SDKBOXIAP.h"

#if SDKBOX_IAP_ENABLED
#include "PluginIAP.h"
#endif

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

// Sets default values for this component's properties
USDKBOXIAP::USDKBOXIAP()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
#if SDKBOX_IAP_ENABLED
    sdkbox::IAP::init();
    printf("initialized SDKBOX IAP\n\n\n");
#endif
}


// Called when the game starts
void USDKBOXIAP::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USDKBOXIAP::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

