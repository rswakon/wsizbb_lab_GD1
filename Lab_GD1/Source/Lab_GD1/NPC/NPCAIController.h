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

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName TargetEnemyKeyName;
	
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName ShouldWanderKeyName;
	
	UPROPERTY(transient)
		class UBlackboardComponent *BBComp;

	UPROPERTY(transient)
		class UBehaviorTreeComponent *BTComp;

protected:
	virtual void OnPossess(APawn* InPawn) override;

public:
	void SetTargetEnemy(APawn* NewTarget);
	void SetShouldWander(bool ShouldWander);
	class AActor* GetTargetEnemy();
	/** Returns BehaviorComp subobject **/
	FORCEINLINE class UBehaviorTreeComponent* GetBehaviorComp() const { return BTComp; }

	  
	FORCEINLINE class UBlackboardComponent* GetBlackboardComp() const { return BBComp; }
};
