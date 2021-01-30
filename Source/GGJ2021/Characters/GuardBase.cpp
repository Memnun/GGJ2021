// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardBase.h"

// Sets default values
AGuardBase::AGuardBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGuardBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGuardBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGuardBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGuardBase::AddAlertSource(AActor* Source)
{
	AlertSources.AddUnique(Source);
}

void AGuardBase::RemoveAlertSource(AActor* Source)
{
	if (AlertSources.Contains(Source))
		AlertSources.Remove(Source);
}

