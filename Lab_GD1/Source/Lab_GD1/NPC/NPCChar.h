// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

 
#include "GameFramework/Character.h"
#include "NPCChar.generated.h"

UCLASS()
class LAB_GD1_API ANPCChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPCChar();
	UPROPERTY(EditAnyWhere, Category = "AIBehavior")
		class UBehaviorTree *NPCBT;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	 
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override; 


};
