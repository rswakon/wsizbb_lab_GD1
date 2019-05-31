// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h" 
#include "AIController.h"
#include "NPCAIController.generated.h"

/**
 * 
 */
UCLASS()
class LAB_GD1_API ANPCAIController : public AAIController
{
	GENERATED_BODY()
public:
	ANPCAIController();

	UPROPERTY(transient)
		class UBlackboardComponent *BBComp;

	UPROPERTY(transient)
		class UBehaviorTreeComponent *BTComp;

protected:
	virtual void OnPossess(APawn* InPawn) override;



	uint8 NPCKeyID;
	
};
