// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GuardBase.generated.h"

UCLASS()
class GGJ2021_API AGuardBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGuardBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/***********************************************/
	/*****             DETECTION              ******/
	/***********************************************/

	/*Notifies the guard that it should know where the player is. Includes an alert source, for tracking if multiple things are alerting the guard to the player's presence */
	UFUNCTION(BlueprintCallable, Category = "Detection")
		void AddAlertSource(AActor* Source);
	
	/*Notifies the guard that a given source no longer detects the player for the guard*/
	UFUNCTION(BlueprintCallable, Category = "Detection")
		void RemoveAlertSource(AActor* Source);

	UFUNCTION(BlueprintPure, Category = "Detection")
		bool HasSeenPlayer() { return AlertSources.Num() > 0; }

private:
	//Actors notifying this guard that it knows where the player is
	TArray<AActor*> AlertSources;

};
